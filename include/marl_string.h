#include "marl_list.h"

typedef struct MARL_String {
  char *string;
  unsigned int size;
} MARL_String;


MARL_String *MARL_StringCreate(char *str);

void MARL_StringAppend(MARL_String *src, const char *str);
