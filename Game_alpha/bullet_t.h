#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
#include "additional.h"

struct bulletStats{
	float speed;
	float damage;
	float range;
	elements::element element = elements::NONE;
	float AOE;
	bool type = false;
};

class bullet_t:public physOb_t
{
private:
	sf::Clock *clock;
	bulletStats stat;

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds
	bool mass;

	sf::Vector2f targetCoords;

public:
	bullet_t();
	bullet_t(float _posX, float _posY, float _speed, elements::element _element, float _AOE, sf::Vector2f _targetCoords);
	bullet_t(sf::Clock *time, float _timer, float _posX, float _posY, float _speed, elements::element _element, sf::Vector2f _targetCoords, float _AOE);
	bullet_t(sf::Clock *time, physOb_t *genObj, sf::Vector2f _targetCoords);
	virtual ~bullet_t();


	virtual bool checkAlive();

public:

	//GET


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
};

