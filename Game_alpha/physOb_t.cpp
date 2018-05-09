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
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	spritePref.setSpritePos(posX, posY);

	fraction = -1;
}

physOb_t::physOb_t(float _posX, float _posY) {
	dX = 0.f;
	dY = 0.f;
	posX = _posX;
	posY = _posY;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	spritePref.setSpritePos(posX, posY);
	fraction = -1;
}

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height) :spritePref(fileName, _coordX, _coordY, _width, _height) {
	dX = 0.f;
	dY = 0.f;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	fraction = -1;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);

}

physOb_t::physOb_t(float _posX, float _posY, std::shared_ptr<sf::Texture>_texture, int _coordX, int _coordY, int _width, int _height) : spritePref(_texture, _coordX, _coordY, _width, _height) {

	dX = 0.f;
	dY = 0.f;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	fraction = -1;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);
}


physOb_t::~physOb_t()
{
}

bool physOb_t::kill() {
	alive = false;
	return alive;
}

void physOb_t::update(float _speed) {

	if (alive) {


		if ((dX > 0) && (abs(dY) < FLT_EPSILON)) {
			direction = animation::RIGHT;
		}
		else if ((dX < 0) && (abs(dY) < FLT_EPSILON)) {

			direction = animation::LEFT;
		}
		else if ((dY > 0) && (abs(dX) < FLT_EPSILON)) {

			direction = animation::BOTTOM;
		}
		else if ((dY < 0) && (abs(dX) < FLT_EPSILON)) {
			direction = animation::TOP;
		}


		posX += dX * _speed;
		posY += dY * _speed;

		dX = 0.f;
		dY = 0.f;

		spritePref.setSpritePos(posX, posY);
		updateFrame();
		animation();
	}

}

bool physOb_t::checkCollision(physOb_t &Object, float _borderError) {

	float thisWidth = static_cast<float>(spritePref.getWidth()) / 2;
	float thisHeight = static_cast<float>(spritePref.getHeight()) / 2;
	float obWidth = static_cast<float>(Object.getWidth()) / 2;
	float obHeight = static_cast<float>(Object.getHeight()) / 2;

	float obCenterX = Object.getPosX() + obWidth;
	float obCenterY = Object.getPosY() + obHeight;

	float thisCenterX = posX + thisWidth;
	float thisCenterY = posY + thisHeight;

	if ((abs(obCenterX - thisCenterX) < (thisWidth + obWidth - _borderError)) && (abs(obCenterY - thisCenterY) < (thisHeight + obHeight - _borderError))){
		return true;
	}
	
	return false;
}

bool physOb_t::collisionHandler(physOb_t &Object, float _speed, float _borderError) {
	
	if (collision && Object.collision) {
		float zero = std::numeric_limits<float>::epsilon();
		float speedX = abs(dX) * _speed;
		float speedY = abs(dY) * _speed;
		
		if (direction == animation::RIGHT) {
			posX = Object.getPosX() - getWidth() - _borderError;
		} else if (direction == animation::LEFT) {
			posX = Object.getPosX() + Object.getWidth() + _borderError;
		} else if (direction == animation::BOTTOM) {
			posY = Object.getPosY() - getHeight() - _borderError;
		} else if (direction == animation::TOP) {
			posY = Object.getPosY() + Object.getHeight()/2;
		}
		
		/*
		if (direction == animation::RIGHT) {
			posX -= Object.getdX() * _speed + _borderError;
		}
		else if (direction == animation::LEFT) {
			posX += Object.getdX() * _speed + _borderError;
		}
		else if (direction == animation::BOTTOM) {
			posY -= Object.getdY() * _speed + _borderError;
		}
		else if (direction == animation::TOP) {
			posY += Object.getdY() * _speed + _borderError;
		}
		*/
		dX = 0;
		dY = 0;
		return true;
	}
	return false;
}



bool physOb_t::checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

bool physOb_t::checkAlive() {
	if (alive) {
		alive = (hitsToDestroy > 0) ? true : false;
	}
	return alive;
}

float physOb_t::takeDamage(float _dmg, bool _dmgType, elements::element _elem) {
	if (alive) {
		
			--hitsToDestroy;
		
	}
	return _dmg;
}

float physOb_t::takeHeal(float _heal) {
	if (alive) {
		++hitsToDestroy;
	}
	return _heal;
}


void physOb_t::updateFrame() {

	frame += animation::frameSpeed;
	if (frame > animation::frameRate) {
		frame -= animation::frameRate;
	}
}
void physOb_t::animation() {

}
