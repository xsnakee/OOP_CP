#pragma once

#include "character_t.h"
const int HERO_SPRITE_HEIGHT = 50;
const int HERO_SPRITE_WIDTH = 50;

class player_t : public character_t
{
	
public:

	player_t();
	player_t(float _x, float _y, obPreference spritePref);
	~player_t();
};

