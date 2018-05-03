#pragma once

#include <SFML/Graphics.hpp>

#include <list>
#include <memory>
#include "character_t.h"
#include "player_t.h"
#include "Npc_t.h"
#include "map_t.h"
#include "bullet_t.h"
#include "additional.h"
#include "cursor_t.h"
#include "skillObGenerator_t.h"
#include "keyboardController.h"

class game_t
{
private:
	sf :: RenderWindow *window;

	cursor_t *cursor;
	std::unique_ptr<keyboardController> controller;

	std::unique_ptr<sf::Clock> clock;
	float curTime;
	float speed;
	float speedMultipple;
	map_t map;
	
	sf::View *view;

	std::list<std::unique_ptr <character_t>> charactersList;
	std::list<std::unique_ptr <character_t>>::iterator mainHero;
//	std::list<std::unique_ptr <Npc_t>> npcList;

	std::list<physOb_t*> obList;
	std::list<std::unique_ptr <bullet_t>> bulletsList;
	std::list<ground_t*> mapTilesList;
public:
	

	game_t();
	game_t(sf::RenderWindow *_window, std::string _levelName);
	~game_t();

	void update();
	void draw();

	void keyController(sf::Event &event);
	void checkAlive();
	void visionEngine();
	void collisionEngine();
	void bulletEngine();
	void charsAction();

	void addOb(physOb_t *);
	void addChar(character_t *);

	void generateMapObjects(std::list<physOb_t*> &_obTextureList);
	void generateMapTiles(std::list<ground_t*> &_mapTilesList);
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
		return clock->getElapsedTime().asSeconds();
	}

	float getSpeedMultipple()const {
		return speedMultipple;
	}

	std::list<std::unique_ptr <bullet_t>> &getBulletList() {
		return bulletsList;
	}
};

