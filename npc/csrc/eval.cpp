#include <regex.h>
#include "common.h"

enum {
  TK_NOTYPE = 256, TK_EQ, TK_0_9, TK_BRACKETS_L, TK_BRACKETS_R, TK_HEX, TK_AND, TK_NEQ, TK_DEREF, TK_REG,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"0x[0-9A-Fa-f]+", TK_HEX},// hex
  {"[0-9]+", TK_0_9},   // 0_9
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
  {"\\*", '*'},         //mult    
  {"/", '/'},       //div
  {"-", '-'},           //sub
  {"\\(", TK_BRACKETS_L }, //(
  {"\\)", TK_BRACKETS_R}, //)
  {"\\$\\S+",TK_REG},
  {"&&",TK_AND},
  {"!=",TK_NEQ},
  {"\\*", TK_DEREF},
};

#define NR_REGEX 14

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[10000] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            //i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;
        
        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        if(substr_len >= 32) {
          return false;
        }
        
        if(rules[i].token_type != TK_NOTYPE){
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          tokens[nr_token].type = rules[i].token_type;
          nr_token++;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  for(int i = 0;i < nr_token;i ++){
    if(tokens[i].type == '*' && (i == 0 || (tokens[i-1].type == '+') || (tokens[i-1].type == '-')
                                        || (tokens[i-1].type == '*') || (tokens[i-1].type == '/')
                                        || (tokens[i-1].type == TK_EQ) || (tokens[i-1].type == TK_NEQ)))
      tokens[i].type = TK_DEREF;
  }
  return true;
}

bool check_parentheses(int p, int q){
  if(tokens[p].type != TK_BRACKETS_L || tokens[q].type != TK_BRACKETS_R)
    return false;
  int stack = 1;
  while(p <= q){
    if(tokens[p++].type == TK_BRACKETS_L)
      break;
  }
  while(p <= q){
      if(stack == 0){
        if(tokens[p].type == TK_BRACKETS_L || tokens[p].type == TK_BRACKETS_R)
          return false;        
      }else{
        if(tokens[p].type == TK_BRACKETS_L)
          stack++;
        else if(tokens[p].type == TK_BRACKETS_R)
          stack--;
      }
    p++;
  }
  return stack == 0;
}

uint32_t isa_reg_str2val(char* str);
extern "C" int pmem_read(uint32_t addr);
uint32_t eval(int p, int q){
  if(p > q){
    return 0;
  }
  else if(p == q){
    if(tokens[p].type == TK_REG){
      uint32_t val = isa_reg_str2val(tokens[p].str);
      return val;
    }else
      return (uint32_t)strtol(tokens[p].str,NULL,0);
  }
  else if(check_parentheses(p,q) == true){
    return eval(p+1,q-1); 
  }
  else{
    int op = 0;
    int op_pos = -1;
    int stack = 0;  //memo the num of ()
    for(int i = p;i < q; i++){
      if(tokens[i].type == TK_BRACKETS_L) stack++;
      if(tokens[i].type == TK_BRACKETS_R) stack--;

      if(stack == 0){
        if(tokens[i].type == TK_EQ){
          op = TK_EQ;
          op_pos = i;
          break;
        }else if(tokens[i].type == TK_NEQ){
          op = TK_NEQ;
          op_pos = i;
          break;
        }else if(tokens[i].type == TK_AND){
          op = TK_AND;
          op_pos = i;
        }else if(tokens[i].type == '+' && op != TK_AND){
          op = '+';
          op_pos = i;
        }else if(tokens[i].type == '-' && op != '+' && op != TK_AND){
          op = '-';
          op_pos = i;
        }else if(tokens[i].type == '*' && op != '-' && op != '+' && op != TK_AND){
          op = '*';
          op_pos = i;
        }else if(tokens[i].type == '/' && op != '-' && op != '+' && op != TK_AND){
          op = '/';
          op_pos = i;
        }else if(tokens[i].type == TK_DEREF && op == 0){
          op = TK_DEREF;
          op_pos = i;
        }
      }
    }
    if(op == 0){
      assert(0);
    }
    uint32_t val1 = 0;
    if(op != TK_DEREF){
      val1 = eval(p,op_pos-1);
    }
    uint32_t val2 = eval(op_pos+1,q);
    switch(op){
      case TK_DEREF:{
        uint32_t val = pmem_read(val2);
        return val;
      }
      case TK_EQ: {return val1 == val2;}
      case TK_NEQ: {return val1 != val2;}
      case '+': {return val1 + val2;}
      case '-': {return val1 - val2;}
      case '*': {return val1 * val2;}
      case '/': if(val2 == 0){
        assert(0);
      }
      return (int)val1 / (int)val2;
      default: assert(0);
    }
  }
}

uint32_t expr(char *e, bool *success,char *end) {
  memset(tokens,0,sizeof(Token)*10000);
  // init_regex();

  for(int i=0;e+i < end; i++){
    e[i] = (e[i]==0)?' ':e[i];
  }

  //Log("%s\n",e);

  if (!make_token(e)) {
    *success = false;
    // for(int i = 0;i < NR_REGEX;i ++){
    //   regfree(&re[i]);
    // }  
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  int i = 0;
  while(tokens[i].type != 0){
    i++;
  }
  uint32_t val = eval(0,i-1);
  //Log("val is 0x%x == %d",val,val);
  //
  // for(int i = 0;i < NR_REGEX;i ++){
  //   regfree(&re[i]);
  // }
  return val;
}


