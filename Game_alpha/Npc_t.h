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

public:

	Npc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock,float  _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple = 1.f);
	Npc_t(std::shared_ptr<sf::Texture>texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _coordX, int _coordY, int _width, int _height, float _multiple);
	virtual ~Npc_t();

	virtual void attack();

	sf::Vector2f getSpotCoords() const{
		return spotCoords;
	}

	float getPowerMultiple() const {
		return powerMultiple;
	}

	
};

