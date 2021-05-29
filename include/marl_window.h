#ifndef MARL_WINDOW_H
#define MARL_WINDOW_H

typedef struct MARL_Window {
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
} MARL_Window;

MARL_Window *MARL_WindowCreate(char *title);
void MARL_WindowDestroy(MARL_Window *window);


#endif /* end of include guard: MARL_WINDOW_H */
