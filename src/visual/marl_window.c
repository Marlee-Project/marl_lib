#include "marl_lib.h"

MARL_Window *MARL_WindowCreate(char *title) {
  if (SDL_WasInit(SDL_INIT_VIDEO)) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      printf("[Marlee]: Error while initializing SDL subsystem: %s\n",
             SDL_GetError());
      return NULL;
    }
  }
  MARL_Window *window = malloc(sizeof(MARL_Window));
  window->sdl_window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       1600, 900, SDL_WINDOW_RESIZABLE);
  SDL_MaximizeWindow(window->sdl_window);

  window->sdl_renderer =
      SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(window->sdl_renderer, 0, 255, 255, 255);
  SDL_RenderClear(window->sdl_renderer);

  return window;
}

void MARL_WindowDestroy(MARL_Window *window) {
  SDL_DestroyWindow(window->sdl_window);
  SDL_DestroyRenderer(window->sdl_renderer);
}
