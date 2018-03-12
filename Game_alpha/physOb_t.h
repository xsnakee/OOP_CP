#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"


class physOb_t : public obPreference
{
protected:
	float posX;
	float posY;	
	float dX;
	float dY;
	bool destroyble;
	bool alive;
	float hitsToDestroy;
	bool collision;

	std::vector<int> dropList;
public:

	physOb_t();
	physOb_t(float _posX, float _posY);	
	physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	~physOb_t();
	
	void update();
	virtual bool checkCollision();
	
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

