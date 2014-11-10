#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <vector>

#include "GameTimer.h"
#include "Texture.h"
#include "Graphics.h"
#include "TileMap.h"

using namespace std;

Texture gTileTexture;
TileMap gTileMap; 
GameTimer gTimer;
//vector<Tile> *gTileSet;
//Spaceship gShip;


bool initSDL()
{
	//Initialization flag
	bool success = true;

	SDL_Init( SDL_INIT_VIDEO );
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
	Graphics::gWindow = SDL_CreateWindow( "MoonLander", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	Graphics::gRenderer = SDL_CreateRenderer( Graphics::gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	return success;
}

string getApplicationPath()
{
	char buffer[MAX_PATH];
	GetModuleFileName( NULL, buffer, MAX_PATH );

	char *pos = strrchr(buffer, '\\');
	if (pos != NULL) 
	   *pos = '\0';

	string appPath(buffer);
	return appPath;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	string appPath = getApplicationPath();

	//Load tile texture
	if( !gTileTexture.loadFromFile( appPath + "\\assets\\texture_atlas.png" ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

	gTileMap.SetTileTexture(gTileTexture);
	gTileMap.LoadAndBuildTileMap(appPath);

	return success;
}

void close()
{
	//Free loaded images
	//gLanderTexture.free();

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
	//Init timer by reseting
	gTimer.Reset();

	//Start up SDL and create window
	if( !initSDL() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//While application is running
			while( !quit )
			{
				SDL_PumpEvents(); 

				// Keyboard state!
				const Uint8* keystate = SDL_GetKeyboardState(NULL);

				if (SDL_QuitRequested()){
					quit = true;
					continue;
				}

				//Tick timer forward
				gTimer.Tick();

				Update(keystate);

				//Clear screen
				SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( Graphics::gRenderer );


				
				gTileMap.Render();


				//Render red filled quad
				//SDL_Rect fillRect = { 50, 50, 50, 50 };
				//SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
				//SDL_RenderFillRect( Graphics::gRenderer, &fillRect );


				//Render objects
				//SDL_Rect backgroundRect = { 0, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT };
				//gTileTexture.render(0, 0, &backgroundRect);

				//gStarfieldTexture.render(0,0,&backgroundRect);
				//gShip.Render(gLanderTexture);

				//Update screen
				SDL_RenderPresent( Graphics::gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	//if(!success)
	string str;
	cin >> str;

	return 0;
}