#include "Npc_t.h"



Npc_t::Npc_t()
{
}


Npc_t::Npc_t(sf::Texture *_texture, sf::Clock *_clock, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _x, _y, _coordX, _coordY, _width, _height,_clock)
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

Npc_t::Npc_t(sf::Texture *_texture, sf::Clock *_clock, sf::Vector2f _spotCoords, int _coordX, int _coordY, int _width, int _height, float _multiple, float randDistX, float randDistY) :
	character_t(_texture, _spotCoords.x, _spotCoords.y, _coordX, _coordY, _width, _height, _clock)
{	
	spotCoords = _spotCoords;


	spawnRandomDistanceX = randDistX;
	spawnRandomDistanceY = randDistY;

	spawnCoords.x = spotCoords.x + spawnRandomDistanceX;
	spawnCoords.y = spotCoords.y + spawnRandomDistanceY;

	moveRadius = 0.f;
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
