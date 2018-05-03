#pragma once

#include "character_t.h"
#include <list>
#include <iterator>
#include <numeric>
#include "bullet_t.h"
#include "skillObGenerator_t.h"


class skillObGenerator_t;



class player_t : public character_t
{
private:
	std::list<elements::element> skillGeneratorArr;
	size_t elemStatus;
	std::unique_ptr<skillObGenerator_t> skill;

public:

	player_t();
	player_t(float _x, float _y, std::string filename, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	virtual  ~player_t();


	void update(float _speed);

	bool checkSkillGenerator();
	bool addElement(elements::element _elem);
	
	size_t getElemStatus() const {
		return elemStatus;
	}

	void generateSkillAndClearElemList();
};

