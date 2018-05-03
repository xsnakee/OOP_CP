#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"

class keyboardController
{
protected:
	int controllerMode;
	int key;//mouse click code = 55
	sf::Clock *clock;
	sf::Int32 startTime;
	sf::Int32 keysCD;

public:
	keyboardController(sf::Clock *_clock);
	virtual ~keyboardController();

	void takeKey(sf::Event &event);
	virtual void eventHandler() = 0;

	//GET
	int getKey() const {
		return key;
	}
	
	sf::Int32 getStartTime() const {
		return startTime;
	}

	sf::Int32 getkeyCD() const {
		return keysCD;
	}

	int getControllerMode() const {
		return controllerMode;
	}
};


class PlayerController :public keyboardController {
	character_t *character;


	void setDefaultCharacterState();
public:
	PlayerController(sf::Clock *_clock, character_t *_mainHero);
	virtual ~PlayerController();

	character_t * getPlayerCharPtr()const {
		return character;
	}


	virtual void eventHandler();
};



/*
class menuController :public keyboardController {
	//menuWindiw *window;

public:
	menuController(sf::Clock *_clock);
	virtual ~menuController();

	menuWindiw * getWindowPtr()const {
		return window;
	}
};
//*/