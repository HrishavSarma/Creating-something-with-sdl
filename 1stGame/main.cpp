#include"game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 30;
	const int framedelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	
	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 658, 368, false);
	
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handlevents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (framedelay > frameTime)
		{
			SDL_Delay(framedelay - frameTime);
		}

	}
	game->clean();
	return 0;
}