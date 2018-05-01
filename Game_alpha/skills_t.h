#pragma once

#include "bullet_t.h"
#include "character_t.h"
#include "additional.h"

class skills_t
{
protected:
	character_t *genericObject;
	skillStats skillStats;

	bool active;
public:
	skills_t();
	~skills_t();

	virtual void cast();

public:
	bool getActivity() const {
		return active;
	}
};

