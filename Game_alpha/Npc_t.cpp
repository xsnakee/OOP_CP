#include "Npc_t.h"



Npc_t::Npc_t()
{
}


Npc_t::Npc_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height) :character_t(_texture,_x,_y,_coordX,_coordY, _width, _height)
{
}


Npc_t::~Npc_t()
{
}
