#pragma once

#include <vector>
#include <memory>

#include "character_t.h"
#include "player_t.h"
#include "Npc_t.h"
#include "map_t.h"
#include "bullet_t.h"
#include "additional.h"
#include "mission_t.h"

class Level_t
{
public:

	bool succesfull;

	bool levelComplete;
	bool gameOver;

	mission_t mission;

	map_t map;
	std::list<std::unique_ptr <character_t>> charactersList;
	std::list<std::unique_ptr <bullet_t>> bulletsList;
	std::list<std::unique_ptr <character_t>>::iterator bossesListIt;

	std::list<std::unique_ptr <character_t>>::iterator mainHero;

	Level_t(std::string _levelName);
	~Level_t();


	mission_t &getMission();
	void checkMissionsTarget();
	bool checkLevelComplete();

};

