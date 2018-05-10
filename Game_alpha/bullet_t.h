#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
#include "character_t.h"
#include <list>
#include "additional.h"

struct bulletStats {
	float speed;
	float damage;
	float range;
	elements::element element = elements::NONE;
	float AOE = 0.1f;
	bool type = true;//0 - heal, 1 - dmg
	int fraction = -1;
	float mpCost = 10.f;
};


class dmgInterval_t {
public:
	physOb_t &ob;
	sf::Int32 startDmgTime;

	dmgInterval_t(physOb_t &_ob):ob (_ob){
		startDmgTime = 0;
	}

	~dmgInterval_t() {

	}
};

class character_t;


class bullet_t:public physOb_t
{
private:
	sf::Clock *clock;
	bulletStats stat;
	character_t *genericObject;
	
	std::list<dmgInterval_t> obList;

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds

	sf::Int32 dmgInterval;

	bool mass;
	
	float startPosX;
	float startPosY;

	sf::Vector2f targetCoords;
	float vectorLength;

	virtual void updateFrame();
	virtual void animation();
	dmgInterval_t &checkObInList(physOb_t &Object);
public:
	bullet_t();
	bullet_t(sf::Clock *time, character_t *genObj, sf::Vector2f _targetCoords);
	virtual ~bullet_t();


	virtual bool checkAlive();
	virtual void update(float speed);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 0.f);
	bool hitting(physOb_t &Object, float _speed, float _borderError = 0.f);
	

public:

	//GET
	character_t *getGenericObject()const {
		return genericObject;
	}

	sf::Int32 getStartTime() const {
		return startTime;
	}

	bulletStats getStats() {
		return stat;
	}

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

	float getMPCost() const {
		return stat.mpCost;
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

	void speedMultiple(float _val) {
		stat.speed *= _val;
		dX *= _val;
		dY *= _val;
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

	void setDmgDelay(sf::Int32 _time) {
		dmgInterval = _time;
	}

	void setMPCost(float _val) {
		stat.mpCost = _val;
	}
};

