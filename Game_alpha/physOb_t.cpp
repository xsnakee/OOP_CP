#include "physOb_t.h"

physOb_t::physOb_t()
{
	posX = 0;
	posY = 0;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
	sprite.setPosition(posX, posY);
}

physOb_t::physOb_t(float _posX, float _posY):posX(_posX), posY(_posY) {
	posX = _posX;
	posY = _posY;
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
	sprite.setPosition(posX, posY);
}
//*

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height):obPreference(fileName, _coordX, _coordY, _width, _height) {
	
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;

	posX = _posX;
	posY = _posY;

	sprite.setPosition(posX, posY);

}
//*/
physOb_t::~physOb_t()
{
}



void physOb_t::update() {

	if (!alive) {

	}
}

bool physOb_t::checkCollision() {
	//sprite.
	return true;
}