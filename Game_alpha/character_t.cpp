#include "character_t.h"



character_t::character_t():physOb_t(),dX(0.f),dY(0.f)
{
}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y), dX(0.f), dY(0.f) {

}
//*
character_t::character_t(float _x, float _y, obPreference spritePref) : physOb_t(_x, _y, spritePref), dX(0.f), dY(0.f){

}

//*/
character_t::~character_t()
{
}
