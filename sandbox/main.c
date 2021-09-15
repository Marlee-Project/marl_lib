#include <marl_lib.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  MARL_EnableTerminalEvents();

  MARL_String *s = MARL_StringCreate(">_ I am Marlee");
  MARL_StringAppend(s, "matic!");
  MARL_Window *window = MARL_WindowCreate(s->string);

  TTF_Init();
  SDL_Color color = {0, 0, 0, 255};
  TTF_Font *font = TTF_OpenFont("../internal/files/Roboto-Regular.ttf", 18);
    if (!font) {
        printf("Failed to open font: %s\n", TTF_GetError());
        MARL_WindowDestroy(window);
        SDL_Quit();
        return 1;
    }
  SDL_Surface *textSurface =
      TTF_RenderText_Blended(font, "Marlee is the best!", color);
  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(window->sdl_renderer, textSurface);
  MARL_Rect textRect;
  textRect.x = textRect.y = 0;
  SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
  SDL_RenderCopy(window->sdl_renderer, textTexture, NULL, &textRect);

  SDL_RenderPresent(window->sdl_renderer);
  MARL_Widget text = MARL_CreateTextBox("Hello World", font, 100, 100, 200, 30);
       	char quit = 0;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = 1;
        break;
      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          SDL_RenderClear(window->sdl_renderer);
	  MARL_WidgetDraw(window, text);
	  SDL_SetRenderDrawColor(window->sdl_renderer, 0, 127, 127, 0);
          SDL_RenderCopy(window->sdl_renderer, textTexture, NULL, &textRect);
          SDL_RenderPresent(window->sdl_renderer);
        }
        break;
      case SDL_USEREVENT:
        if (event.type == MARL_TERMINALEVENT) {
          if(strcmp(event.user.data1, "exit\n") == 0) {
	  	quit = 1;
	  }
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
