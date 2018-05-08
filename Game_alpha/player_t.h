#pragma once

#include "character_t.h"
#include "bullet_t.h"
#include "additional.h"


class player_t : public character_t
{
public:

	player_t(float _x, float _y, std::string filename, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	player_t(std::shared_ptr<sf::Texture> _texture, std::list<std::unique_ptr <bullet_t>> &_bulletList,float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock);

	virtual  ~player_t();

	virtual void attack();
	void useMP(float _mp);
	void update(float _speed);

};

