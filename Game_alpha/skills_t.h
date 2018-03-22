#pragma once

#include "bullet_t.h"

class skills_t
{
protected:
	bool active;
public:
	skills_t();
	~skills_t();
	virtual bool castSkill(sf::Clock *time, sf::Int32 _timer)=0;

public:
	bool getActivity() const {
		return active;
	}
};

