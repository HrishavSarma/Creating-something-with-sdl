#include "SDL.h"

int main(int argc, char* argv[])
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 55, 210, 230, 0.8);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(1000);

	return 0;
}