#include "effectSkill_t.h"



effectSkill_t::effectSkill_t()
{
	startTime = 0;
	timer = std::numeric_limits<sf::Int32>::max();

	stats.resetStats(stats);
	active = false;
}


effectSkill_t::effectSkill_t(sf::Clock *time, sf::Int32 _timer) {
	sf::Int32 _startTime = time->getElapsedTime().asMilliseconds();
	startTime = _startTime;
	timer = _timer;
	stats.resetStats(stats);
}

effectSkill_t::~effectSkill_t()
{
}

bool effectSkill_t::castSkill() {


	active = true;
	return active;
}

bool  effectSkill_t::checkTimer(sf::Clock *time) {

	sf::Int32 tempTime = time->getElapsedTime().asMilliseconds();

	active = (abs(tempTime - startTime) > timer) ? false : true;

	return active;
}