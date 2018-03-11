#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "character_t.h"
#include "player_t.h"

class game_t
{
public:
	std::vector<character_t*> charactersList;

	game_t();
	~game_t();

	void draw(sf::RenderWindow *_window);
};

