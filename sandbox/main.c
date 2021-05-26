#include <marl_lib.h>

int main(int argc, char* argv[]) {
    SDL_Window *window;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      printf("An Error occurred while initializing SDL2: %s\n", SDL_GetError());
      return 1;
    }

    window = SDL_CreateWindow(">_ marleematic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_RESIZABLE);

    if(window == NULL) {
      printf("An Error occurred while creating window: %s\n", SDL_GetError());
      return 1;
    }

    SDL_MaximizeWindow(window);

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
