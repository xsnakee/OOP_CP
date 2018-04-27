#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"
#include "additional.h"

class physOb_t
{
protected:
	obPreference spritePref;

	float posX;
	float posY;
	float dX;
	float dY;
	bool destroyble;
	bool alive;
	int hitsToDestroy;
	bool collision;

	int fraction;
	animation::direction direction;

	std::vector<int> dropList;

public:

	physOb_t();
	physOb_t(float _posX, float _posY);	
	physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	physOb_t(float _posX, float _posY, sf::Texture *_texture,  int _coordX, int _coordY, int _width, int _height);

	virtual ~physOb_t();
	
	virtual bool kill();
	virtual void update(float _speed);
	bool checkCollision(physOb_t &Object, float _borderError = 0.f);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 1.f);

	virtual bool checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time);
	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType);
	//GET
	sf::Sprite getSprite() const {
		return spritePref.getSprite();
	}
	int getWidth() const {
		return spritePref.getWidth();
	}
	int getHeight()const {
		return spritePref.getHeight();
	}
	int getFraction() const {
		return fraction;
	}

	float getdX() const {
		return dX;
	}

	float getdY() const {
		return dY;
	}

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

	int gethitsToDestroy() const {
		return hitsToDestroy;
	}

	virtual sf::Int32 getStartTime() const {
		return 0;
	}
	virtual sf::Int32 getTimer()const {
		return std::numeric_limits<sf::Int32>::max();
	}

	sf::Vector2f getCoords() const {	
		return sf::Vector2f (posX, posY);
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
	int setFraction(int _fract) {
		fraction = _fract;
		return fraction;
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

	int sethitsToDestroy(int _hitsToDestroy){
		hitsToDestroy = _hitsToDestroy;
		return hitsToDestroy;
	}

	float setdX(float _x) {
		dX = _x;
		return dX;
	}

	float setdY(float _y) {
		dY = _y;
		return dY;
	}
};

