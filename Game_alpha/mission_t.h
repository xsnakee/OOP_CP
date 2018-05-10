#pragma once
#include <vector>
#include <memory>


class gameStatistic_t {
	std::string convertTime(size_t _val);

public:
	gameStatistic_t();
	~gameStatistic_t();
	std::vector<std::string> statFields;
	std::vector<std::string> statStrValues;

	std::vector <size_t> statDataVect;

	void fillStrStats();

	void ŚnemyKilled();
	void bossKilled();
	void setDeathTime();
};



const std::vector<std::string> STD_MISSION_TASKS = {
	"- KILL THE HOLY CRYSTAL DEFENDER",
	"- KILL BLACK DRAGON",
	"- KILL RED DRAGON",
	"- KILL THE ENH ",
	"- KILL THE QUEEN OF DARKNESS (MAIN)"
};

class mission_t
{
public:
	gameStatistic_t gameStats;

	std::vector<std::string> missionsContent;
	std::vector<bool> missionsCompleteStatus;

	mission_t();
	mission_t(std::string _fileName);
	~mission_t();

	void ŚnemyKilled();
	void bossKilled();
	void setDeathTime();

	bool checkComplete();

};

const std::vector<std::string> STAT_LIST = {
	"KILLED ENEMYES",
	"KILLED BOSSES",
	"ALIVE TIME"
};

