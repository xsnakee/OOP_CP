#pragma once

#include <SFML\Graphics.hpp>
#include "skills_t.h"
#include "character_t.h"
#include "physOb_t.h"

class effectSkill_t: public skills_t
{

public:
	effectSkill_t();
	~effectSkill_t();
public:
	virtual void cast();
	virtual bool checkEffectTimer();
	bool checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time);

public:
};

