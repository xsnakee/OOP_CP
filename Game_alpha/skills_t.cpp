#include "skills_t.h"


skills_t::skills_t()
{
	clock = genericObject->getClockPtr();
	startTime = clock->getElapsedTime().asMilliseconds();
	timer = 4000;
	mpCost = 1.f;
}

skills_t::skills_t(character_t *_genericCharacter)
{
	genericObject = _genericCharacter;
	active = false;

	skillStats.speed = 0.1f;
	skillStats.range = genericObject->getStats().attackRange;
	float dmgRand = getRand(-genericObject->getStats().damageRand, genericObject->getStats().damageRand);
	skillStats.damage = genericObject->getStats().attackPower + dmgRand;
	skillStats.AOE = 0.f;
	skillStats.element = elements::NONE;
	skillStats.type = false;
	
	clock = genericObject->getClockPtr();
	startTime = clock->getElapsedTime().asMilliseconds();
	timer = 4000;
}

skills_t::~skills_t()
{
}



void skills_t::cast() {
	if (genericObject->getStats().MP > FLT_EPSILON) {
		genericObject->getStats().MP -= mpCost;
	}
	else {
		delete this;
	}
}