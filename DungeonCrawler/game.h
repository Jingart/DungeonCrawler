#pragma once
#include <string>
#include <vector>
#include "GameTimer.h"
#include "Textures.h"
#include "Graphics.h"
#include "TileMap.h"
#include "Utils.h"
#include "World.h"
#include "Character.h"

using namespace std;



class game
{
public:
	game(void);
	~game(void);

	void init();

	void close();

	bool loadMedia();

	void draw();

private:

	Textures mTileTextures;
	Texture mTex;
	GameTimer mTimer;
	World *mWorld;

};

