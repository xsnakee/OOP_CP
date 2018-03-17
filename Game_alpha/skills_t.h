#pragma once

#include "bullet_t.h"
#include "game_t.h"

class skills_t
{
protected:
	//game_t *gameEngine;
	bool active;
public:
	skills_t();
	//skills_t(game_t &gameEngine);
	~skills_t();
	virtual bool castSkill() = 0;

public:
	bool getActivity() const {
		return active;
	}
};

