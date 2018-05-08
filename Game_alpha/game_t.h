#pragma once
#include <SFML/Graphics.hpp>
#include "Level_t.h"
#include "GameEngine_t.h"
#include "InterfaceEngine_t.h"

enum modes {
	START_MENU,
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

	modes mode;
	size_t difficulity;

public:
	game_t(sf::RenderWindow *_window);
	~game_t();

	void start(std::string levelName, size_t difficulity = 1);
	void play();
	void keyController(sf::Event &event);
};

