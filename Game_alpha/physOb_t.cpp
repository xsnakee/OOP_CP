#include "physOb_t.h"

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

	float thisWidth = static_cast<float>(spritePref.getWdith());
	float thisHeight = static_cast<float>(spritePref.getHeight());


	float ObjectLeftBorder = static_cast<float>(Object->getPosX() - thisWidth);
	float ObjectTopBorder = static_cast<float>(Object->getPosY() - thisHeight);
	float ObjectRightBorder = ObjectLeftBorder + static_cast<float>(Object->spritePref.getWdith());
	float ObjectBottomBorder = ObjectTopBorder + static_cast<float>(Object->spritePref.getHeight());

	if ((posX >= ObjectLeftBorder) && (posX <= ObjectRightBorder) && (posY >= ObjectTopBorder) && (posY <= ObjectBottomBorder)) {
		return true;
	}

	return false;
}

void physOb_t::collisionHandler(physOb_t *Object) {
	if (checkCollision(Object) && Object->collision) {

		float thisWidth = static_cast<float>(spritePref.getWdith());
		float thisHeight = static_cast<float>(spritePref.getHeight());
		
		switch (direction) {
		case animation::TOP: {
			//posY = static_cast<float>(Object->getPosY() + thisHeight);
			dY = .0f;
		}
		case animation::BOTTOM:{
			//posY = static_cast<float>(Object->getPosY() - 1);
			dY = .0f;
		}

		case animation::LEFT: {
			//posX = static_cast<float>(Object->getPosX() + 1);
			dX = .0f;
		}
		
		case animation::RIGHT: {
			//posX = static_cast<float>(Object->getPosX() - thisWidth);
			dX = .0f;
		}
		}
	}
}


bool physOb_t::checkTimer(sf::Clock *time) {
	return true;
}