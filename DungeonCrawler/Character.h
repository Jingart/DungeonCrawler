#pragma once
#include <SDL.h>
#include "Graphics.h"
#include <vector>

using namespace std;

class Character
{
public:
	Character(void);
	~Character(void);

	void SetMapPosition(int x, int y);
	void SetMapTilePositions(vector< vector<SDL_Rect> > tilePositions);

	void Render();

private:
	int mMapX;
	int mMapY;

	int mPosX;
	int mPosY;

	SDL_Rect mCharacter;

	vector< vector<SDL_Rect> > mMapTilePositions;
};

