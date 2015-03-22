#include "StdAfx.h"
#include "game.h"



game::game(void)
{

}


game::~game(void)
{
}

void game::init()
{
	loadMedia();

	mWorld = new World();

	mTimer.Reset();

	/***************************
	Manual object init for testing
	****************************/

	TileMap* tileMap;
	tileMap = new TileMap();
	tileMap->SetTileTexture(*mTileTextures.GetTexture(Textures::DUNGEON_MAP_TEST_32));
	tileMap->LoadAndBuildTileMap(Utils::GetApplicationPath());
	mWorld->SetDungeonMap(tileMap);

	Character* hero;
	hero = new Character();
	hero->SetMapTilePositions(tileMap->GetMapTilePositions());
	hero->SetMapPosition(8, 2);
	mWorld->AddWorldCharacter(hero);
}

void game::close()
{
	//Free loaded images
	//gLanderTexture.free();
	mWorld->~World();
	mTileTextures.~Textures();

	//Destroy window	
	SDL_DestroyRenderer( Graphics::gRenderer );
	SDL_DestroyWindow( Graphics::gWindow );
	Graphics::gWindow = NULL;
	Graphics::gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool game::loadMedia()
{
	bool success = mTileTextures.LoadTextures();
	return success;

}


void game::draw()
{

	mTimer.Tick();


	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( Graphics::gRenderer );
				
	mWorld->Render();

	SDL_RenderPresent( Graphics::gRenderer );

}

