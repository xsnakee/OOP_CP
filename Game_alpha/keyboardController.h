#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"

class keyboardController
{
public:
	keyboardController();
	virtual ~keyboardController();

	bool checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time);

	virtual void eventHandler(sf::Event &event) = 0;
};


class PlayerController :public keyboardController {
	character_t *character;


	void checkCharacterStateAndChangeDefault();
public:
	PlayerController(character_t *_mainHero);
	virtual ~PlayerController();

	character_t * getPlayerCharPtr()const {
		return character;
	}


	virtual void eventHandler(sf::Event &event);//virtual void eventHandler();
};



/*
class menuController :public keyboardController {
	//menuWindow *window;

public:
	menuController(sf::Clock *_clock);
	virtual ~menuController();

	menuWindiw * getWindowPtr()const {
		return window;
	}
};
//*/