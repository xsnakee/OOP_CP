#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <memory>
#include "Level_t.h"
#include "InterfaceOb_t.h"
#include "InterfaceBar.h"


typedef std::unique_ptr<InterfaceBar> bar_t;
typedef std::unique_ptr<InterfaceOb_t> interfaceWindow_t;

class InterfaceEngine_t
{
	sf::RenderWindow *window;
	Level_t &level;

	std::list<bar_t> barsList;
	std::list<interfaceWindow_t> windowsList;

public:
	InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~InterfaceEngine_t();

	void update();
	void draw();

	void generateHPbars();
	void setObservedBards();
	void createIterfaceWindows();
};

