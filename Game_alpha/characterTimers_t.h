#pragma once
#include <SFML/Graphics.hpp>
#include <map>



class characterTimers_t
{
	struct timerStats {
		sf::Int32 startTime;
		sf::Int32 cooldown;
	};
	//get init time in Milliseconds
	sf::Clock *clock;
	std::map<std::string, timerStats> timersList;
	std::string attackCDkey = "attackCD";
	std::string castDelaykey = "castDelay";
		std::string swapDirectionTimerkey = "swapDirectionTimer";
public:
	characterTimers_t(sf::Clock *_clock, int _castSpeed = 1, int _attackSpeed = 1);
	~characterTimers_t();



	sf::Int32 getAttackCD(int _attackCD);
	sf::Int32 getCastDelay(int _castDelay);
	sf::Int32 getDirectionSwapTime(int _time);


	bool setAttackCD(int _attackCD);
	bool setCastDelay(int _castDelay);
	bool setDirectionSwapTime(int _time);

	bool setAttackStartTimer( sf::Int32 _curTime);
	bool setcastDelayStartTimer(sf::Int32 _curTime);
	bool setswapDirectionTimerStartTimer(sf::Int32 _curTime);


	bool attackReady();
	bool castReady();
	bool swapDirectionReady();
};

