#include "character_t.h"



character_t::character_t():physOb_t()
{
	destroyble = true;
}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y) {
	destroyble = true;
}
//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height){
	destroyble = true;
}

//*/
character_t::~character_t()
{
}
