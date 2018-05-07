#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"

class keyboardController
{
protected:
	int controllerMode;
	int key;//mouse click code = 55

public:
	keyboardController(sf::Clock *_clock);
	virtual ~keyboardController();

	bool checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time);

	virtual void eventHandler(sf::Event &event) = 0;
	//GET
	int getKey() const {
		return key;
	}

	int getControllerMode() const {
		return controllerMode;
	}
};


class PlayerController :public keyboardController {
	character_t *character;


	void checkCharacterStateAndChangeDefault();
public:
	PlayerController(sf::Clock *_clock, character_t *_mainHero);
	virtual ~PlayerController();

	character_t * getPlayerCharPtr()const {
		return character;
	}


	virtual void eventHandler(sf::Event &event);//virtual void eventHandler();
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