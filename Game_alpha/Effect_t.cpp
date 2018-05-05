#include "Effect_t.h"



Effect_t::Effect_t(character_t *_character,characterStats_t stat, sf::Int32 _duration)
{
	character = _character;
	duration = _duration;
	startTime = 0;
	activity = false;
}


Effect_t::~Effect_t()
{
	cancelEffect();
}


void Effect_t::useEffect(characterStats_t &stat) {
	startTime = character->getClockPtr()->getElapsedTime().asMilliseconds();
	character->getStats().upStat(stat);
	activity = true;
}

bool Effect_t::timeIsOver() {

	if (timerIsOver(character->getClockPtr(),startTime,duration)) {
		activity = false;
	}
}

void Effect_t::cancelEffect() {
	character->getStats().defaultStats();
}