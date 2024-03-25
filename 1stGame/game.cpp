#include "game.h"
#include "textureManager.h"
#include "GameObject.h"
#include "Map.h"
using namespace std;

GameObject* player;
GameObject* enemy;
Map* map;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;	
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystem initialized..." << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Window Created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);// -1 iin index to let sdl choose the best rendering driver and 0 for defualt behaviout of vsync and hardware acceleration
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 230, 235, 180, 255);
			cout << "Renderer Created" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 200, 0);
	map = new Map();

	/*playerTex = TextureManager::LoadTexture("assets/player.png", renderer);
	EnemyTex = TextureManager::LoadTexture("assets/enemy.png", renderer);*/

	/* SDL_Surface* tmpsurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface); */

}

void Game::handlevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	enemy->update();
	player->update();

}

void Game::render()
{
	//this is where we would stuff to render
	SDL_RenderClear(renderer);
	map->DrawMap();
	enemy->render();
	player->render();
	SDL_RenderPresent(renderer);
	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}
