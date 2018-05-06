#pragma once

#include "character_t.h"
#include "player_t.h"
#include "Npc_t.h"
#include "map_t.h"
#include "bullet_t.h"
#include "additional.h"

class Level_t
{
public:

	map_t map;
	std::list<std::unique_ptr <character_t>> charactersList;
	std::list<physOb_t*> obList;
	std::list<std::unique_ptr <bullet_t>> bulletsList;
	std::list<ground_t*> mapTilesList;


	Level_t(std::string _levelName);
	~Level_t();

	void generateMapObjects(std::list<physOb_t*> &_obTextureList);
	void generateMapTiles(std::list<ground_t*> &_mapTilesList);

};

