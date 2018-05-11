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
	size_t iterationAmount = mission.missionsCompleteStatus.size();
	for (size_t i = 0; i < iterationAmount; ++i) {
		if ((i == 0 || getMission().missionsCompleteStatus[i - 1]) &&
			(i == iterationAmount - 1 || !getMission().missionsCompleteStatus[i + 1])) {
			(*it)->setDestroyble(true);
		}
		++it;
	}

	size_t tempCounter = 0;
	std::list<std::unique_ptr <character_t>>::iterator it2 = bossesListIt;

	for (size_t i = 0; i < iterationAmount; ++i) {
		if ((!it2->get()->getAlive())) {
			mission.missionsCompleteStatus[tempCounter] = true;
		}
		++it2;
	}
}

bool Level_t::checkLevelComplete() {

	checkMissionsTarget();
	return mission.missionsCompleteStatus[(mission.missionsCompleteStatus.size() - 1)] ? true : false;
		
}