#include "mission_t.h"



mission_t::mission_t(): gameStats()
{
	missionsContent = STD_MISSION_TASKS;
	missionsCompleteStatus = std::vector<bool>(missionsContent.size(),false);
}

mission_t::mission_t(std::string _fileName) {
	//OPEN FILE AND READ DATA

	missionsCompleteStatus = std::vector<bool>(missionsContent.size(), false);
}

mission_t::~mission_t()
{
}


void mission_t::ånemyKilled() {
	gameStats.ånemyKilled();
}
void mission_t::bossKilled() {
	gameStats.bossKilled();
}
void mission_t::setDeathTime() {
	gameStats.setDeathTime();
}


bool mission_t::checkComplete() {
	for (auto &i : missionsCompleteStatus) {
		if (!i) return false;
	}

	return true;
}

//GAME STATS

gameStatistic_t::gameStatistic_t(){
	statFields = STAT_LIST;
	statStrValues = std::vector<std::string>(statFields.size());
	statDataVect = std::vector <size_t>(statFields.size());
}

gameStatistic_t::~gameStatistic_t() {
}

void gameStatistic_t::ånemyKilled() {
	++statDataVect[0];

}
void gameStatistic_t::bossKilled() {
	++statDataVect[1];
}
void gameStatistic_t::setDeathTime() {
	++statDataVect[2];
}
std::string gameStatistic_t::convertTime(size_t _val) {
	size_t minutes = statDataVect[3] / 60;
	size_t seconds = statDataVect[3] % 60;
	return std::string(minutes + " : " + seconds);
}

void gameStatistic_t::fillStrStats() {
	for (size_t i = 0; i < statStrValues.size(); ++i) {
		statStrValues[i] = static_cast<const char>(statDataVect[i]);
	}
	statStrValues[3] = convertTime(statDataVect[3]);
}

