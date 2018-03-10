#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "characterStats_t.h"
#include "obPreference.h"

class character_t : public obPreference_t
{
protected:
	bool alive;
	bool godMode;
	//characterStats_t stat;

public:
	character_t();
	~character_t();
};

