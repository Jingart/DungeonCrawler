#include "TileMap.h"


TileMap::TileMap(void)
{
}


TileMap::~TileMap(void)
{
}


bool TileMap::LoadAndBuildTileMap(string appPath)
{
	//Success flag
	bool tilesLoaded = true;
	Tile *tile = 0;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    ifstream mapStream( appPath + "/dungeon.map" );

    //If the map couldn't be loaded
    if( mapStream == NULL )
    {
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
    }
	else
	{
		//Initialize the tiles
		for( int i = 0; i < TOTAL_TILES; ++i )
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			mapStream >> tileType;

			//If the was a problem in reading the map
			if( mapStream.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
			{
				tile = new Tile( x, y, TILE_WIDTH, TILE_HEIGHT, tileType );
				mTileSet.push_back(*tile);
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}
		
		//Clip the sprite sheet
		if( tilesLoaded )
		{
			/*mTileTextureClips[ TILE_RED ].x = 0;
			mTileTextureClips[ TILE_RED ].y = 0;
			mTileTextureClips[ TILE_RED ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_RED ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_GREEN ].x = 0;
			mTileTextureClips[ TILE_GREEN ].y = 80;
			mTileTextureClips[ TILE_GREEN ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_GREEN ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_BLUE ].x = 0;
			mTileTextureClips[ TILE_BLUE ].y = 160;
			mTileTextureClips[ TILE_BLUE ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_BLUE ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_TOPLEFT ].x = 80;
			mTileTextureClips[ TILE_TOPLEFT ].y = 0;
			mTileTextureClips[ TILE_TOPLEFT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_TOPLEFT ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_LEFT ].x = 80;
			mTileTextureClips[ TILE_LEFT ].y = 80;
			mTileTextureClips[ TILE_LEFT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_LEFT ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_BOTTOMLEFT ].x = 80;
			mTileTextureClips[ TILE_BOTTOMLEFT ].y = 160;
			mTileTextureClips[ TILE_BOTTOMLEFT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_BOTTOMLEFT ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_TOP ].x = 160;
			mTileTextureClips[ TILE_TOP ].y = 0;
			mTileTextureClips[ TILE_TOP ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_TOP ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_CENTER ].x = 160;
			mTileTextureClips[ TILE_CENTER ].y = 80;
			mTileTextureClips[ TILE_CENTER ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_CENTER ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_BOTTOM ].x = 160;
			mTileTextureClips[ TILE_BOTTOM ].y = 160;
			mTileTextureClips[ TILE_BOTTOM ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_BOTTOM ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_TOPRIGHT ].x = 240;
			mTileTextureClips[ TILE_TOPRIGHT ].y = 0;
			mTileTextureClips[ TILE_TOPRIGHT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_TOPRIGHT ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_RIGHT ].x = 240;
			mTileTextureClips[ TILE_RIGHT ].y = 80;
			mTileTextureClips[ TILE_RIGHT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_RIGHT ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_BOTTOMRIGHT ].x = 240;
			mTileTextureClips[ TILE_BOTTOMRIGHT ].y = 160;
			mTileTextureClips[ TILE_BOTTOMRIGHT ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_BOTTOMRIGHT ].h = TILE_HEIGHT;*/

			mTileTextureClips[ TILE_STONEFLOOR ].x = 0;
			mTileTextureClips[ TILE_STONEFLOOR ].y = 0;
			mTileTextureClips[ TILE_STONEFLOOR ].w = 16;
			mTileTextureClips[ TILE_STONEFLOOR ].h = 16;

			mTileTextureClips[ TILE_GRAVELFLOOR ].x = 0;
			mTileTextureClips[ TILE_GRAVELFLOOR ].y = 16;
			mTileTextureClips[ TILE_GRAVELFLOOR ].w = 16;
			mTileTextureClips[ TILE_GRAVELFLOOR ].h = 16;

			mTileTextureClips[ TILE_WATER ].x = 0;
			mTileTextureClips[ TILE_WATER ].y = 32;
			mTileTextureClips[ TILE_WATER ].w = TILE_WIDTH;
			mTileTextureClips[ TILE_WATER ].h = TILE_HEIGHT;

			mTileTextureClips[ TILE_BOARDFLOOR_HORIZONTAL ].x = 0;
			mTileTextureClips[ TILE_BOARDFLOOR_HORIZONTAL ].y = 48;
			mTileTextureClips[ TILE_BOARDFLOOR_HORIZONTAL ].w = 16;
			mTileTextureClips[ TILE_BOARDFLOOR_HORIZONTAL ].h = 16;

			mTileTextureClips[ TILE_BOARDFLOOR_VERTICAL ].x = 0;
			mTileTextureClips[ TILE_BOARDFLOOR_VERTICAL ].y = 64;
			mTileTextureClips[ TILE_BOARDFLOOR_VERTICAL ].w = 16;
			mTileTextureClips[ TILE_BOARDFLOOR_VERTICAL ].h = 16;

			mTileTextureClips[ TILE_STATUE ].x = 0;
			mTileTextureClips[ TILE_STATUE ].y = 80;
			mTileTextureClips[ TILE_STATUE ].w = 16;
			mTileTextureClips[ TILE_STATUE ].h = 16;

			mTileTextureClips[ TILE_WALL_DOWN ].x = 16;
			mTileTextureClips[ TILE_WALL_DOWN ].y = 0;
			mTileTextureClips[ TILE_WALL_DOWN ].w = 16;
			mTileTextureClips[ TILE_WALL_DOWN ].h = 16;

			mTileTextureClips[ TILE_WALL_LEFT ].x = 16;
			mTileTextureClips[ TILE_WALL_LEFT ].y = 16;
			mTileTextureClips[ TILE_WALL_LEFT ].w = 16;
			mTileTextureClips[ TILE_WALL_LEFT ].h = 16;

			mTileTextureClips[ TILE_WALL_UP ].x = 16;
			mTileTextureClips[ TILE_WALL_UP ].y = 32;
			mTileTextureClips[ TILE_WALL_UP ].w = 16;
			mTileTextureClips[ TILE_WALL_UP ].h = 16;

			mTileTextureClips[ TILE_WALL_RIGHT ].x = 16;
			mTileTextureClips[ TILE_WALL_RIGHT ].y = 48;
			mTileTextureClips[ TILE_WALL_RIGHT ].w = 16;
			mTileTextureClips[ TILE_WALL_RIGHT ].h = 16;

		}
	}

    //Close the file
    mapStream.close();

    //If the map was loaded fine
    return tilesLoaded;
}


void TileMap::SetTileTexture(Texture &tileTextureAtlas)
{
	mTileTextureAtlas = &tileTextureAtlas;
}


void TileMap::Render()
{
	//SDL_Rect camera = { 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT };
	//SDL_Rect backgroundRect = { 0, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT };
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		//mTileSet[i]->render( camera );
		//mTileSet[i].render(camera, mTileTextureClips, mTileTextureAtlas);

		SDL_Rect t = mTileSet[i].getBox();
		mTileTextureAtlas->render( t.x, t.y, &mTileTextureClips[ mTileSet[i].getType() ] );

		/*mTileTextureAtlas.render(0, 0, &backgroundRect);*/
	}

}
