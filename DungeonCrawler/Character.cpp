#include "Character.h"


Character::Character(void)
{
	mCharacter.x = 0;
	mCharacter.y = 0;
	mCharacter.w = 15;
	mCharacter.h = 15;

	mMapX = 0;
	mMapY = 0;

	mPosX = 0;
	mPosY= 0;


}


Character::~Character(void)
{
}


void Character::SetMapPosition(int x, int y)
{
	mMapX = x;
	mMapY = y;

	mCharacter.x = x;
	mCharacter.y = y;
}


void Character::Render()
{
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( Graphics::gRenderer, &mCharacter );
}
