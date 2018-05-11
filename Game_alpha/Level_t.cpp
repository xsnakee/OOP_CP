#include "Level_t.h"



Level_t::Level_t(std::string _levelName): map(_levelName)
{

	succesfull = (map.fillTheMapObj() && map.fillTheMapTiles());

	generateMapObjects(map.mapObList);
	generateMapTiles(map.groundTilesList);	

	levelComplete = false;
	gameOver = false;
}


Level_t::~Level_t()
{
}

void Level_t::generateMapObjects(std::list<physOb_t*> &_obList) {

	obList.insert(obList.end(), _obList.begin(), _obList.end());
	map.mapObList.clear();
}

void Level_t::generateMapTiles(std::list<ground_t*> &_obList) {

	mapTilesList.insert(mapTilesList.end(), _obList.begin(), _obList.end());
	map.groundTilesList.clear();
}


mission_t &Level_t::getMission() {
	return mission;
}

void Level_t::checkMissionsTarget() {
	std::list<std::unique_ptr <character_t>>::iterator it = bossesListIt;
	
	for (size_t i = 0; it != charactersList.end(); ++i, ++it) {
		if (!it->get()->getAlive()){
			mission.missionsCompleteStatus[i] = true;
		}
	}
}

bool Level_t::checkLevelComplete() {

	for (auto &i : mission.missionsCompleteStatus) {
		if (!i) {
			return false;
		}
	}
	return true;
		
}