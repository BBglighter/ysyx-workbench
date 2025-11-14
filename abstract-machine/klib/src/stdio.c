#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  char * str;
  int d = 0,s = 0,i = 0;
  int num = 0;
  while(fmt[s] != '\0'){
    if(fmt[s] == '%'){
      s++;
      switch(fmt[s]){
      case 'd':
        num = va_arg(ap,int);
        if(num == 0) {
          out[d++] = '0';
          break;
        }else if(num < 0){
          out[d++] = '-';
            num = -num;
        }
        int stack[100] = {0}; 
        for(i = 0;num != 0;i ++){            
          stack[i] = num % 10;
          num = num / 10;
        }
        i--;
        for(;i >= 0;i --){
          out[d++] = stack[i] + '0';
        }
        break;        
      case 's':
        i = 0;
        str = va_arg(ap,char *);
        while(str[i] != '\0'){
          out[d++] = str[i++];
        }
        break;
      }
      s++;
    }else
      out[d++] = fmt[s++];
  }
  out[d] = '\0';
  va_end(ap);
  return d;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
