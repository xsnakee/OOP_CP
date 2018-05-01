#pragma once

#include "bullet_t.h"
#include "character_t.h"
#include "additional.h"

class skills_t
{
protected:
	character_t *genericObject;
	skillStats skillStats;
	float mpCost;

	sf::Clock *clock;
	sf::Int32 startTime;
	sf::Int32 timer; //live time as Milliseconds

	bool active;

public:
	skills_t();
	skills_t(character_t *genericCharacter);
	~skills_t();

	virtual void cast();

public:
	bool getActivity() const {
		return active;
	}
};

