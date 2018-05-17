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

	dmgInterval_t(physOb_t &_ob);

	~dmgInterval_t();
};

class character_t;


class bullet_t :public physOb_t
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

	sf::Vector2f targetPos;
	float vectorLength;

	void updateFrame();
	void animation();
	dmgInterval_t &checkObInList(physOb_t &Object);
public:
	bullet_t();
	bullet_t(sf::Clock *time, character_t *genObj, sf::Vector2f _targetPos);
	virtual ~bullet_t();


	virtual bool checkAlive();
	virtual void update(float speed);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 0.f);
	bool hitting(physOb_t &Object, float _speed, float _borderError = 0.f);


public:

	//GET
	character_t * getGenericObject()const;
	sf::Int32 getStartTime() const;
	bulletStats getStats();
	int getElement()const;
	sf::Int32 getTimer()const;
	float getDmg()const;
	float getRng()const;
	float getAOE() const;
	bool checkAOE() const;
	float getMPCost() const;
	//SET
	int setElement(elements::element _element);
	bool setStats(bulletStats &_stats);
	void setTimer(sf::Int32 _timer);
	void setDmg(float _val);
	void setSpeed(float _val);
	void speedMultiple(float _val);
	void setRng(float _val);
	void setAOE(float _val);
	void setType(bool _val);
	void setDmgDelay(sf::Int32 _time);
	void setMPCost(float _val);

};