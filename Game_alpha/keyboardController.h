#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"
#include "game_t.h"

class game_t;

class keyboardController{
	character_t *character;
	game_t *game;

	void checkCharacterStateAndChangeDefault();
public:
	keyboardController(character_t *_mainHero, game_t *_game);
	virtual ~keyboardController();

	character_t * getPlayerCharPtr()const {
		return character;
	}


	void eventHandler(sf::Event &event);
};