#include"GameObject.h"
#include"textureManager.h"

GameObject::GameObject(const char* Texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(Texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::update()
{

	xpos++;
	ypos++;


	SrcRect.h = 321;
	SrcRect.w = 191;
	SrcRect.x = 0;
	SrcRect.y = 0;

	DestRect.x = xpos;
	DestRect.y = ypos;
	DestRect.h = 51;
	DestRect.w = 30;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &SrcRect, &DestRect);
}