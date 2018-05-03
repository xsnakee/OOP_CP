#include "Npc_t.h"




Npc_t::Npc_t(sf::Texture *_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _bulletList, _x, _y, _coordX, _coordY, _width, _height,_clock)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnCoords = spotCoords;
	spawnRandomDistanceX = 0.f;
	spawnRandomDistanceY = 0.f;
	moveRadius = 0.f;
	powerMultiple = _statMultiple;

	stat.statMiltipler(powerMultiple);
	state = std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(this));
	spawnTime = std::numeric_limits<sf::Int32>::max();
}

//REWORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Npc_t::Npc_t(sf::Texture *_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _coordX, int _coordY, int _width, int _height, float _multiple, float randDistX, float randDistY) :
	character_t(_texture, _bulletList,_spotCoords.x, _spotCoords.y, _coordX, _coordY, _width, _height, _clock)
{	
	spotCoords = _spotCoords;


	spawnRandomDistanceX = randDistX;
	spawnRandomDistanceY = randDistY;

	spawnCoords.x = spotCoords.x + spawnRandomDistanceX;
	spawnCoords.y = spotCoords.y + spawnRandomDistanceY;

	moveRadius = 0.f;
	powerMultiple = _multiple;
	stat.statMiltipler(powerMultiple);
	state = std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(this));
	spawnTime = std::numeric_limits<sf::Int32>::max();
}

Npc_t::~Npc_t()
{
	
}

void Npc_t::controller(sf::Event) {
	
}

bool Npc_t::checkKeyCd(sf::Clock *clock) {
	return true;
}
