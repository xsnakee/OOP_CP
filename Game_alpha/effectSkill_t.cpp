#include "effectSkill_t.h"



effectSkill_t::effectSkill_t()
{
	startTime = 0;
	timer = std::numeric_limits<sf::Int32>::max();
	active = false;
}
effectSkill_t::~effectSkill_t()
{
}

void effectSkill_t::cast() {
	skills_t::cast();
	startTime = genericObject->getClockPtr()->getElapsedTime().asMilliseconds();;
	active = true;
}



bool effectSkill_t:: checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

bool effectSkill_t::checkEffectTimer() {
	if (!active) {
		if (checkTimer(clock, startTime, timer)) {
			return false;
		}
	}

	return true;
}