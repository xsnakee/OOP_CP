#pragma once
#include <SFML/Graphics.hpp>
#include <map>



class characterTimers_t
{
	struct timerStats {
		sf::Int32 startTime;
		sf::Int32 cooldown;
		bool ready = true;
	};
	//get init time in Milliseconds
	sf::Clock *clock;
	std::map<std::string, timerStats> timersList;
	const std::string attackCDkey = "attackCD";
	const std::string castDelaykey = "castDelay";
	const std::string skillGenerationCDkey = "skillGenerationCD";


	void setAttackStartTimer(sf::Int32 _curTime);
	void setcastDelayStartTimer(sf::Int32 _curTime);
	void setswapDirectionTimerStartTimer(sf::Int32 _curTime);
public:
	characterTimers_t();
	characterTimers_t(sf::Clock *_clock, int _castSpeed = 1, int _attackSpeed = 1);
	~characterTimers_t();
	
	
	//GET

	sf::Clock *getClockPtr() const {
		return clock;
	}

	sf::Int32 &getAttackStartTime();
	sf::Int32 &getCastStartTime();
	sf::Int32 &getSwapDirStartTime();

	sf::Int32 &getAttackCD();
	sf::Int32 &getCastDelay();
	sf::Int32 &getDirectionSwapTime();

	sf::Int32 attackCDcorrection(float _attackSpeed);
	sf::Int32 castDelayCorrection(float _castDelay);
	sf::Int32 directionSwapTimeCorrection(int _time);

	void setAttackCD(int _attackCD);
	void setCastDelay(int _castDelay);
	void setDirectionSwapTime(int _time);

	bool attackReady();
	bool castReady();
	bool swapDirectionReady();

	void updateAttackCD();
	void updateCastCD();
	void updateSwapDirectionCD();
};

