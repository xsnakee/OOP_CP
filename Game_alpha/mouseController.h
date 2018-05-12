#pragma once
#include <SFML\Graphics.hpp>
#include "InterfaceButton.h"
#include "game_t.h"
#include "cursor_t.h"

typedef std::unique_ptr<InterfaceButton> button;
class game_t;

class mouseController
{
	sf::RenderWindow *window;
	game_t *game;
	cursor_t &cursor;
public:
	mouseController(sf::RenderWindow *_window, game_t *_game, cursor_t &_cursor);
	~mouseController();

	void eventHandler(sf::Event &event);
	void menuEventHandler(sf::Event &event);
};

