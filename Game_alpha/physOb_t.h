#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"


class physOb_t : public obPreference
{
protected:
	float posX;
	float posY;

	bool destroyble;
	bool alive;
	float hitsToDestroy;
	bool collision;

	std::vector<size_t> dropList;
public:

	physOb_t();
	physOb_t(float _posX, float _posY);	
	//physOb_t(obPreference spritePref);
	//physOb_t(float _posX, float _posY, obPreference spritePref);
	~physOb_t();
	
	//GET
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

	float gethitsToDestroy() const {
		return hitsToDestroy;
	}

	//SET
	float setPosX(float _x){
		posX = _x;
		return posX;
	}

	float setPosY(float _y){
		posY = _y;
		return posY;
	}

	bool setDestroyble(bool _d){
		destroyble = _d;
		return destroyble;
	}

	bool setAlive(bool _live){
		alive = _live;
		return alive;
	}

	bool setCollision(bool _collision){
		collision = _collision;
		return collision;
	}

	float sethitsToDestroy(float _hitsToDestroy){
		hitsToDestroy = _hitsToDestroy;
		return hitsToDestroy;
	}

};

