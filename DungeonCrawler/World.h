#pragma once
#include "TileMap.h"
#include "Character.h"
#include <vector>

class World
{
public:
	World(void);
	~World(void);

	void SetDungeonMap(TileMap* map);
	void AddWorldCharacter(Character* character);

	void Update();
	void Render();

private:
	TileMap *mDungeonMap;
	vector<Character*> mCharacters;
};

