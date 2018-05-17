#include "characterTimers_t.h"
const sf::Int32 STD_ATTACK_CD = 1000;
const sf::Int32 STD_CAST_DELAY = 2000;

characterTimers_t::characterTimers_t()
{
}

characterTimers_t::characterTimers_t(sf::Clock *_clock, int _castSpeed, int _attackSpeed)
{
	clock = _clock;
	sf::Int32 startTime = 1;

	timerStats attackCD = { startTime, STD_ATTACK_CD };
	timersList.push_back(attackCD);

	timerStats castDelay = { startTime, STD_CAST_DELAY };
	timersList.push_back(castDelay);

	timerStats skillGenerationCD = { startTime, 4000 };
	timersList.push_back(skillGenerationCD);
}

characterTimers_t::~characterTimers_t()
{
}
characterTimers_t &characterTimers_t::operator =(characterTimers_t _secondTimer) {
	_secondTimer.timersList = timersList;
	return *this;
}
sf::Int32 &characterTimers_t::getAttackStartTime() {
	return timersList[0].startTime;
}
sf::Int32 &characterTimers_t::getCastStartTime() {
	return timersList[1].startTime;
}
sf::Int32 &characterTimers_t::getSwapDirStartTime() {
	return timersList[2].startTime;
}


sf::Int32 &characterTimers_t::getAttackCD() {
	return timersList[0].cooldown;
}
sf::Int32 &characterTimers_t::getCastDelay() {
	return timersList[1].cooldown;
}
sf::Int32 &characterTimers_t::getDirectionSwapTime() {
	return timersList[2].cooldown;
}


sf::Int32 characterTimers_t::attackCDcorrection(float _attackCD) {
	timersList[0].cooldown = STD_ATTACK_CD - static_cast<sf::Int32>(_attackCD * 100);
	return timersList[0].cooldown;
}
sf::Int32 characterTimers_t::castDelayCorrection(float _castDelay) {

	timersList[1].cooldown = STD_CAST_DELAY - static_cast<sf::Int32>(_castDelay * 100);
	return timersList[1].cooldown;
}
sf::Int32 characterTimers_t::directionSwapTimeCorrection(int _time) {

	timersList[2].cooldown /= _time;
	return timersList[2].cooldown;
}



void characterTimers_t::setAttackCD(int _attackCD) {
	timersList[0].cooldown = abs(_attackCD);
}
void characterTimers_t::setCastDelay(int _castDelay) {
	timersList[1].cooldown = abs(_castDelay);
}
void characterTimers_t::setDirectionSwapTime(int _time) {
	timersList[2].cooldown = abs(_time);}


void characterTimers_t::setAttackStartTimer(sf::Int32 _curTime) {
	timersList[0].startTime = _curTime;
}

void characterTimers_t::setcastDelayStartTimer(sf::Int32 _curTime) {
	timersList[1].startTime = _curTime;
}

void characterTimers_t::setswapDirectionTimerStartTimer(sf::Int32 _curTime) {
	timersList[2].startTime = _curTime;
}


bool characterTimers_t::attackReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[0].ready = (abs(curTime - timersList[0].startTime) > timersList[0].cooldown) ? true : false;
	return timersList[0].ready;
}
bool characterTimers_t::castReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[1].ready = (abs(curTime - timersList[1].startTime) > timersList[1].cooldown) ? true : false;
	return timersList[1].ready;
}
bool characterTimers_t::swapDirectionReady() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[2].ready = (abs(curTime - timersList[2].startTime) > timersList[2].cooldown) ? true : false;
	return timersList[2].ready;
}


void characterTimers_t::updateAttackCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[0].ready = false;
	setAttackStartTimer(curTime);
}

void characterTimers_t::updateCastCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();
	timersList[1].ready = false;
	setcastDelayStartTimer(curTime);
}
void characterTimers_t::updateSwapDirectionCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[2].ready = false;
	setswapDirectionTimerStartTimer(curTime);
}