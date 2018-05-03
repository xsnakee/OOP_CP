#pragma once
#include <SFML/Graphics.hpp>

#include <list>
#include <memory>
#include "character_t.h"
#include "bullet_t.h"
#include "additional.h"

class character_t;

class skillObGenerator_t
{

	character_t *character;
	std::list<std::unique_ptr <bullet_t>> &skillGeneratorBulletList;
	
public:
	//skillObGenerator_t();
	skillObGenerator_t(character_t *_character, std::list<std::unique_ptr <bullet_t>> &_bulletList);
	virtual ~skillObGenerator_t();

	void useSkill();

	void upCharacterStat(characterStats_t &_stats);


	std::list<std::unique_ptr <bullet_t>> &getBulletList() {
		return skillGeneratorBulletList;
	}
};

