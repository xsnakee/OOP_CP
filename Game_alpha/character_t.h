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
#include "Effect_t.h"

class CharacterState_t;
class skillObGenerator_t;
class Effect_t;

class character_t : public physOb_t
{

protected:
	characterStats_t stat;
	std::unique_ptr<CharacterState_t> state;
	std::unique_ptr<Effect_t> buff;

	std::list<elements::element> skillGeneratorArr;
	size_t elemStatus;
	std::unique_ptr<skillObGenerator_t> skill;

	sf::Clock *clock;
	characterTimers_t timer;

	sf::Vector2f targetPos;
	sf::Vector2f spawnCoords;

	float moveRadius;
	virtual void animation();

protected:

	character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	character_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock);
public:
	virtual ~character_t();

	void changeState(CharacterState_t *newState);
	void changeEffect(Effect_t *newEffect);

	void defaultStats();
	void defaultAllStats();
	virtual void attack();
	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType, elements::element _elem);
	float takeHeal(float _heal);

	bool checkCollision(physOb_t &Object);
	virtual bool checkEnemy(character_t *ob);


	virtual bool checkSkillGenerator();
	virtual bool addElement(elements::element _elem);
	virtual void generateSkillAndClearElemList();
	virtual void resetElemsList();
	virtual size_t setElemStatus(size_t _elemStatus);
	virtual std::vector<size_t> getSkillList();
	virtual void setSkills(std::initializer_list<size_t> _skillList);
	void useMP(float _mp);
	bool kill();
	void update(float _speed);
	float toHit ()const;
	void updateTimerDependenceStats();
public:
	//GET	
	Effect_t *getEffectPtr();
	characterStats_t &getStats();
	character_t *getPtr();
	sf::Vector2f getTargetPos();
	sf::Vector2f getSpotCoords();
	sf::Vector2f getSpawnCoords();
	float getMoveRadius() const;
	sf::Clock *getClockPtr()const;
	size_t getElemStatus()const;
	characterTimers_t &getTimer();
	std::list<elements::element> getElements();
	skillObGenerator_t *getSkillGeneratorPtr();
	float getComputedDmg()const;
	CharacterState_t *getState()const;
	//SET
	float setFrame(float _frame);
	sf::Vector2f setTargetPos(sf::Vector2f _targetPos);
	void setStats(characterStats_t &_stats);
	void setMoveRadius(float _radius);
};

