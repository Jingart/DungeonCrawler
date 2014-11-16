#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <fstream>

#include "Tile.h"
#include "Texture.h"

using namespace std;


class TileMap
{
public:

	//Screen dimension constants 
	//static const int SCREEN_WIDTH = 640; 
	//static const int SCREEN_HEIGHT = 480; 

	//Tile constants 
	static const int TILE_WIDTH = 32; 
	static const int TILE_HEIGHT = 32; 

	static const int TOTAL_TILES = 81; 
	static const int TOTAL_TILE_SPRITES = 10; 

	//The dimensions of the level 
	static const int LEVEL_WIDTH = TILE_WIDTH * 9; 
	static const int LEVEL_HEIGHT = TILE_HEIGHT * 9; 

	//The different tile sprites 
	//static const int TILE_RED = 0; 
	//static const int TILE_GREEN = 1; 
	//static const int TILE_BLUE = 2; 
	//static const int TILE_CENTER = 3; 
	//static const int TILE_TOP = 4; 
	//static const int TILE_TOPRIGHT = 5; 
	//static const int TILE_RIGHT = 6; 
	//static const int TILE_BOTTOMRIGHT = 7; 
	//static const int TILE_BOTTOM = 8; 
	//static const int TILE_BOTTOMLEFT = 9; 
	//static const int TILE_LEFT = 10; 
	//static const int TILE_TOPLEFT = 11;

	static const int TILE_STONEFLOOR = 0; 
	static const int TILE_GRAVELFLOOR = 1; 
	static const int TILE_WATER = 2; 
	static const int TILE_BOARDFLOOR_HORIZONTAL = 3; 
	static const int TILE_BOARDFLOOR_VERTICAL = 4; 
	static const int TILE_STATUE = 5; 
	static const int TILE_WALL_DOWN = 6; 
	static const int TILE_WALL_LEFT = 7; 
	static const int TILE_WALL_UP = 8; 
	static const int TILE_WALL_RIGHT = 9; 


	TileMap(void);
	~TileMap(void);

	void SetTileTexture(Texture &tileTextureAtlas);
	bool LoadAndBuildTileMap(string appPath);
	void Render();

private:
	//SDL_Rect TileTextureClips[ TOTAL_TILE_SPRITES ];

	//vector<SDL_Rect> *mTileTextureClips;
	SDL_Rect mTileTextureClips[ TOTAL_TILE_SPRITES ];
	vector<Tile> mTileSet;
	Texture *mTileTextureAtlas;
};

