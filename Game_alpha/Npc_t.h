#pragma once
#include "character_t.h"
#include "additional.h"

class Npc_t :
	public character_t
{
protected:
	sf::Vector2f spotCoords;
	sf::Int32 spawnTime;
	float powerMultiple;

	virtual void setTypeStats();
public:

	Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock,float  _x, float _y, int _width, int _height, float _statMultiple = 1.f);
	Npc_t(std::shared_ptr<sf::Texture>texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	Npc_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	
	virtual ~Npc_t();

	virtual void attack();

	sf::Vector2f getSpotCoords() const{
		return spotCoords;
	}

	float getPowerMultiple() const {
		return powerMultiple;
	}
};


class MageNpc_t : public Npc_t {

	virtual void setTypeStats();
public:
	MageNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	MageNpc_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	~MageNpc_t();
};

class WarriorNpc_t : public Npc_t {

	virtual void setTypeStats();
public:
	WarriorNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	WarriorNpc_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	~WarriorNpc_t();
};

class ZombieWitch_t : public Npc_t {

	virtual void setTypeStats();
public:
	ZombieWitch_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	ZombieWitch_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	~ZombieWitch_t();
};


class FatZombie_t : public Npc_t {

	virtual void setTypeStats();
public:
	FatZombie_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	FatZombie_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	~FatZombie_t();
};


class SkeletonMage_t : public Npc_t {

	virtual void setTypeStats();
public:
	SkeletonMage_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 1.f);
	SkeletonMage_t(character_t *copyedNpc, sf::Vector2f sporPoint, float powerMultiple = 1.f);
	~SkeletonMage_t();
};