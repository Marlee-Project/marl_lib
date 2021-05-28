#include "marl_lib.h"

MARL_Window *MARL_CreateWindow() {
  if(SDL_WasInit(SDL_INIT_VIDEO)) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      printf("[Marlee]: Error while initializing SDL subsystem: %s\n", SDL_GetError());
      return NULL;
    }
  }


  MARL_Window *window = malloc(sizeof(MARL_Window));

  window->sdl_window = SDL_CreateWindow(">_Marleematic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600,900, SDL_WINDOW_RESIZABLE);

  SDL_MaximizeWindow(window->sdl_window);

  window->sdl_renderer = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);
  return window;
}
