#include "Npc_t.h"




Npc_t::Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, float _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple) :character_t(_texture, _bulletList, _x, _y, _coordX, _coordY, _width, _height,_clock)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnCoords = spotCoords;
	powerMultiple = _statMultiple;

	stat.statMiltipler(powerMultiple);
	state = std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(this));
	spawnTime = std::numeric_limits<sf::Int32>::max();
	elemStatus = 1;
}

//REWORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Npc_t::Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _coordX, int _coordY, int _width, int _height, float _multiple) :
	character_t(_texture, _bulletList,_spotCoords.x, _spotCoords.y, _coordX, _coordY, _width, _height, _clock)
{	
	spotCoords = _spotCoords;

	spawnCoords.x = spotCoords.x;
	spawnCoords.y = spotCoords.y;
	powerMultiple = _multiple;
	stat.statMiltipler(powerMultiple);
	state = std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(this));
	spawnTime = std::numeric_limits<sf::Int32>::max();
	elemStatus = 1;
}

Npc_t::~Npc_t()
{
	
}


void Npc_t::attack() {
	character_t::attack();
}