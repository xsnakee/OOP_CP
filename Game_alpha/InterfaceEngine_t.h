#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <memory>
#include "Level_t.h"
#include "InterfaceBar.h"

class InterfaceEngine_t
{
	sf::RenderWindow *window;
	Level_t &level;

	std::list<std::unique_ptr<InterfaceBar>> barsList;

public:
	InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~InterfaceEngine_t();

	void update();
	void draw();

	void generateHPbars();
};

