#include "TileMap.h"


TileMap::TileMap(void)
{
}


TileMap::~TileMap(void)
{
}


bool TileMap::BuildTiles()
{
	//Success flag
	bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    ifstream mapStream( "39_tiling/lazy.map" );

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
				mTileSet[ i ] = new Tile( x, y, tileType );
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
			mTileTextureClips[ TILE_RED ].x = 0;
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
			mTileTextureClips[ TILE_BOTTOMRIGHT ].h = TILE_HEIGHT;
		}
	}

    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}
