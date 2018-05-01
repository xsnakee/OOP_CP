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
	std::string attackCDkey = "attackCD";
	std::string castDelaykey = "castDelay";
	std::string swapDirectionTimerkey = "swapDirectionTimer";


	void setAttackStartTimer(sf::Int32 _curTime);
	void setcastDelayStartTimer(sf::Int32 _curTime);
	void setswapDirectionTimerStartTimer(sf::Int32 _curTime);
public:
	characterTimers_t();
	characterTimers_t(sf::Clock *_clock, int _castSpeed = 1, int _attackSpeed = 1);
	~characterTimers_t();



	sf::Int32 getAttackCD(int _attackCD);
	sf::Int32 getCastDelay(int _castDelay);
	sf::Int32 getDirectionSwapTime(int _time);


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

