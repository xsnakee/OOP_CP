#include "characterTimers_t.h"

characterTimers_t::characterTimers_t()
{
}

characterTimers_t::characterTimers_t(sf::Clock *_clock, int _castSpeed, int _attackSpeed)
{
	clock = _clock;
	sf::Int32 startTime = clock->getElapsedTime().asMilliseconds();

	timerStats attackCD = { startTime, 1000/ _attackSpeed};
	timersList.insert(std::pair<std::string,timerStats>(attackCDkey, attackCD));

	timerStats castDelay = { startTime, 1500 / _castSpeed};
	timersList.insert(std::pair<std::string, timerStats>(castDelaykey, castDelay));

	timerStats swapDirectionTimer = { startTime, 4000 };
	timersList.insert(std::pair<std::string, timerStats>(skillGenerationCDkey, swapDirectionTimer));
}

characterTimers_t::~characterTimers_t()
{
}


sf::Int32 characterTimers_t::getAttackCD(int _attackCD) {
	return timersList[attackCDkey].cooldown;
}
sf::Int32 characterTimers_t::getCastDelay(int _castDelay) {
	return timersList[castDelaykey].cooldown;
}
sf::Int32 characterTimers_t::getDirectionSwapTime(int _time) {
	return timersList[skillGenerationCDkey].cooldown;
}



void characterTimers_t::setAttackCD(int _attackCD) {
	timersList[attackCDkey].cooldown = abs(_attackCD);
}
void characterTimers_t::setCastDelay(int _castDelay) {
	timersList[castDelaykey].cooldown = abs(_castDelay);
}
void characterTimers_t::setDirectionSwapTime(int _time) {
	timersList[skillGenerationCDkey].cooldown = abs(_time);}


void characterTimers_t::setAttackStartTimer(sf::Int32 _curTime) {
	timersList[attackCDkey].startTime = _curTime;
}

void characterTimers_t::setcastDelayStartTimer(sf::Int32 _curTime) {
	timersList[castDelaykey].startTime = _curTime;
}

void characterTimers_t::setswapDirectionTimerStartTimer(sf::Int32 _curTime) {
	timersList[skillGenerationCDkey].startTime = _curTime;
}


bool characterTimers_t::attackReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[attackCDkey].ready = (abs(curTime - timersList[attackCDkey].startTime) > timersList[attackCDkey].cooldown) ? true : false;
	return timersList[attackCDkey].ready;
}
bool characterTimers_t::castReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[castDelaykey].ready = (abs(curTime - timersList[castDelaykey].startTime) > timersList[castDelaykey].cooldown) ? true : false;
	return timersList[castDelaykey].ready;
}
bool characterTimers_t::swapDirectionReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[skillGenerationCDkey].ready = (abs(curTime - timersList[skillGenerationCDkey].startTime) > timersList[skillGenerationCDkey].cooldown) ? true : false;
	return timersList[skillGenerationCDkey].ready;
}


void characterTimers_t::updateAttackCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[attackCDkey].ready = false;
	setAttackStartTimer(curTime);
}

void characterTimers_t::updateCastCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[castDelaykey].ready = false;
}
void characterTimers_t::updateSwapDirectionCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[skillGenerationCDkey].ready = false;
	setswapDirectionTimerStartTimer(curTime);
}