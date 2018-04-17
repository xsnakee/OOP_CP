#include "character_t.h"
#include <iostream>


character_t::character_t():physOb_t()
{
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y) {
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
}

//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height){
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
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

bool character_t::kill() {
	alive = false;
	return false;
};

void character_t::update(float _speed) {

	if (abs(stat.HP - 1.f) < FLT_EPSILON) {
		alive = false;
		return;
	}

	physOb_t::update(_speed);

	animation();	
}


void character_t::animation() {


	int spriteCoordX = static_cast<int>(frame) * animation::MAIN_HERO_SPRITE_WIDTH;
	int spriteCoordY = direction * animation::MAIN_HERO_SPRITE_HEIGHT;

	spritePref.setTexturePos(spriteCoordX, spriteCoordY);
	//spritePref.getSprite().setTextureRect(sf::IntRect(, animation::MAIN_HERO_SPRITE_HEIGHT, animation::MAIN_HERO_SPRITE_WIDTH));
	//std::cout << "4";
}

void character_t::updateFrame() {

	frame += animation::frameSpeed;
	if (frame > animation::frameRate) {
		frame -= animation::frameRate;
	}
}