#include "ground_t.h"



ground_t::ground_t():physOb_t()
{
	destroyble = false;
	alive = true;
	hitsToDestroy = 1.f;
	collision = 0;
}


ground_t::ground_t(std::string tileFile, int ID, int _x, int _y)
{
	destroyble = false;
	alive = true;
	hitsToDestroy = 1.f;
	collision = 0;

	spriteCoordX = ID * tiles::size;
	spriteCoordY = (ID / 21) * ID * tiles::size;
	width = height = tiles::size;
	posX = _x * tiles::size;
	posY = _y * tiles::size;
	texture.loadFromFile(tileFile);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX,spriteCoordY,width,height));

}

ground_t::~ground_t()
{
}
