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
	std::vector<character_t*>::iterator &it = bossesList.begin();
	for (size_t i = 0; i < bossesList.size(); ++i) {
		if ((i == 0 || getMission().missionsCompleteStatus[i - 1]) &&
			(i == bossesList.size() - 1 || !getMission().missionsCompleteStatus[i + 1])) {
			(*it)->setDestroyble(true);
		}
		++it;
	}

	size_t tempCounter = 0;
	for (auto &i : bossesList) {
		if ((!i->getAlive())) {
			mission.missionsCompleteStatus[tempCounter] = true;
		}
		++tempCounter;
	
	}
}

bool Level_t::checkLevelComplete() {

	checkMissionsTarget();
	return mission.missionsCompleteStatus[(mission.missionsCompleteStatus.size() - 1)] ? true : false;
		
}