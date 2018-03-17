#include "ground_t.h"

ground_t::ground_t():physOb_t()
{
	destroyble = false;
	alive = true;
	hitsToDestroy = 0.f;
	collision = 0;
}


ground_t::ground_t(float _posX, float _posY, std::string tileFile, int _x, int _y):physOb_t(_posX, _posY, tileFile, _x, _y, tiles::size, tiles::size)
{
	destroyble = false;
	alive = true;
	hitsToDestroy = 0.f;
	collision = 0;
}

ground_t::~ground_t()
{
}
