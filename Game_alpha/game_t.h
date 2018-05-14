#pragma once
#include <SFML/Graphics.hpp>
#include "Level_t.h"
#include "GameEngine_t.h"
#include "InterfaceEngine_t.h"
#include "keyboardController.h"
#include "mouseController.h"
#include "mainMenu_t.h"
#include "additional.h"

class mouseController;
class keyboardController;

class game_t
{
	sf::RenderWindow *window;
	sf::Clock clock;

	std::unique_ptr<Level_t> level;
	std::unique_ptr<keyboardController> KBcontroller;
	std::unique_ptr<mouseController> Mcontroller;

	std::string levelName;
	size_t difficulty;
	game::status status;

public:

	std::unique_ptr<GameEngine_t> gameEngine;
	std::unique_ptr<InterfaceEngine_t> interfaceEngine;

	game_t(sf::RenderWindow *_window, std::string _levelName, size_t _difficulty);
	~game_t();
	sf::RenderWindow *getWindowPtr() const {
		return window;
	}
	void start();
	void play();
	void resetGame();
	void keyController(sf::Event &event);
	game::status getStatus() const;
	void setGameStatus(game::status _newStatus);
};

