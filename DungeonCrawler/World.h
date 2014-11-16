#pragma once
#include "TileMap.h"

class World
{
public:
	World(void);
	~World(void);

	void SetDungeonMap();

private:
	TileMap *mDungeonMap;
};

