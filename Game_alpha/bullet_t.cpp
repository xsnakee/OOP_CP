#include "bullet_t.h"

bullet_t::bullet_t() :physOb_t()
{
}


bullet_t::bullet_t(sf::Clock *time, character_t *genObj, sf::Vector2f _targetPos) : physOb_t(genObj->getPosOfCenter().x, genObj->getPosOfCenter().y) {

	genericObject = genObj;
	fraction = genObj->getFraction();
	clock = time;

	sf::Int32 _startTime = clock->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = 4000;

	targetPos = _targetPos;
	stat.range = genericObject->getStats().attackRange;
	stat.damage = genericObject->getStats().attackPower;

	float speed = 15.f;
	stat.speed = speed / stat.range;


	stat.AOE = 0.f;
	stat.element = elements::NONE;
	stat.type = true;

	if (abs(stat.AOE) < FLT_EPSILON) {
		mass = false;
	}
	else {
		mass = true;
	}
	dmgInterval = timer;

	startPosX = posX;
	startPosY = posY;


	//CALC SPEED
	float distanceX = targetPos.x - posX;
	float distanceY = targetPos.y - posY;
	float rotation = (atan2(distanceY, distanceX)) * 180.f / 3.14159265f;

	spritePref.setOriginToCenter();
	spritePref.setRotation(rotation);


	vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2)) + spritePref.getTexture().getSize().x;

	//CALC DISTANCE SPEED ERROR 
	float k = vectorLength / stat.range;
	distanceX /= k * 100;
	distanceY /= k * 100;

	//SET SPEED
	dX = distanceX * stat.speed;
	dY = distanceY * stat.speed;
}

bullet_t::~bullet_t()
{
}

void bullet_t::update(float _speed) {
	if (alive) {
		checkAlive();
		posX += dX * _speed;
		posY += dY * _speed;
		updateFrame();
		animation();
		spritePref.setSpritePos(posX, posY);
	}

}

bool bullet_t::checkAlive() {
	if (alive) {
		float distanceX = startPosX - posX;
		float distanceY = startPosY - posY;
		float tempVectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
		float minRange = 0.5;

		alive = (checkTimer(clock, startTime, timer) && (tempVectorLength < stat.range));//time is over or leave from range //  abs(tempVectorLength - stat.range) < (minRange))
	}


	return alive;
}

bool bullet_t::hitting(physOb_t &Object, float _speed, float _borderError) {
	
		if (stat.type && Object.getFraction() != fraction) {
			Object.takeDamage(stat.damage, stat.type, stat.element);
			if (collision) {
				alive = false;
			}
		}
		else if (!stat.type && Object.getFraction() == fraction) {
			Object.takeHeal(stat.damage);
		}
	
	return true;
}

bool bullet_t::collisionHandler(physOb_t &Object, float _speed, float _borderError) {
	dmgInterval_t &temp = checkObInList(Object);//if ob exist startDmgTime != 0

	if (temp.startDmgTime) {
		if (!checkTimer(clock, temp.startDmgTime, dmgInterval)){
			temp.startDmgTime = clock->getElapsedTime().asMilliseconds();
			hitting(Object, _speed, _borderError);
		}
		
	} else {

		if (Object.getDestroyble()) {

			temp.startDmgTime = clock->getElapsedTime().asMilliseconds();
			obList.push_back(temp);
			hitting(Object, _speed, _borderError);

			return true;
		}
	}
	
	return false;

}

void bullet_t::updateFrame() {
	float AnimationSpeedMultiple = 3.f;
	frame += animation::frameSpeed * AnimationSpeedMultiple;
	if (frame > animation::frameRate) {
		frame -= animation::frameRate;
	}
}
void bullet_t::animation() {


	int spriteCoordX = static_cast<int>(frame) * getWidth();

	spritePref.setTexturePos(spriteCoordX, spritePref.getCoordY());
}


dmgInterval_t &bullet_t::checkObInList(physOb_t &Object) {
	dmgInterval_t temp(Object);

	for (auto &i : obList) {
		if (Object.getPtr() == i.ob.getPtr()) {
			return i;
		}
	}

	return temp;
}
