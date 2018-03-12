#pragma once

#include <SFML\Graphics.hpp>
#include "physOb_t.h"
#include "additional.h"

class bullet_t:public physOb_t
{
	elements::element element;

public:
	bullet_t();
	~bullet_t();
};

