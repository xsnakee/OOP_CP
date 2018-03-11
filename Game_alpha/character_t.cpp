#include "character_t.h"



character_t::character_t():physOb_t(),dX(0.f),dY(0.f)
{
	destroyble = true;
}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y), dX(0.f), dY(0.f) {
	destroyble = true;
}
//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height), dX(0.f), dY(0.f){
	destroyble = true;
}

//*/
character_t::~character_t()
{
}
