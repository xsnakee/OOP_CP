#pragma once

#include <SFML\Graphics.hpp>
#include "skills_t.h"
#include "character_t.h"

class effectSkill_t: public skills_t
{
private:
	
	character_t * target;
	characterStats_t stats;

	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds

public:
	effectSkill_t();
	effectSkill_t(sf::Clock *time, sf::Int32 _timer = 10);
	~effectSkill_t();

public:
	virtual bool castSkill(); 
	virtual bool checkTimer(sf::Clock *time);

public:

	characterStats_t getStats() const {
		return stats;
	}
};

