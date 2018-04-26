#pragma once
#include "character_t.h"
class Npc_t :
	public character_t
{
	sf::Vector2f spotCoords;
	sf::Vector2f spawnCoords;
	int spawnDistance;

	float moveRadius;
	float powerMultiple;

public:
	Npc_t();
	Npc_t(sf::Texture *_texture,float  _x, float _y, int _coordX, int _coordY, int _width, int _height, float _statMultiple = 1.f);
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


	float setPowerMultiple(float _mult) {
		stat.statMiltipler(_mult);
		return powerMultiple;
	}
};

