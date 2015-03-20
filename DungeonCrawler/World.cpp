#include "stdafx.h"
#include "World.h"


World::World(void)
{
}


World::~World(void)
{
}


void World::SetDungeonMap(TileMap* map){

	mDungeonMap = map;
}


void World::AddWorldCharacter(Character* character)
{
	mCharacters.push_back(character);
}


void World::Update()
{

}


void World::Render()
{
	mDungeonMap->Render();

	for(int i = 0; i < mCharacters.size(); i++)
		mCharacters[i]->Render();
}
