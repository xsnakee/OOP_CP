#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "characterStats_t.h"
#include "physOb_t.h"

class character_t : public physOb_t
{
protected:
	float dX;
	float dY;
	characterStats_t stat;

public:
	character_t();
	character_t(float _x, float _y);
	virtual ~character_t() = 0;

	//GET
	float getdX() const {
		return dX;
	}

	float getdY() const {
		return dY;
	}

	//SET
	float setdX(float _x) {
		dX = _x;
		return dX;
	}

	float setdY(float _y) {
		dY = _y;
		return dY;
	}
};

