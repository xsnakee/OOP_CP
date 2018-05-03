#pragma once
#include <SFML/Graphics.hpp>
#include "player_t.h"
#include <list>

class skillObGenerator_t
{

	player_t *character;
	static std::list<std::unique_ptr<bullet_t>> &bulletList;

public:
	skillObGenerator_t(player_t *_character);
	virtual ~skillObGenerator_t();

	void useSkill();
	void upCharacterStat(characterStats_t &_stats);
	void generateBullet(bullet_t *bullet);
};

