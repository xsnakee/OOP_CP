#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Character.h"

class Game
{
public:
	std::vector<Character_t*> charList;
	Game();
	~Game();
};

