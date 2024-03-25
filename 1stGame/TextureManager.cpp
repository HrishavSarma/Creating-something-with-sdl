#include "textureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* Texture)
{
	SDL_Surface* tempsurface = IMG_Load(Texture);
	SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return Tex;
}