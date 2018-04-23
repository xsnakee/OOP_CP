#pragma once
#include <SFML/Graphics.hpp>
#include <map>
struct timerStats {
	sf::Int32 startTime;
	sf::Int32 cooldown;
};

class characterTimers_t
{
	//get init time in Milliseconds
	sf::Clock *clock;
	std::map<std::string, timerStats> timersList;
public:
	characterTimers_t();
	~characterTimers_t();
};

