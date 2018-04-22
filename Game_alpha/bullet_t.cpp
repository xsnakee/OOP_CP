#include "bullet_t.h"



bullet_t::bullet_t():physOb_t()
{
}
/*
bullet_t::bullet_t(float _posX, float _posY, float _speed,  elements::element _element, float _AOE, sf::Vector2f _targetCoords) : physOb_t(_posX,_posY)
{
	clock = nullptr;

	startTime = 0.f;
	timer = std::numeric_limits<float>::max();
	targetCoords = _targetCoords;

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

	passedDistance = stat.range;
	spritePref.setSpritePos(posX, posY);
}
*/
/*
bullet_t::bullet_t(sf::Clock *time, float _timer, float _posX, float _posY, float _speed, elements::element _element, sf::Vector2f _targetCoords, float _AOE = 1.f) : physOb_t(_posX, _posY) {

	clock = time;
	sf::Int32 _startTime = time->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = _timer;

	targetCoords = _targetCoords;

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

	passedDistance = stat.range;

	spritePref.setSpritePos(posX, posY);
}
*/

bullet_t::bullet_t(sf::Clock *time, physOb_t *genObj, sf::Vector2f _targetCoords):physOb_t(genObj->getPosX(), genObj->getPosY()) {

	clock = time;

	sf::Int32 _startTime = clock->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = 1000;

	targetCoords = _targetCoords;

	//characterStats_t tempStats = genObj->getStats();

	//stat.range = tempStats.attackRange;
	//stat.damage = tempStats.atackPower;


	stat.range = 250.0f;
	stat.damage = 20.0f;
	stat.speed = 0.0005f;
	mass = false;
	stat.AOE = 0.1f;
	stat.element = elements::NONE;
	stat.type = false;

	float distanceX = targetCoords.x - posX;
	float distanceY = targetCoords.y - posY;

	vectorLength = sqrt( pow(distanceX,2) + pow(distanceY,2));

	dX = distanceX * stat.speed;
	dY = distanceY * stat.speed;
}


bullet_t::~bullet_t()
{
}

void bullet_t::update(float _speed) {
	if (alive){
		posX += dX * _speed;
		posY += dY * _speed;
		spritePref.setSpritePos(posX, posY);
	}
}

bool bullet_t::checkAlive() {

	float distanceX = targetCoords.x - posX;
	float distanceY = targetCoords.y - posY;
	float tempVectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	alive = (checkTimer(clock, startTime, timer) && (abs(vectorLength - tempVectorLength) < stat.range) );
	return alive;
}
