#pragma once

#include "character_t.h"
#include "bullet_t.h"
#include "additional.h"


class player_t : public character_t
{
public:

	player_t(float _x, float _y, std::string filename, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	virtual  ~player_t();

	virtual void attack();

	void update(float _speed);

};

