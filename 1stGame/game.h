#pragma once
#ifndef game_hpp
#define game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include<iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handlevents();
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	bool running() { return isRunning; };
private:
	int cnt=0;
	bool isRunning;
	SDL_Window* window;


};


#endif // !game_hpp
