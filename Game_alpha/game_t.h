#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "character_t.h"
#include "player_t.h"

class game_t
{
private:
	sf::Clock clock;
	float curTime;
	float speed;
	float speedMultipple;

public:
	std::vector<character_t*> charactersList;

	game_t();
	~game_t();
	

	void update();
	void draw(sf::RenderWindow *_window);
	void keyController(sf::Event &event);

	//GET
	float setSpeed(float _time) {
		speed = _time/speedMultipple;
		return speed;
	}

	float getSpeed()const {
		return speed;
	}

	float getCurTimeSec() const {
		return clock.getElapsedTime().asSeconds();
	}

	float getSpeedMultipple()const {
		return speedMultipple;
	}

};

