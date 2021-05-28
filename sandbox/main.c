#include <marl_lib.h>

int main(int argc, char* argv[]) {
    MARL_Window *window = MARL_CreateWindow();
    printf("Hello Marleematic\n");

    SDL_Surface *bmpSurface = SDL_LoadBMP("./bin/sample.bmp");
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(window->sdl_renderer, bmpSurface);
    SDL_FreeSurface(bmpSurface);

    SDL_RenderClear(window->sdl_renderer);
    SDL_RenderCopy(window->sdl_renderer, bmpTex, NULL, NULL);
    SDL_RenderPresent(window->sdl_renderer);

    SDL_Event event;
    int running = 1;


    while(running) {
      while(SDL_PollEvent(&event)) {
        switch (event.type) {
          case SDL_QUIT:
            running = 0;
            break;
        }
      }
    }

    SDL_DestroyWindow(window->sdl_window);
    SDL_DestroyRenderer(window->sdl_renderer);
    SDL_Quit();
    return 0;
}
