#include "bullet_t.h"

bullet_t::bullet_t():physOb_t()
{
}

bullet_t::bullet_t(bullet_t &bullet)
{

}

bullet_t::bullet_t(sf::Clock *time, character_t *genObj, sf::Vector2f _targetCoords) : physOb_t(genObj->getCoordsOfCenter().x, genObj->getCoordsOfCenter().y) {


	genericObject = genObj;
	fraction = genObj->getFraction();
	clock = time;

	sf::Int32 _startTime = clock->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = 4000;

	targetCoords = _targetCoords; 

	stat.speed = 0.1f;
	stat.range = 200.0f;

	stat.damage = getRand(-5.f, 5.f);// 20.0f;
	stat.AOE = 0.f;
	stat.element = elements::NONE;
	stat.type = false;

	if (abs(stat.AOE) < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}

	startPosX = posX;
	startPosY = posY;


	//CALC SPEED
	float distanceX = targetCoords.x - posX;
	float distanceY = targetCoords.y - posY;
	float rotation = -(atan2(distanceX, distanceY)) * 180.f / 3.14159265f;

	spritePref.setCenterWithOrigin();
	spritePref.setRotation(rotation);

	vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	//CALC DISTANCE SPEED ERROR 
	float k = vectorLength / stat.range;
	distanceX /= k*100;
	distanceY /= k*100;

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

bool bullet_t::collisionHandler(physOb_t &Object, float _speed, float _borderError) {
	if (Object.getCollision() && Object.getFraction() != fraction) {
		
		if (Object.getDestroyble()) {
			Object.takeDamage(stat.damage, stat.type);
		}
		if (!mass) {
			alive = false;
		}
		
			return true;
	}
	return false;

}