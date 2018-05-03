#pragma once
#include <SFML/Graphics.hpp>

#include <list>
#include <memory>
#include "game_t.h"
#include "player_t.h"
#include "bullet_t.h"
#include "additional.h"

class player_t;

class skillObGenerator_t
{

	player_t *character;
	std::list<std::unique_ptr <bullet_t>> &skillGeneratorBulletList;
	
public:
	//skillObGenerator_t();
	skillObGenerator_t(player_t *_character, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	virtual ~skillObGenerator_t();

	void useSkill();

	std::list<std::unique_ptr <bullet_t>> &getBulletList() {
		return skillGeneratorBulletList;
	}
};

