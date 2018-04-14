#include "bullet_t.h"



bullet_t::bullet_t():physOb_t()
{
}

bullet_t::bullet_t(float _posX, float _posY, float _speed,  elements::element _element, float _AOE) : physOb_t(_posX,_posY)
{
	startTime = 0.f;
	timer = std::numeric_limits<float>::max();

	stat.range = 50.f;
	stat.speed = _speed;
	stat.AOE = _AOE;

	stat.element = _element;

	if (abs(stat.AOE - 1.f) < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}

	spritePref.setSpritePos(posX, posY);
}

bullet_t::bullet_t(sf::Clock *time, float _timer, float _posX, float _posY, float _speed, elements::element _element, float _AOE = 1.f) : physOb_t(_posX, _posY) {

	sf::Int32 _startTime = time->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = _timer;

	stat.range = 50.f;
	stat.speed = _speed;
	stat.AOE = _AOE;

	stat.element = _element;

	if (abs(stat.AOE - 1.f) < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}
	spritePref.setSpritePos(posX, posY);
}

bullet_t::~bullet_t()
{
}


bool bullet_t::checkTimer(sf::Clock *time) {

	sf::Int32 tempTime = time->getElapsedTime().asMilliseconds();

	alive = (abs(tempTime - startTime) > timer) ? false : true;

	return alive;
}
