#pragma once
#include <SFML/Graphics.hpp>
#include "Level_t.h"
#include "GameEngine_t.h"
#include "InterfaceEngine_t.h"
#include "mainMenu_t.h"

enum modes {
	PLAY,
	PAUSED,
	GAME_OVER
};

class game_t
{
	sf::RenderWindow *window;
	sf::Clock clock;

	std::unique_ptr<Level_t> level;
	std::unique_ptr<GameEngine_t> game;
	std::unique_ptr<InterfaceEngine_t> interface;
	std::unique_ptr<keyboardController> controller;
	std::unique_ptr<mainMenu_t> mainMenu;

	modes mode;
	std::string levelName;
	size_t difficulty;

public:
	game_t(sf::RenderWindow *_window);
	~game_t();

	void start(std::string levelName);
	void play();
	void keyController(sf::Event &event);
};

