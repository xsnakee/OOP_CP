#pragma once

#include <SFML\Graphics.hpp>

#include "characterStats_t.h"
#include "physOb_t.h"
#include "skills_t.h"

class character_t : public physOb_t
{

protected:
	characterStats_t stat;
	skills_t *skill;

	sf::Int32 timer;
	sf::Int32 startTime;
	sf::Int32 cooldown;
public:


	character_t();
	character_t(float _x, float _y);
	character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	virtual ~character_t() = 0;


	void defaultStats();
	virtual void update(float time) = 0;
	virtual void controller(sf::Event) = 0;
	virtual bool checkTimer(sf::Clock *clock);
	virtual bool checkKeyCd(sf::Clock *clock) = 0;

public:
	void setStats(characterStats_t &_stats);

	characterStats_t getStats();


};

