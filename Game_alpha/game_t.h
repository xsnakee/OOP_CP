#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "character_t.h"
#include "player_t.h"
#include "map_t.h"
#include "bullet_t.h"
#include "additional.h"
#include "cursor_t.h"
#include <memory>

class game_t
{
private:
	sf :: RenderWindow *window;
	cursor_t *cursor;

	sf::Clock clock;
	float curTime;
	float speed;
	float speedMultipple;
	map_t map;
	
	sf::View *view;

	std::list<std::unique_ptr <character_t>> charactersList;
	std::list<std::unique_ptr <character_t>>::iterator mainHero;

	std::list<physOb_t*> obList;
	std::list<bullet_t*> bulletsList;

public:
	

	game_t();
	game_t(sf::RenderWindow *_window, std::string _levelName);
	~game_t();

	void update();
	void draw();

	void keyController(sf::Event &event);
	void checkAlive();
	void collisionEngine();

	void addOb(physOb_t *);
	void addChar(character_t *);

	void generateMapObjects(std::list<physOb_t*> _obTextureList);

	void setCamera();

	void drawCursor();
	


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

