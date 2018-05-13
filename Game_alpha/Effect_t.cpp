#include "Effect_t.h"
#include <iostream>


Effect_t::Effect_t(character_t *_character,characterStats_t _stats, sf::Int32 _duration)
{
	character = _character;
	stat = _stats;
	duration = _duration;
	startTime = 0;
	activity = false;
}


Effect_t::~Effect_t()
{
	cancelEffect();
}


void Effect_t::useEffect() {
	startTime = character->getClockPtr()->getElapsedTime().asMilliseconds();
	character->getStats().upStat(stat);
	character->updateTimerDependenceStats();
	activity = true;
}

bool Effect_t::timerIsOver() {

	if (timeIsOver(character->getClockPtr(),startTime,duration)) {
		return true;
	}
	return false;
}

void Effect_t::cancelEffect() {
	character->getStats().defaultStats();
	character->updateTimerDependenceStats();
}

void Effect_t::checkActivity() {
	if (timerIsOver()) cancelEffect();
}