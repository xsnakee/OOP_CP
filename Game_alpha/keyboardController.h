#pragma once
#include <SFML/Graphics.hpp>
#include "player_t.h"

class keyboardController
{
protected:
	sf::Keyboard::Key key;
	sf::Clock *clock;
	sf::Int32 startTime;
	sf::Int32 keysCD;

public:
	keyboardController(sf::Clock *_clock);
	virtual ~keyboardController();

	void takeKey(sf::Event &event);
	virtual void eventHandler() = 0;

	//GET
	sf::Keyboard::Key getKey() const {
		return key;
	}
	
	sf::Int32 getStartTime() const {
		return startTime;
	}

	sf::Int32 getkeyCD() const {
		return keysCD;
	}
};


class PlayerController :public keyboardController {
	player_t *character;

public:
	PlayerController(sf::Clock *_clock, player_t *_mainHero);
	virtual ~PlayerController();

	player_t * getPlayerCharPtr()const {
		return character;
	}
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