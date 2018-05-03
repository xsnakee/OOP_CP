#include "player_t.h"
#include <iostream>


player_t::player_t() :character_t()
{
	elemStatus = 0;
	fraction = 0;
	collision = true;
}



//*
player_t::player_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : character_t(_x, _y, fileName, _coordX, _coordY, _width, _height, _clock)
{
	skill = std::move(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	fraction = 0;
	collision = true;
	state = std::unique_ptr<CharacterState_t>(new CharacterPlayerControll_t(this));
}
//*/

player_t::~player_t()
{
}


void player_t::update(float _speed) {
	character_t::update(_speed);

}



bool player_t::checkSkillGenerator() {
	std::list<elements::element>::iterator temp = skillGeneratorArr.begin();

	size_t tempStatus = 0;

	for (size_t i = 0; i < skillGeneratorArr.size(); ++i, ++temp) {
		if ((*temp) == elements::NONE) return false;
		tempStatus += (*temp);
	}

	elemStatus = tempStatus;

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

void player_t::generateSkillAndClearElemList() {
	elemStatus = std::accumulate(skillGeneratorArr.begin(),skillGeneratorArr.end(),0);
	skillGeneratorArr.clear();
	elemStatus = 0;
}
