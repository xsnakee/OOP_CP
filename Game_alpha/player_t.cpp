#include "player_t.h"



player_t::player_t():character_t()
{
}



//*
player_t::player_t(float _x, float _y, obPreference spritePref): character_t(_x,_y, spritePref) {
	
}
//*/

player_t::~player_t()
{
}


void player_t::update(float time) {

	posX += dX*time;
	posY += dY*time;

	stat.speed = 0;

	sprite.setPosition(posX, posY);
}