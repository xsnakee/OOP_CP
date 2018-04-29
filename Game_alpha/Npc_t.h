#pragma once
#include "character_t.h"


class Npc_t :
	public character_t
{
protected:
	sf::Vector2f spotCoords;
	float spawnRandomDistance;

	float moveRadius;
	float powerMultiple;

public:
	Npc_t();
	Npc_t(sf::Texture *_texture,float  _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple = 1.f);
	Npc_t(sf::Texture *texture, sf::Vector2f _spotCoords, float _multiple, float _moveRadius, int _spawnRandDist = 0);
	virtual ~Npc_t();


	sf::Vector2f getSpotCoords() const{
		return spotCoords;
	}

	float getMoveRadius() const {
		return moveRadius;
	}

	float getPowerMultiple() const {
		return powerMultiple;
	}

	float getSpawnDistance() const {
		return spawnRandomDistance;
	}

	float setPowerMultiple(float _mult) {
		stat.statMiltipler(_mult);
		return powerMultiple;
	}
	
};

