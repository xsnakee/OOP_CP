#pragma once

#include "SFML\Graphics.hpp"
#include "physOb_t.h"
#include "additional.h"

class ground_t:public physOb_t
{

public:
	ground_t();
	ground_t(std::string tileFile, int ID, int _x, int _y);
	~ground_t();
};

