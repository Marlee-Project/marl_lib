#include "marl_lib.h"

Uint32 MARL_TERMINALEVENT;

int MARL_ManageTerminal() {
  printf("[MARLEE] Console input enabled\n");
  char text[100];
  while (fgets(text, 100, stdin)) {
    SDL_Event event;
    event.type = MARL_TERMINALEVENT;
    event.user.data1 = text;
    SDL_PushEvent(&event);
  }
  return 0;
}

void MARL_EnableTerminalEvents() {
  if (!SDL_WasInit(0)) {
    SDL_Init(0);
    printf("[MARLEE] Init SDL for terminal use\n");
  }

  MARL_TERMINALEVENT = SDL_RegisterEvents(1);
  if (MARL_TERMINALEVENT == ((Uint32)-1)) {
    printf("[MARLEE] Failed to initialize terminal event: %s\n",
           SDL_GetError());
    return;
  }

  SDL_Thread *terminalThread = SDL_CreateThread(
      MARL_ManageTerminal, "MARL-TerminalThread", (void *)NULL);

  if (!terminalThread) {
    printf("[MARLEE] Failed to create terminal Thread: %s\n", SDL_GetError());
  }
}
