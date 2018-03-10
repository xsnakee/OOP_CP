#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"


class physOb_t : public obPreference_t
{
protected:
	float posX;
	float posY;

	bool destroyble;
	bool alive;
	float HP;
	bool collision;
public:

	physOb_t();
	physOb_t(float _posX, float _posY);
	
	physOb_t(obPreference_t spritePref);
	~physOb_t();

	float getPosX() const {
		return posX;
	}

	float getPosY() const {
		return posY;
	}

	bool getDestroyble() const {
		return destroyble;
	}

	bool getAlive() const {
		return alive;
	}

	bool getCollision() const {
		return collision;
	}

	float getHP() const {
		return HP;
	}
};

