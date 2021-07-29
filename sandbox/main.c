#include <marl_lib.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  MARL_String *s = MARL_StringCreate(">_ I am Marlee");
  MARL_StringAppend(s, "matic!");
  MARL_Window *window = MARL_WindowCreate(s->string);
	SDL_RenderPresent(window->sdl_renderer);

	char quit = 1;
	SDL_Event event;
	while (quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 0;
			}
		}
	}

	printf("[Marlee] Stopping...\n");
  MARL_WindowDestroy(window);
  SDL_Quit();

  return 0;
}
