#include "player_t.h"
#include <iostream>


player_t::player_t() :character_t()
{
	keyCooldown = 400;
	startKeyPressTime = 0;
	elemStatus = 0;
	fraction = 0;
}



//*
player_t::player_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock) : character_t(_x, _y, fileName, _coordX, _coordY, _width, _height) {

	keyCooldown = 400;
	startKeyPressTime = 0;
	clock = _clock;
	fraction = 0;
}
//*/

player_t::~player_t()
{
}


void player_t::update(float _speed) {
	character_t::update(_speed);

}

void player_t::controller(sf::Event) {
	using namespace sf;
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		dY = -stat.speed;
		updateFrame();
	}else

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		dY = stat.speed;
		updateFrame();

	}
	else

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		dX = stat.speed;
		updateFrame();
	}
	else
	

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		dX = -stat.speed;
		updateFrame();
	}

	if (Keyboard::isKeyPressed(Keyboard::E)) {
		posX = 100.0f;
		posY = 100.0f;
	}
	

	if (!checkKeyCd(clock))
	{
		if (Keyboard::isKeyPressed(Keyboard::Space)) {


			addElement(elements::FIRE);
			checkSkillGenerator();
			std::cout << elements::FIRE;

		}

		
		startKeyPressTime = clock->getElapsedTime().asMilliseconds();

	}
	
}


bool player_t::checkSkillGenerator() {
	std::list<elements::element>::iterator temp = skillGeneratorArr.begin();

	size_t tempStatus = 0;

	for (size_t i = 0; i < skillGeneratorArr.size(); ++i, ++temp) {
		if ((*temp) == elements::NONE) return false;
		tempStatus += (*temp);
	}

	elemStatus = tempStatus;
	//sprite.setColor(sf::Color::Green);

	return true;
}

bool player_t::addElement(elements::element _elem) {
	if (skillGeneratorArr.size() < 3) {
		skillGeneratorArr.push_back(_elem);
		return true;
	}
	else {
		skillGeneratorArr.pop_back();
		skillGeneratorArr.push_back(_elem);
		return true;
	}
	return false;
}

size_t player_t::generateSkill() {

}

bool player_t::checkKeyCd(sf::Clock *clock) {

	sf::Int32 temptime = clock->getElapsedTime().asMilliseconds();

	return (temptime - startKeyPressTime) >= keyCooldown ? false : true;
}


bool player_t::attack(float _x, float _y) {
	return false;
}