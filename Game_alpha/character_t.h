#pragma once

#include <SFML\Graphics.hpp>

#include <list>
#include <numeric>
#include "characterStats_t.h"
#include "CharacterState_t.h"
#include "characterTimers_t.h"
#include "physOb_t.h"
#include "additional.h"
#include "skillObGenerator_t.h"

class CharacterState_t;
class skillObGenerator_t;

class character_t : public physOb_t
{

protected:
	characterStats_t stat;
	std::unique_ptr<CharacterState_t> state;

	std::list<elements::element> skillGeneratorArr;
	size_t elemStatus;
	std::unique_ptr<skillObGenerator_t> skill;

	sf::Clock *clock;
	characterTimers_t timer;

	sf::Vector2f targetCoords;
	sf::Vector2f spawnCoords;



	float moveRadius;
	virtual void animation();

protected:

	character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	character_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock);

public:
	virtual ~character_t();

	void changeState(CharacterState_t *newState);

	void defaultStats();

	virtual void attack();

	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType);
	bool checkCollision(physOb_t &Object, float _borderError = 0.f);
	virtual bool checkEnemy(character_t *ob);


	virtual bool checkSkillGenerator();
	virtual bool addElement(elements::element _elem);
	virtual void generateSkillAndClearElemList();



	bool kill();
	void update(float _speed);
	float toHit ()const;

public:
	//GET
	characterStats_t &getStats();

	character_t *getPtr() {
		return this;
	}

	sf::Vector2f getTargetCoords() const {
		return targetCoords;
	}

	sf::Vector2f getSpotCoords() const {
		return sf::Vector2f(1800.f,1800.f);
	}

	sf::Vector2f getSpawnCoords() const {
		return spawnCoords;
	}


	float getMoveRadius() const {
		return moveRadius;
	}
	sf::Clock *getClockPtr() const {
		return clock;
	}


	size_t getElemStatus() const {
		return elemStatus;
	}

	characterTimers_t &getTimers() {
		return timer;
	}
	//SET
	float setFrame(float _frame) {
		frame = _frame;
		return frame;
	}
	sf::Vector2f setTargetCoords(sf::Vector2f _targetCoords) {
		targetCoords = _targetCoords;
		return targetCoords;
	}
	
	CharacterState_t *getState() const {
		return state.get();
	}

	void setStats(characterStats_t &_stats);

	size_t setElemStatus(size_t _elemStatus) {
		elemStatus = _elemStatus;
		return elemStatus;
	}

	void setMoveRadius(float _radius) {
		moveRadius = _radius;
	}
};

