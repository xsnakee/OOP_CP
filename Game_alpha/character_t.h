#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "characterStats_t.h"
#include "physOb_t.h"
#include "skills_t.h"

class character_t : public physOb_t
{

protected:
	characterStats_t stat;
	skills_t *skill;
public:


	character_t();
	character_t(float _x, float _y);
	character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	virtual ~character_t() = 0;


	void defaultStats();
	virtual void update(float time) = 0;
	virtual void controller(sf::Event) = 0;

public:
	void setStats(characterStats_t &_stats);

	characterStats_t getStats();


};

