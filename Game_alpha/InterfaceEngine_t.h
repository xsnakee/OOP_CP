#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <iterator>
#include <memory>
#include "Level_t.h"
#include "InterfaceWindow_t.h"
#include "InterfaceBar.h"

typedef std::unique_ptr<InterfaceBar> bar_t;
typedef std::unique_ptr<InterfaceWindow_t> window_t;

class InterfaceEngine_t
{
	sf::RenderWindow *window;
	Level_t &level;

	std::list<bar_t> barsList;
	std::list<window_t> windowsList;


	//Iterators
	std::list<window_t>::iterator elemIt;

public:
	InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~InterfaceEngine_t();

	void update();
	void draw();

	void generateHPbars();
	void setObservedBards();
	void createIterface();

	void changeElements();
};

