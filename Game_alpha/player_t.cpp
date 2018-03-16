#include "player_t.h"



player_t::player_t() :character_t()
{
	elemStatus = 0;
}



//*
player_t::player_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : character_t(_x, _y, fileName, _coordX, _coordY, _width, _height) {

}
//*/

player_t::~player_t()
{
}


void player_t::update(float speed) {
	if (abs(stat.HP - 1.f) < FLT_EPSILON) {
		alive = false;
		return;
	}

	if (alive) {
		checkSkillGeneratorEmpty();

		posX += dX*speed;
		posY += dY*speed;

		dX = 0.f;
		dY = 0.f;

		sprite.setPosition(posX, posY);
	}
	
}

void player_t:: controller(sf::Event) {
	using namespace sf;
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		dY = -stat.speed;
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {

		dY = stat.speed;
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {

		dX = stat.speed;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		dX = -stat.speed;
	}

}


bool player_t::checkSkillGeneratorEmpty() {
	std::list<elements::element>::iterator temp = skillGeneratorArr.begin();

	size_t tempStatus = 0;

	for (size_t i = 0; i < skillGeneratorArr.size(); ++i,++temp) {
		if ((*temp) == elements::NONE) return false;
		tempStatus += (*temp);
	}

	elemStatus = tempStatus;
	return true;
}

bool player_t::addElement(elements::element _elem) {
	if (skillGeneratorArr.size() < 3) {
		skillGeneratorArr.push_back(_elem);
	}
	else{
		skillGeneratorArr.pop_back();
		skillGeneratorArr.push_back(_elem);
	}

}

size_t player_t::generateSkill(){

}