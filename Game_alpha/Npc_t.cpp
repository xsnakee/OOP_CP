#include "Npc_t.h"



Npc_t::Npc_t()
{
}


Npc_t::Npc_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _x, _y, _coordX, _coordY, _width, _height)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnCoords = spotCoords;
	spawnRandomDistanceX = 0.f;
	spawnRandomDistanceY = 0.f;
	moveRadius = 0.f;
	powerMultiple = _statMultiple;
	setPowerMultiple(powerMultiple);
}

//REWORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Npc_t::Npc_t(sf::Texture *texture, sf::Vector2f _spotCoords, float _multiple, float randDistX, float randDistY) :character_t(texture, _spotCoords.x, _spotCoords.y)
{
	spotCoords = _spotCoords;


	spawnRandomDistanceX = randDistX;
	spawnRandomDistanceY = randDistY;

	spawnCoords.x = spotCoords.x + spawnRandomDistanceX;
	spawnCoords.y = spotCoords.y + spawnRandomDistanceY;

	moveRadius = moveRadius;
	powerMultiple = _multiple;
	setPowerMultiple(powerMultiple);
}

Npc_t::~Npc_t()
{
	
}

void Npc_t::controller(sf::Event) {
	
}

bool Npc_t::checkKeyCd(sf::Clock *clock) {
	return true;
}

bool Npc_t::attack(float _x, float _y) {

	return true;
}