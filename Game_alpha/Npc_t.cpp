#include "Npc_t.h"



Npc_t::Npc_t()
{
}


Npc_t::Npc_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _x, _y, _coordX, _coordY, _width, _height)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnRandomDistance = 0.f;
	spawnCoords = spotCoords;
	moveRadius = 0.f;
	powerMultiple = _statMultiple;
	setPowerMultiple(powerMultiple);
}

//REWORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Npc_t::Npc_t(sf::Texture *texture, sf::Vector2f _spotCoords, float _multiple, float _moveRadius, int _spawnRandDist) :character_t()
{
	spotCoords = _spotCoords;

	srand(_spawnRandDist);
	spawnRandomDistance = static_cast<float>(rand() % _spawnRandDist);
	spawnCoords.x = spotCoords.x + spawnRandomDistance;
	spawnRandomDistance = static_cast<float>(rand() % _spawnRandDist);
	spawnCoords.y = spotCoords.y + spawnRandomDistance;

	moveRadius = moveRadius;
	powerMultiple = _multiple;
	setPowerMultiple(powerMultiple);
}

Npc_t::~Npc_t()
{
	
}

