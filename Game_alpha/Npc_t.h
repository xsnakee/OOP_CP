#pragma once
#include "character_t.h"
class Npc_t :
	public character_t
{
	sf::Vector2f spotCoords;
	float moveRadius;

public:
	Npc_t();
	Npc_t(sf::Texture *_texture,float  _x, float _y, int _coordX, int _coordY, int _width, int _height);
	virtual ~Npc_t();
};

