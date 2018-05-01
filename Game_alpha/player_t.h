#pragma once

#include "character_t.h"
#include <list>
#include <iterator>




class player_t : public character_t
{
private:
	std::list<elements::element> skillGeneratorArr;
	size_t elemStatus;

public:

	player_t();
	player_t(float _x, float _y, std::string filename, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock);
	virtual  ~player_t();

	

	void update(float _speed);

	bool checkSkillGenerator();
	bool addElement(elements::element _elem);


	size_t generateSkill();
};

