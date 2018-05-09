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

Npc_t::Npc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple):
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

void Npc_t::setTypeStats() {

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
	stat.attackSpeed = 1.1f;
	stat.stdSpeed = 0.1f;
	defaultAllStats();
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
	stat.attackPower = 2.f;
	stat.damageRand = 7.f;
	stat.stdHP = 70.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 1.5f;
	stat.stdSpeed = 0.11f;
	defaultAllStats();
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
	stat.attackRange = 150.f;
	stat.stdPhysDef = 5.f;
	stat.stdMagDef = 5.f;
	stat.attackPower = 5.f;
	stat.damageRand = 7.f;
	stat.stdHP = 30.f;
	stat.visionDistance = 200.f;
	stat.attackSpeed = 1.f;
	stat.stdSpeed = 0.09f;
	defaultAllStats();
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
	defaultAllStats();
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
	stat.attackPower = 10.f;
	stat.damageRand = 7.f;
	stat.stdHP = 110.f;
	stat.visionDistance = 350.f;
	stat.attackSpeed = 1.f;
	stat.stdSpeed = 0.11f;
	defaultAllStats();
}