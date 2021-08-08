#include <marl_lib.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  MARL_EnableTerminalEvents();

  MARL_String *s = MARL_StringCreate(">_ I am Marlee");
  MARL_StringAppend(s, "matic!");
  MARL_Window *window = MARL_WindowCreate(s->string);

  TTF_Init();
  SDL_Color color = {0, 0, 0, 255};
  TTF_Font *font = TTF_OpenFont("./internal/files/Roboto-Regular.ttf", 18);
  SDL_Surface *textSurface =
      TTF_RenderText_Blended(font, "Marlee is the best!", color);
  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(window->sdl_renderer, textSurface);
  MARL_Rect textRect;
  textRect.x = textRect.y = 0;
  SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
  SDL_RenderCopy(window->sdl_renderer, textTexture, NULL, &textRect);

  SDL_RenderPresent(window->sdl_renderer);

  char quit = 1;
  SDL_Event event;
  while (quit) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = 0;
        break;
      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          SDL_RenderClear(window->sdl_renderer);
          SDL_RenderCopy(window->sdl_renderer, textTexture, NULL, &textRect);
          SDL_RenderPresent(window->sdl_renderer);
        }
        break;
      case SDL_USEREVENT:
        if (event.type == MARL_TERMINALEVENT) {
          // Get data with event.user.data1
        }
        break;
      }
    }
  }

  printf("[Marlee] Stopping...\n");
  SDL_FreeSurface(textSurface);
  MARL_WindowDestroy(window);
  SDL_Quit();
  return 0;
}
