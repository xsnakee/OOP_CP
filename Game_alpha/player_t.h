#pragma once

#include "character_t.h"
#include "bullet_t.h"
#include "additional.h"


class player_t : public character_t
{
public:

	player_t(sf::Vector2f _pos, std::string filename, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	player_t(std::shared_ptr<sf::Texture> _texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Vector2f _pos, int _width, int _height, sf::Clock *_clock);

	virtual  ~player_t();

	virtual void attack();
	void useMP(float _mp);
	void update(float _speed);

};

