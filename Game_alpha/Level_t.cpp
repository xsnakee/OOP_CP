#include "Level_t.h"



Level_t::Level_t(std::string _levelName): map(_levelName)
{

	succesfull = (map.fillTheMapObj() && map.fillTheMapTiles());
	levelComplete = false;
	gameOver = false;
}


Level_t::~Level_t()
{
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