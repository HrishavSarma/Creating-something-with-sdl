#pragma once
#include"game.h"
class GameObject
{
public:
	GameObject(const char* TextureSheet, int x, int y);
	~GameObject();

	void update();
	void render();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect SrcRect, DestRect;

};