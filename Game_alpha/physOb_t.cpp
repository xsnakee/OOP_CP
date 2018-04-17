#include "physOb_t.h"

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

physOb_t::physOb_t(float _posX, float _posY){
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

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height):spritePref(fileName, _coordX, _coordY, _width, _height) {
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

bool physOb_t::checkCollision(physOb_t *Object) {	

	float thisWidth = static_cast<float>(spritePref.getWidth());
	float thisHeight = static_cast<float>(spritePref.getHeight());

	float ObjectPosX = Object->getPosX();
	float ObjectPosY = Object->getPosY();

	float ObjectLeftBorder = ObjectPosX - thisWidth;
	float ObjectTopBorder = ObjectPosY - thisHeight;
	float ObjectRightBorder = ObjectPosX + static_cast<float>(Object->spritePref.getWidth());
	float ObjectBottomBorder = ObjectPosY + static_cast<float>(Object->spritePref.getHeight()) - (thisHeight / 2);
	/*
	if ((posX > ObjectLeftBorder || equal(posX, ObjectLeftBorder)) && (posX < ObjectRightBorder || equal(posX, ObjectRightBorder)) && 
		(posY > ObjectTopBorder || equal(posY, ObjectTopBorder)) && (posY < ObjectBottomBorder || equal(posY, ObjectBottomBorder))) {//  //
		return true;
	}
	*/

	if ((posX > ObjectLeftBorder) && (posX < ObjectRightBorder) &&
		(posY > ObjectTopBorder) && (posY < ObjectBottomBorder)) {//  //
		return true;
	}
	return false;
}

void physOb_t::collisionHandler(physOb_t *Object, float _speed) {
	if (checkCollision(Object) && Object->collision) {

		float thisWidth = static_cast<float>(spritePref.getWidth());
		float thisHeight = static_cast<float>(spritePref.getHeight());

		float ObjectWidth = static_cast<float>(Object->spritePref.getWidth());
		float ObjectHeight = static_cast<float>(Object->spritePref.getHeight());

		float ObjectPosX = Object->getPosX();
		float ObjectPosY = Object->getPosY();

		float ObCenterPosX = ObjectPosX + ObjectWidth / 2;
		float ObCenterPosY = ObjectPosY + ObjectHeight / 2;

		float ObjectLeftBorder = ObjectPosX - thisWidth - 1.1f;
		float ObjectTopBorder = ObjectPosY - thisHeight - 1.1F;
		float ObjectRightBorder = ObjectPosX + ObjectWidth + 1.1f;
		float ObjectBottomBorder = ObjectPosY + ObjectHeight - (thisHeight / 2) + 1.1f;

		
		//*
		
			if (dY > 0) {
				posY = ObjectTopBorder;
				dX = 0;
			}
			if (dY < 0) {
				posY = ObjectBottomBorder;
				dX = 0;
			}
			if (dX > 0) {
				posX = ObjectLeftBorder;

			}
			if (dX < 0) {
				posX = ObjectRightBorder;
			}
		
		//*/
			 
		 //*/
	

	}
}


bool physOb_t::checkTimer(sf::Clock *time) {
	return true;
}