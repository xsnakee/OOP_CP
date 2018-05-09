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

Npc_t::Npc_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple):
	character_t(copyedNpc->getSpritePref().getTextureSharedPtr(), copyedNpc->getSkillGeneratorPtr()->getBulletList(), spotPoint.x, spotPoint.y, 0, 0,
		copyedNpc->getWidth(), copyedNpc->getHeight(), copyedNpc->getClockPtr()) {
	stat = copyedNpc->getStats();
	elemStatus = copyedNpc->getElemStatus();

	spotCoords = spotPoint;

	spawnCoords.x = spotPoint.x;
	spawnCoords.y = spotPoint.y;
	powerMultiple = powerMultiple;
	stat.statMiltipler(powerMultiple);

	state = std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(this));
	spawnTime = std::numeric_limits<sf::Int32>::max();
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
	stat.attackRange = 200.f;
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 10.f;
	stat.damageRand = 2.f;
	stat.stdHP = 50.f;
	stat.visionDistance = 220.f;
	stat.attackSpeed = 1.1f;
	stat.stdSpeed = 0.1f;
	defaultStats();
}

MageNpc_t::MageNpc_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
Npc_t(copyedNpc, spotPoint, powerMultiple)
{
}

MageNpc_t::~MageNpc_t() {

}


//WARRIOR CLASS
WarriorNpc_t::WarriorNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	elemStatus = 1;//SWORD ATTACK
	stat.attackRange = 40.f;
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
WarriorNpc_t::WarriorNpc_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
}
WarriorNpc_t::~WarriorNpc_t() {

}

//ZOMBIE WITCH CLASS
ZombieWitch_t::ZombieWitch_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	elemStatus = 4;//FIRE LIGHTING
	stat.attackRange = 150.f;
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 5.f;
	stat.attackPower = 5.f;
	stat.damageRand = 7.f;
	stat.stdHP = 30.f;
	stat.visionDistance = 200.f;
	stat.attackSpeed = 1.f;
	stat.stdSpeed = 0.09f;
	defaultStats();
}
ZombieWitch_t::ZombieWitch_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
}
ZombieWitch_t::~ZombieWitch_t() {

}

//FAT ZOMBIE CLASS
FatZombie_t::FatZombie_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	elemStatus = 6;//POISION BALL
	stat.attackRange = 50.f;
	stat.stdPhysDef = 10.f;
	stat.stdMagDef = 10.f;
	stat.attackPower = 20.f;
	stat.damageRand = 7.f;
	stat.stdHP = 100.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 2.f;
	stat.stdSpeed = 0.08f;
	defaultStats();
}
FatZombie_t::FatZombie_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
}
FatZombie_t::~FatZombie_t() {

}

//SKELETON MAGE CLASS
SkeletonMage_t::SkeletonMage_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	elemStatus = 12;//POISION BALL
	stat.attackRange = 300.f;
	stat.stdPhysDef = 20.f;
	stat.stdMagDef = 20.f;
	stat.attackPower = 10.f;
	stat.damageRand = 7.f;
	stat.stdHP = 110.f;
	stat.visionDistance = 350.f;
	stat.attackSpeed = 2.f;
	stat.stdSpeed = 0.11f;
	defaultStats();
}
SkeletonMage_t::SkeletonMage_t(Npc_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
}

SkeletonMage_t::~SkeletonMage_t() {

}