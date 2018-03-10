#pragma once

#include "character_t.h"
const size_t HERO_SPRITE_HEIGHT = 50;
const size_t HERO_SPRITE_WIDTH = 50;

class player_t : public character_t
{
	
public:

	player_t();
	player_t(float _x, float _y);
	~player_t();
};

