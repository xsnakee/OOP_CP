#pragma once
#include <SFML/Graphics.hpp>
#include "player_t.h"
#include "bullet_t.h"
#include <list>

class player_t;

class skillObGenerator_t
{

	player_t *character;
	std::list<bullet_t *> *bulletList;//std::unique_ptr<bullet_t>

public:
	skillObGenerator_t(player_t *_character);
	virtual ~skillObGenerator_t();

	void useSkill();
	void upCharacterStat(characterStats_t &_stats);
	void generateBullet(bullet_t *bullet);
	static void setBulletList(std::list<std::unique_ptr<bullet_t>> *_bulletList);
};

