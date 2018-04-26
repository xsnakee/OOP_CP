#include "Npc_t.h"



Npc_t::Npc_t()
{
}


Npc_t::Npc_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _x, _y, _coordX, _coordY, _width, _height)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnCoords = spotCoords;
	spawnDistance = 0;
	moveRadius = 0.f;
	powerMultiple = _statMultiple;
	setPowerMultiple(powerMultiple);
}


Npc_t::~Npc_t()
{
}
