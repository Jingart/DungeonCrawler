#pragma once
#include <SDL.h>
//#include <SDL_image.h>

#include <stdio.h>
#include <string>
#include <iostream>
//#include <windows.h>
#include <vector>

#include "GameTimer.h"
#include "Textures.h"
#include "Graphics.h"
#include "TileMap.h"
#include "Utils.h"
#include "World.h"
#include "Character.h"

using namespace std;

Textures gTileTextures;
Texture gtex;
GameTimer gTimer;
World *gWorld;
//vector<Tile> *gTileSet;
//Spaceship gShip;


bool initSDL()
{
	//Initialization flag
	bool success = true;

	SDL_Init( SDL_INIT_VIDEO );
	Graphics::gWindow = SDL_CreateWindow( "DungeonCrawler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	Graphics::gRenderer = SDL_CreateRenderer( Graphics::gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "best" );

	return success;
}

bool loadMedia()
{
	bool success = gTileTextures.LoadTextures();
	return success;

}

void close()
{
	//Free loaded images
	//gLanderTexture.free();
	gWorld->~World();
	gTileTextures.~Textures();

	//Destroy window	
	SDL_DestroyRenderer( Graphics::gRenderer );
	SDL_DestroyWindow( Graphics::gWindow );
	Graphics::gWindow = NULL;
	Graphics::gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void Update(const Uint8* keystate)
{

	/*Spaceship::Action landerAction;*/

	if(keystate[SDL_SCANCODE_UP])
	{
		printf("UP\n");
		//landerAction = Spaceship::moveup;
	}
	
	if(keystate[SDL_SCANCODE_DOWN])
	{
		printf("Down\n");
		//landerAction = Spaceship::movedown;
	}
	
	if(keystate[SDL_SCANCODE_LEFT])
	{
		printf("Left\n");
		//landerAction = Spaceship::moveleft;
	}

	if(keystate[SDL_SCANCODE_RIGHT])
	{
		printf("Right\n");
		//landerAction = Spaceship::moveright;
	}

	//gShip.Update(gTimer.DeltaTime(), landerAction);

}

int main( int argc, char* args[] )
{

	gTimer.Reset();

	if( !initSDL() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		loadMedia();

		gWorld = new World();

		/***************************
		Manual object init for testing
		****************************/

		TileMap* tileMap;
		tileMap = new TileMap();
		tileMap->SetTileTexture(*gTileTextures.GetTexture(Textures::DUNGEON_MAP_TEST_32));
		tileMap->LoadAndBuildTileMap(Utils::GetApplicationPath());
		gWorld->SetDungeonMap(tileMap);

		Character* hero;
		hero = new Character();
		hero->SetMapPosition(1, 1);
		gWorld->AddWorldCharacter(hero);

		/***************************
		****************************/


		bool quit = false;
		while( !quit )
		{
			SDL_PumpEvents(); 

			const Uint8* keystate = SDL_GetKeyboardState(NULL);

			if (SDL_QuitRequested()){
				quit = true;
				continue;
			}

			gTimer.Tick();

			Update(keystate);

			SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( Graphics::gRenderer );
				
			gWorld->Render();

			SDL_RenderPresent( Graphics::gRenderer );
			
		}
	}

	close();
	return 0;
}