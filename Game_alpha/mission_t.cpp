#include "mission_t.h"
//GAME STATS

gameStatistic_t::gameStatistic_t() {
	statFields = STAT_LIST;
	statStrValues = std::vector<std::string>(statFields.size());
	statDataVect = std::vector <size_t>(statFields.size(), 0);
	fillStrStats();
}

gameStatistic_t::~gameStatistic_t() {
}

void gameStatistic_t::ånemyKilled() {
	++statDataVect[0];

}
void gameStatistic_t::bossKilled() {
	++statDataVect[1];
}
void gameStatistic_t::setTime(sf::Clock *clock) {
	statDataVect[2] = clock->getElapsedTime().asSeconds();
}
std::string gameStatistic_t::convertTime(size_t _val) {
	size_t minutes = _val / 60;
	size_t seconds = _val % 60;
	std::ostringstream tempStream;

	tempStream << minutes << ":" << seconds;//minutes + " : " + seconds
	return std::string(tempStream.str());
}

void gameStatistic_t::fillStrStats() {
	std::ostringstream tempStream;
	for (size_t i = 0; i < statStrValues.size(); ++i) {
		if (i != 2) {
			tempStream.str(std::string());
			tempStream << statDataVect[i];
			statStrValues[i] = tempStream.str();
		}
	}	 
	statStrValues[2] = convertTime(statDataVect[2]);
}


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
void mission_t::setTime(sf::Clock *clock) {
	gameStats.setTime(clock);
}


bool mission_t::checkComplete() {
	for (auto &i : missionsCompleteStatus) {
		if (!i) return false;
	}

	return true;
}



