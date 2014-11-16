#pragma once
#include <SDL.h>

class Graphics
{
public:

	static void InitAll();

	//static const int SCREEN_WIDTH = 640;
	//static const int SCREEN_HEIGHT = 480;
	static const int SCREEN_WIDTH = 400;
	static const int SCREEN_HEIGHT = 400;

	static SDL_Renderer* gRenderer;
	static SDL_Window* gWindow;

};

