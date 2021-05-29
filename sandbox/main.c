#include <marl_lib.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  MARL_String *s = MARL_StringCreate(">_ I am Marlee");
  MARL_StringAppend(s, "matic!");
  MARL_Window *window = MARL_WindowCreate(s->string);
  SDL_Delay(5000);

  MARL_WindowDestroy(window);
  SDL_Quit();

  return 0;
}
