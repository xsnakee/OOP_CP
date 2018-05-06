#pragma once

#include <SFML/Graphics.hpp>

#include <list>
#include <memory>
#include "character_t.h"
#include "player_t.h"
#include "Npc_t.h"
#include "bullet_t.h"
#include "additional.h"
#include "cursor_t.h"
#include "keyboardController.h"
#include "Level_t.h"

class GameEngine_t
{
private:
	sf :: RenderWindow *window;

	cursor_t *cursor;
	std::unique_ptr<keyboardController> controller;
	Level_t &level;

	std::unique_ptr<sf::Clock> clock;
	float curTime;
	float speed;
	float speedMultipple;
	sf::View *view;

	std::list<std::unique_ptr <character_t>>::iterator mainHero;

public:
	
	GameEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~GameEngine_t();

	void update();
	void draw();

	void keyController(sf::Event &event);
	void checkAlive();
	void visionEngine();
	void collisionEngine();
	void bulletEngine();
	void charsAction();
	
	void setCamera();
	void drawCursor();
	void generateNpc();


	//GET
	float setSpeed(float _time) {
		speed = _time/speedMultipple;
		return speed;
	}

	float getSpeed()const {
		return speed;
	}

	float getCurTimeSec() const {
		return clock->getElapsedTime().asSeconds();
	}

	float getSpeedMultipple()const {
		return speedMultipple;
	}

	std::list<std::unique_ptr <bullet_t>> &getBulletList() {
		return level.bulletsList;
	}
};

