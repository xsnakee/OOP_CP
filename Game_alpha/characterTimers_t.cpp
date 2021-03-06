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
	timersList.insert(std::pair<std::string,timerStats>(attackCDkey, attackCD));

	timerStats castDelay = { startTime, STD_CAST_DELAY };
	timersList.insert(std::pair<std::string, timerStats>(castDelaykey, castDelay));

	timerStats skillGenerationCD = { startTime, 4000 };
	timersList.insert(std::pair<std::string, timerStats>(skillGenerationCDkey, skillGenerationCD));
}

characterTimers_t::~characterTimers_t()
{
}
characterTimers_t &characterTimers_t::operator =(characterTimers_t _secondTimer) {
	_secondTimer.timersList = timersList;
	return *this;
}
sf::Int32 &characterTimers_t::getAttackStartTime() {
	return timersList[attackCDkey].startTime;
}
sf::Int32 &characterTimers_t::getCastStartTime() {
	return timersList[castDelaykey].startTime;
}
sf::Int32 &characterTimers_t::getSwapDirStartTime() {
	return timersList[skillGenerationCDkey].startTime;
}


sf::Int32 &characterTimers_t::getAttackCD() {
	return timersList[attackCDkey].cooldown;
}
sf::Int32 &characterTimers_t::getCastDelay() {
	return timersList[castDelaykey].cooldown;
}
sf::Int32 &characterTimers_t::getDirectionSwapTime() {
	return timersList[skillGenerationCDkey].cooldown;
}


sf::Int32 characterTimers_t::attackCDcorrection(float _attackCD) {
	timersList[attackCDkey].cooldown = STD_ATTACK_CD - static_cast<sf::Int32>(_attackCD * 100);
	return timersList[attackCDkey].cooldown;
}
sf::Int32 characterTimers_t::castDelayCorrection(float _castDelay) {

	timersList[castDelaykey].cooldown = STD_CAST_DELAY - static_cast<sf::Int32>(_castDelay * 100);
	return timersList[castDelaykey].cooldown;
}
sf::Int32 characterTimers_t::directionSwapTimeCorrection(int _time) {

	timersList[skillGenerationCDkey].cooldown /= _time;
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
	setcastDelayStartTimer(curTime);
}
void characterTimers_t::updateSwapDirectionCD() {
	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	timersList[skillGenerationCDkey].ready = false;
	setswapDirectionTimerStartTimer(curTime);
}