#include "bullet_t.h"
#include <iostream>



bullet_t::bullet_t():physOb_t()
{
}

bullet_t::bullet_t(sf::Clock *time, physOb_t *genObj, sf::Vector2f _targetCoords):physOb_t(genObj->getPosX(), genObj->getPosY()) {

	clock = time;

	sf::Int32 _startTime = clock->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = 4000;

	targetCoords = _targetCoords;\

	
	stat.speed = 0.001f;
	stat.range = 200.0f;

	stat.damage = 20.0f;
	mass = false;
	stat.AOE = 0.1f;
	stat.element = elements::NONE;
	stat.type = false;

	if (abs(stat.AOE - 1.f) < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}
	
	startPosX = posX;
	startPosY = posY;

	float distanceX = targetCoords.x - posX;
	float distanceY = targetCoords.y - posY;
	vectorLength = sqrt( pow(distanceX,2) + pow(distanceY,2));
	
	//CALC DISTANCE SPEED ERROR 
	float k = vectorLength / stat.range;
	distanceX /= k;
	distanceY /= k;

	//SET SPEED
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
	float distanceX = startPosX - posX;
	float distanceY = startPosY - posY;
	float tempVectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	
	alive = (checkTimer(clock, startTime, timer) && (tempVectorLength < stat.range) );//time is over or leave from range

	return alive;
}
