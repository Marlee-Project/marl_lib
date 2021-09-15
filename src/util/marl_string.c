#include <stdlib.h>
#include <stdio.h>
#include "marl_string.h"


MARL_String *MARL_StringCreate(char *str) {
  MARL_String *mstr = malloc(sizeof(MARL_String));
    mstr->string = NULL;
    mstr->size = 0;
  MARL_StringAppend(mstr, str);
  return mstr;
}

void MARL_StringAppend(MARL_String *src, const char *str) {
  unsigned long str_size = 0;
  do {} while(*(str + ++str_size) != '\0');

  src->string = realloc(src->string, (src->size + str_size) * sizeof(char));
  if (src->size > 0) {
    src->size--;
  }
  for (size_t i = 0; i <= str_size; i++) {
    src->string[src->size++] = (str[i]);
  }
}
