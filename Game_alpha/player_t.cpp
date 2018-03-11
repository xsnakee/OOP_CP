#include "player_t.h"



player_t::player_t() :character_t()
{
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