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

	fraction = -1;
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
	fraction = -1;
}
//*

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height) :spritePref(fileName, _coordX, _coordY, _width, _height) {
	dX = 0.f;
	dY = 0.f;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
	fraction = -1;

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
	fraction = -1;

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

bool physOb_t::checkCollision(physOb_t *Object, float _borderError) {

	float thisWidth = static_cast<float>(spritePref.getWidth())/2;
	float thisHeight = static_cast<float>(spritePref.getHeight())/2;
	float obWidth = static_cast<float>(Object->spritePref.getWidth()) / 2;
	float obHeight = static_cast<float>(Object->spritePref.getWidth()) / 2;


	float ObjectPosX = Object->getPosX();
	float ObjectPosY = Object->getPosY();

	float obCenterX = ObjectPosX + obWidth;
	float obCenterY = ObjectPosY + obHeight;

	float thisCenterX = posX + thisWidth;
	float thisCenterY = posY + thisHeight;


	float ObjectLeftBorder = ObjectPosX - thisWidth;
	float ObjectTopBorder = ObjectPosY - thisHeight;
	float ObjectRightBorder = ObjectPosX + static_cast<float>(Object->spritePref.getWidth());
	float ObjectBottomBorder = ObjectPosY + static_cast<float>(Object->spritePref.getHeight()) - (thisHeight / 2);
	//*

	if ((abs(obCenterX - thisCenterX) < (thisWidth + obWidth)) && (abs(obCenterY - thisCenterY) < (thisHeight + obHeight))){
		return true;
	}
	//*/
	return false;
}

void physOb_t::collisionHandler(physOb_t *Object, float _speed, float _borderError) {
	if (collision && Object->collision) {
		
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



bool physOb_t::checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

bool physOb_t::checkAlive() {
	return true;
}