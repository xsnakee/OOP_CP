#pragma once

#include <SFML\Graphics.hpp>

#include "characterStats_t.h"
#include "CharacterState_t.h"
#include "physOb_t.h"
#include "skills_t.h"
#include "additional.h"

class CharacterState_t;

class character_t : public physOb_t
{

protected:
	characterStats_t stat;
	std::unique_ptr<CharacterState_t> state;

	skills_t *skill;

	sf::Int32 timer;
	sf::Int32 startTime;
	sf::Int32 cooldown;

	float frame;
	sf::Vector2f targetCoords;
	sf::Vector2f spawnCoords;

protected:

	character_t();
	character_t(float _x, float _y);
	character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	character_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height);

public:
	virtual ~character_t();

	void changeState(CharacterState_t *newState);

	void defaultStats();
	virtual void controller(sf::Event) = 0;
	virtual bool checkKeyCd(sf::Clock *clock) = 0;

	virtual bool attack(float _x, float _y) = 0;
	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType);
	bool checkCollision(physOb_t &Object, float _borderError = 0.f);
	virtual bool checkEnemy(character_t *ob);
	//virtual bool move();

	bool kill();
	void update(float _speed);
	void animation();
	void updateFrame();
	float toHit ()const;

public:

	characterStats_t getStats();

	float getFrame() const {
		return frame;
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
		return 300.f;
	}

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
};

