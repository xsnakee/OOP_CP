#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "character_t.h"
#include "player_t.h"
#include "map_t.h"
#include "bullet_t.h"
#include "additional.h"

class game_t
{
private:
	sf::Clock clock;
	float curTime;
	float speed;
	float speedMultipple;
	map_t map;

public:
	std::list<character_t*> charactersList;
	std::list<physOb_t*> obList;

	game_t();
	game_t(std::string mapFileName, std::string _tileFileName, int _sizeX, int _sizeY);
	~game_t();
	

	void update();
	void draw(sf::RenderWindow *_window);

	void keyController(sf::Event &event);
	void checkAlive();

	void addOb(physOb_t *);
	void addChar(character_t *);

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

