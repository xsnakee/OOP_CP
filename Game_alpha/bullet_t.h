#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
//#include "character_t.h"
#include "additional.h"

struct bulletStats{
	float speed;
	float damage;
	float range;
	elements::element element = elements::NONE;
	float AOE = 0.1f;
	bool type = false;
	int fraction = -1;
};

class bullet_t:public physOb_t
{
private:
	sf::Clock *clock;
	bulletStats stat;
	physOb_t *genericObject;
	

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds

	bool mass;
	
	float startPosX;
	float startPosY;

	sf::Vector2f targetCoords;
	float vectorLength;
public:
	bullet_t();
	bullet_t(sf::Clock *time, physOb_t *genObj, sf::Vector2f _targetCoords);
	virtual ~bullet_t();


	virtual bool checkAlive();
	virtual void update(float speed);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 0.f);

public:

	//GET
	physOb_t * getGenericObject()const {
		return genericObject;
	}

	virtual sf::Int32 getStartTime() const {
		return startTime;
	}

	int getElement()const {
		return stat.element;
	}

	virtual sf::Int32 getTimer()const {
		return timer;
	}

	float getDmg()const {
		return stat.damage;
	}
	float getRng()const {
		return stat.range;
	}

	float getAOE() const {
		return stat.AOE;
	}
	
	bool checkAOE() const {
		return mass;
	}
	//SET

	int setElement(elements::element _element){
		stat.element = _element;
		return stat.element;
	}

	bool setStats(bulletStats &_stats) {
		stat = _stats;
	}
};

