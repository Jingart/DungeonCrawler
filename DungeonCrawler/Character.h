#pragma once
#include <SDL.h>
#include "Graphics.h"

class Character
{
public:
	Character(void);
	~Character(void);

	void SetMapPosition(int x, int y);

	void Render();

private:
	int mMapX;
	int mMapY;

	int mPosX;
	int mPosY;

	SDL_Rect mCharacter;
};

