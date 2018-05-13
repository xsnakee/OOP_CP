#include "Npc_t.h"
#include <iostream>



Npc_t::Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, float _x, float _y, int _width, int _height, float _statMultiple) 
	:character_t(_texture, _bulletList, _x, _y, 0,0,_width, _height,_clock)
{
	spotCoords = sf::Vector2f(_x,_y);
	spawnCoords = spotCoords;
	powerMultiple = _statMultiple;

	stat.statMiltipler(powerMultiple);
	state.swap(std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(*this)));
	spawnTime = std::numeric_limits<sf::Int32>::max();
	elemStatus = 1;
	collision = false;
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
	state.swap(std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(*this)));
	spawnTime = std::numeric_limits<sf::Int32>::max();
	elemStatus = 1;
	collision = false;
}

Npc_t::Npc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple):
	character_t(copyedNpc->getSpritePref().getTextureSharedPtr(), copyedNpc->getSkillGeneratorPtr()->getBulletList(), spotPoint.x, spotPoint.y, 0, 0,
		copyedNpc->getWidth(), copyedNpc->getHeight(), copyedNpc->getClockPtr()) {
	setStats(copyedNpc->getStats());
	elemStatus = copyedNpc->getElemStatus();

	spotCoords = spotPoint;

	spawnCoords.x = spotPoint.x;
	spawnCoords.y = spotPoint.y;
	powerMultiple = powerMultiple;
	stat.statMiltipler(powerMultiple);

	state.swap(std::unique_ptr<CharacterState_t>(new CharacterStateMove_t(*this)));
	spawnTime = std::numeric_limits<sf::Int32>::max();

	collision = copyedNpc->getCollision();
	alive = copyedNpc->getAlive();
	clock = copyedNpc->getClockPtr();
	moveRadius = copyedNpc->getMoveRadius();
	fraction = copyedNpc->getFraction();
	timer = copyedNpc->getTimer();
}
 
Npc_t::~Npc_t()
{
	
}


void Npc_t::attack() {
	character_t::attack();
}

void Npc_t::setTypeStats() {
	timer.attackCDcorrection(stat.attackSpeed);
	timer.castDelayCorrection(stat.castSpeed);
}

//MAGE CLASS


MageNpc_t::MageNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture,_bulletList,_clock,_spotCoords,_width, _height, _multiple)
{
	setTypeStats();
}

MageNpc_t::MageNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
Npc_t(copyedNpc, spotPoint, powerMultiple)
{
	setTypeStats();
}

MageNpc_t::~MageNpc_t() {

}

void MageNpc_t::setTypeStats() {

	elemStatus = 5;//FIRE BALLS
	stat.attackRange = 200.f;
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 10.f;
	stat.damageRand = 2.f;
	stat.stdHP = 50.f;
	stat.visionDistance = 220.f;
	stat.attackSpeed = 3.f;
	stat.stdSpeed = 0.1f;
	defaultAllStats();
	Npc_t::setTypeStats();
}
//WARRIOR CLASS
WarriorNpc_t::WarriorNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setTypeStats();
}
WarriorNpc_t::WarriorNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
	setTypeStats();
}
WarriorNpc_t::~WarriorNpc_t() {

}
void WarriorNpc_t::setTypeStats() {

	elemStatus = 1;//SWORD ATTACK
	stat.attackRange = 40.f;
	stat.stdPhysDef = 15.f;
	stat.stdMagDef = 5.f;
	stat.attackPower = 7.f;
	stat.damageRand = 10.f;
	stat.stdHP = 70.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 5.f;
	stat.stdSpeed = 0.16f;
	defaultAllStats();
	Npc_t::setTypeStats();
}
//ZOMBIE WITCH CLASS
ZombieWitch_t::ZombieWitch_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setTypeStats();
}
ZombieWitch_t::ZombieWitch_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
	setTypeStats();
}
ZombieWitch_t::~ZombieWitch_t() {

}
void ZombieWitch_t::setTypeStats() {

	elemStatus = 4;//FIRE LIGHTING
	stat.attackRange = 250.f;
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 5.f;
	stat.attackPower = 10.f;
	stat.damageRand = 7.f;
	stat.stdHP = 50.f;
	stat.visionDistance = 300.f;
	stat.attackSpeed = 1.f;
	stat.stdSpeed = 0.09f;
	defaultAllStats();
	Npc_t::setTypeStats();
}
//FAT ZOMBIE CLASS
FatZombie_t::FatZombie_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setTypeStats();
}
FatZombie_t::FatZombie_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
	setTypeStats();
}
FatZombie_t::~FatZombie_t() {

}
void FatZombie_t::setTypeStats() {

	elemStatus = 2;//POISION BALL
	stat.attackRange = 50.f;
	stat.stdPhysDef = 10.f;
	stat.stdMagDef = 10.f;
	stat.attackPower = 30.f;
	stat.damageRand = 7.f;
	stat.stdHP = 100.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 2.f;
	stat.stdSpeed = 0.08f;
	defaultAllStats();
	Npc_t::setTypeStats();
}
//SKELETON MAGE CLASS
SkeletonMage_t::SkeletonMage_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setTypeStats();
}
SkeletonMage_t::SkeletonMage_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) :
	Npc_t(copyedNpc, spotPoint, powerMultiple)
{
	setTypeStats();
}

SkeletonMage_t::~SkeletonMage_t() {

}
void SkeletonMage_t::setTypeStats() {

	elemStatus = 12;//POISION BALL
	stat.attackRange = 300.f;
	stat.stdPhysDef = 20.f;
	stat.stdMagDef = 20.f;
	stat.attackPower = 30.f;
	stat.damageRand = 15.f;
	stat.stdHP = 110.f;
	stat.visionDistance = 350.f;
	stat.attackSpeed = -2.f;
	stat.stdSpeed = 0.11f;
	defaultAllStats();
	Npc_t::setTypeStats();
}