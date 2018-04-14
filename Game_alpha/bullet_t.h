#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
#include "additional.h"

struct bulletStats{
	float speed;
	float damage;
	float range;
	elements::element element;
	float AOE;
};

class bullet_t:public physOb_t
{
private:
	bulletStats stat;

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds
	bool mass;

	sf::Vector2i targetCoords;

public:
	bullet_t();
	bullet_t(float _posX, float _posY, float _speed, elements::element _element, float _AOE, sf::Vector2i _targetCoords);
	bullet_t(sf::Clock *time, float _timer, float _posX, float _posY, float _speed, elements::element _element, sf::Vector2i _targetCoords, float _AOE);
	virtual ~bullet_t();

public:
	virtual bool checkTimer(sf::Clock *time);
public:

	//GET
	int getElement()const {
		return stat.element;
	}

	sf::Int32 getTimer()const {
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

