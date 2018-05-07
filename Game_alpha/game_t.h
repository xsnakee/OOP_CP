#pragma once
#include <SFML/Graphics.hpp>
#include "Level_t.h"
#include "GameEngine_t.h"
#include "InterfaceEngine_t.h"

class game_t
{
	sf::RenderWindow *window;
	sf::Clock clock;

	Level_t level;
	GameEngine_t game;
	InterfaceEngine_t interface;

public:
	game_t(sf::RenderWindow *_window);
	~game_t();

	void start();
};

