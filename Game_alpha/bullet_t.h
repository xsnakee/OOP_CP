#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
#include "character_t.h"
#include "additional.h"


class character_t;


class bullet_t:public physOb_t
{
private:
	sf::Clock *clock;
	bulletStats stat;
	character_t *genericObject;
	

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds

	bool mass;
	
	float startPosX;
	float startPosY;

	sf::Vector2f targetCoords;
	float vectorLength;
public:
	bullet_t();
	bullet_t(bullet_t &bullet);
	bullet_t(sf::Clock *time, character_t *genObj, sf::Vector2f _targetCoords);
	virtual ~bullet_t();


	virtual bool checkAlive();
	virtual void update(float speed);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 0.f);

public:

	//GET
	character_t *getGenericObject()const {
		return genericObject;
	}

	virtual sf::Int32 getStartTime() const {
		return startTime;
	}

	bulletStats getStats() {
		return stat;
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
		mass = (_stats.AOE > FLT_EPSILON) ? true : false;
		stat = _stats;
	}

	void setTimer(sf::Int32 _timer) {
		timer = _timer;
	}

	void setDmg(float _val) {
		stat.damage = _val;
	}
	void setSpeed(float _val) {
		stat.speed = _val;
	}
	void setRng(float _val) {
		stat.range = _val;
	}

	void setAOE(float _val)  {
		mass = (_val > FLT_EPSILON) ? true : false;
		stat.AOE = _val;
	}

	void setType(bool _val) {
		stat.type = _val;
	}

};

