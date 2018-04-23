#pragma once

#include "bullet_t.h"

class skills_t
{
protected:
	bool active;
public:
	skills_t();
	~skills_t();

public:
	bool getActivity() const {
		return active;
	}
};

