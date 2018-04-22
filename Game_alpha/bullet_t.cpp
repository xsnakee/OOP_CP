#include "bullet_t.h"
#include <iostream>



bullet_t::bullet_t():physOb_t()
{
}

bullet_t::bullet_t(sf::Clock *time, physOb_t *genObj, sf::Vector2f _targetCoords):physOb_t(genObj->getPosX(), genObj->getPosY()) {

	genericObject = genObj;
	fraction = genObj->getFraction();
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

	if (stat.AOE < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}
	
	startPosX = posX;
	startPosY = posY;

	float distanceX = targetCoords.x - posX;
	float distanceY = targetCoords.y - posY;
	float rotation = -(atan2(distanceX, distanceY)) * 180 / 3.14159265;
	spritePref.setCenterWithOrigin();
	spritePref.setRotation(rotation);

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
	if (alive) {
		float distanceX = startPosX - posX;
		float distanceY = startPosY - posY;
		float tempVectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

		alive = (checkTimer(clock, startTime, timer) && (tempVectorLength < stat.range));//time is over or leave from range
	}
	

	return alive;
}

bool bullet_t::collisionHandler(physOb_t *Object, float _speed, float _borderError) {
	if (Object->getCollision() && Object->getFraction() != fraction && Object->getDestroyble()) {
		std::cout << stat.damage << std::endl;
		
			Object->takeDamage(stat.damage, stat.type);

			alive = false;
		
			return true;
	}
	return false;

}