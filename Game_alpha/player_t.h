#pragma once

#include "character_t.h"
#include "additional.h"
#include <list>
#include <iterator>

const int MAIN_HERO_SPRITE_WIDTH = 25;
const int MAIN_HERO_SPRITE_HEIGHT = 30;
const int SPRITE_X = 195;
const int SPRITE_Y= 0;
const std::string MAIN_HERO_TEXTURE_FILE = "img/mainHeroSprite.png";

class player_t : public character_t
{
public:
	std::list<elements::element> skillGeneratorArr;
	size_t elemStatus;
public:

	player_t();
	player_t(float _x, float _y, std::string filename, int _coordX, int _coordY, int _width, int _height);
	virtual  ~player_t();

	

	virtual void update(float speed);
	void controller(sf::Event);
	bool checkSkillGeneratorEmpty();
	bool addElement(elements::element _elem);
	size_t generateSkill();
};

