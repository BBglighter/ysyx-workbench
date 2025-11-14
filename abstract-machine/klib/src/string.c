#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0,i = 0;
  while(s[i] != '\0'){
    i++; len++;
  }
  return len; 
}

char *strcpy(char *dst, const char *src) {
  char *p = dst;
  while(*src != '\0'){
    *p++ = *src++;
  }
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for(i = 0;i < n && src[i] != '\0';i ++)
    dst[i] = src[i];
  for(; i < n;i ++)
    dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *p = dst;
  while(*dst != '\0')
    dst++;
  while(*src != '\0')
    *dst++ = *src++;
  return p;
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2 && *s1 && *s2){
    s1++; s2++;
  }
  if(*s1 == *s2)
    return 0;
  else if(*s1 > *s2)
    return 1;
  else
    return -1;
}

int strncmp(const char *s1, const char *s2, size_t n) { 
  size_t i = 0;
  while(*s1 == *s2 && *s1 && *s2 && i < n){
    s1++; s2++; i++;
  }
  if(*s1 == *s2)
    return 0;
  else if(*s1 > *s2)
    return 1;
  else
    return -1;
}

void *memset(void *s, int c, size_t n) {
  uint8_t *byte_p = (uint8_t*)s;
  for(size_t i = 0;i < n;i ++)
    byte_p[i] = (uint8_t)c;
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  uint8_t *d = dst;
  const uint8_t *s = src;
  if(s == d || n == 0)
    return dst;
  if(d < s){
    for(size_t i = 0;i < n;i ++)
      d[i] = s[i];
  }else{
    for(size_t i = n-1;i >= 0;i --)
      d[i] = s[i];
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  uint8_t *d = out;
  const uint8_t *s = in;
  if(s == d || n == 0)
    return out;
  for(size_t i = 0;i < n;i ++)
    d[i] = s[i];
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {  
  size_t i = 0;
  const uint8_t *us1 = s1,*us2 = s2;
  if(n == 0) return 0;
  while(*us1 == *us2 && i < n-1){
    us1++; us2++; i++;
  }
  if(*us1 == *us2)
    return 0;
  else
    return (int)*us1 - (int)*us2;
}

#endif
