#pragma once
#include <SFML\Graphics.hpp>
#include "InterfaceButton.h"
#include "cursor_t.h"

typedef std::unique_ptr<InterfaceButton> button;

class mouseController
{
	sf::RenderWindow *window;
	std::list<button> &buttonList;
	cursor_t &cursor;
public:
	mouseController(sf::RenderWindow *_window, std::list<button> &_buttonList, cursor_t &_cursor);
	virtual ~mouseController();

	virtual void eventHandler(sf::Event &event);
};

