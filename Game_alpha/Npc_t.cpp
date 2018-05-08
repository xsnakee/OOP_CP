#include "Npc_t.h"
#include <iostream>



Npc_t::Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, float _x, float _y, int _width, int _height, float _statMultiple) :character_t(_texture, _bulletList, _x, _y, 0,0,_width, _height,_clock)
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

Npc_t::Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	character_t(_texture, _bulletList,_spotCoords.x, _spotCoords.y, 0, 0, _width, _height, _clock)
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



//MAGE CLASS


MageNpc_t::MageNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture,_bulletList,_clock,_spotCoords,_width, _height, _multiple)
{
	elemStatus = 5;//FIRE BALLS
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 10.f;
	stat.damageRand = 2.f;
	stat.stdHP = 50.f;
	stat.visionDistance = 200.f;
	stat.attackSpeed = 1.1f;
	stat.stdSpeed = 0.1f;
	defaultStats();
}

MageNpc_t::~MageNpc_t() {

}


//WARRIOR CLAS
WarriorNpc_t::WarriorNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	elemStatus = 1;//SWORD ATTACK
	stat.stdPhysDef = 15.f;
	stat.stdMagDef = 5.f;
	stat.attackPower = 2.f;
	stat.damageRand = 7.f;
	stat.stdHP = 70.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 1.5f;
	stat.stdSpeed = 0.11f;
	defaultStats();
}

WarriorNpc_t::~WarriorNpc_t() {

}