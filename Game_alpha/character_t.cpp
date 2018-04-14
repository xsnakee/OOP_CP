#include "character_t.h"



character_t::character_t():physOb_t()
{
	destroyble = true;
	skill = nullptr;
}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y) {
	destroyble = true;
	skill = nullptr;
}

//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height){
	destroyble = true;
	skill = nullptr;
}


//*/
character_t::~character_t()
{
}



void character_t::setStats(characterStats_t &_stats) {

	stat = _stats;

}

characterStats_t character_t::getStats() {
	return stat;
}

void character_t::defaultStats() {
	stat.defaultStats();
}

bool character_t::checkTimer(sf::Clock *clock) {

	sf::Int32 tempTime = clock->getElapsedTime().asMilliseconds();

	bool tempReuslt= (abs(tempTime - startTime) > timer) ? false : true;

	return tempReuslt;
}