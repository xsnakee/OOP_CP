#include "physOb_t.h"
#include <iostream>

bool equal(float &a, float &b) {

	return (abs(a - b) < std::numeric_limits<float>::epsilon()) ? true : false;
}

bool inInterval(float &x, float a, float b) {
	return (x > a && x < b) ? true : false;
}
physOb_t::physOb_t()
{
	dX = 0.f;
	dY = 0.f;
	posX = 0;
	posY = 0;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
	spritePref.setSpritePos(posX, posY);
}

physOb_t::physOb_t(float _posX, float _posY) {
	dX = 0.f;
	dY = 0.f;
	posX = _posX;
	posY = _posY;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
	spritePref.setSpritePos(posX, posY);
}
//*

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height) :spritePref(fileName, _coordX, _coordY, _width, _height) {
	dX = 0.f;
	dY = 0.f;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);

}

physOb_t::physOb_t(float _posX, float _posY, sf::Texture *_texture, int _coordX, int _coordY, int _width, int _height) : spritePref(_texture, _coordX, _coordY, _width, _height) {
	dX = 0.f;
	dY = 0.f;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);
}
//*/
physOb_t::~physOb_t()
{
}

bool physOb_t::kill() {
	alive = false;
	return alive;
}

void physOb_t::update(float _speed) {

	if (alive) {


		posX += dX * _speed;
		posY += dY * _speed;

		dX = 0.f;
		dY = 0.f;

		spritePref.setSpritePos(posX, posY);
	}
}

bool physOb_t::checkCollision(physOb_t *Object, float _borderError = 0.f) {

	float thisWidth = static_cast<float>(spritePref.getWidth());
	float thisHeight = static_cast<float>(spritePref.getHeight());

	float ObjectPosX = Object->getPosX();
	float ObjectPosY = Object->getPosY();

	float ObjectLeftBorder = ObjectPosX - thisWidth;
	float ObjectTopBorder = ObjectPosY - thisHeight;
	float ObjectRightBorder = ObjectPosX + static_cast<float>(Object->spritePref.getWidth());
	float ObjectBottomBorder = ObjectPosY + static_cast<float>(Object->spritePref.getHeight()) - (thisHeight / 2);
	//*
	if ( (posX > ObjectLeftBorder + _borderError) && (posX < ObjectRightBorder - _borderError) && (posY > ObjectTopBorder + _borderError) && (posY < ObjectBottomBorder - _borderError) ) {//  //
		return true;
	}
	//*/
	/*
	if ((posX > ObjectLeftBorder) && (posX < ObjectRightBorder) &&
		(posY > ObjectTopBorder) && (posY < ObjectBottomBorder)) {//  //
		return true;
	}
	//*/
	return false;
}

void physOb_t::collisionHandler(physOb_t *Object, float _speed, float _borderError) {
	if (checkCollision(Object, _borderError) && Object->collision) {
		
		float zero = std::numeric_limits<float>::epsilon();
		float speedX = abs(dX) * _speed;
		float speedY = abs(dY) * _speed;

		float errorVal = 1.0f + _borderError;
		
		

		if (dX > 0) {

			std::cout << 1 << std::endl;
			posX -= speedX  + errorVal;
		}
		else if (dX < 0) {

			std::cout << 2 << std::endl;
			posX += speedX + errorVal;
		}

		if (dY > 0) {

			std::cout << 3 << std::endl;
			posY -= speedY + errorVal;

		}
		else if (dY < 0) {

			std::cout << 4 << std::endl;
			posY += speedY + errorVal;
		}

		dX = 0;
		dY = 0;
	}

	}



bool physOb_t::checkTimer(sf::Clock *time) {
	return true;
}