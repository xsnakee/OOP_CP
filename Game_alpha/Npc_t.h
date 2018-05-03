#pragma once
#include "character_t.h"


class Npc_t :
	public character_t
{
protected:
	sf::Vector2f spotCoords;
	float spawnRandomDistanceX;
	float spawnRandomDistanceY;
	sf::Int32 spawnTime;

	float moveRadius;
	float powerMultiple;

public:
	Npc_t();
	Npc_t(sf::Texture *_texture, sf::Clock *_clock,float  _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple = 1.f);
	Npc_t(sf::Texture *texture, sf::Clock *_clock, sf::Vector2f _spotCoords, int _coordX, int _coordY, int _width, int _height, float _multiple, float randDistX, float randDistY);
	virtual ~Npc_t();

	virtual void controller(sf::Event);
	virtual bool checkKeyCd(sf::Clock *clock);

	sf::Vector2f getSpotCoords() const{
		return spotCoords;
	}

	float getMoveRadius() const {
		return moveRadius;
	}

	float getPowerMultiple() const {
		return powerMultiple;
	}

	sf::Vector2f getSpawnDistance() const {
		return sf::Vector2f(spawnRandomDistanceX,spawnRandomDistanceY);
	}

	float setPowerMultiple(float _mult) {
		stat.statMiltipler(_mult);
		return powerMultiple;
	}

	float setSpawnDistanceX(float _dist) {
		spawnRandomDistanceX = _dist;
		return spawnRandomDistanceX;
	}
	float setSpawnDistanceY(float _dist) {
		spawnRandomDistanceY = _dist;
		return spawnRandomDistanceY;
	}
	
};

