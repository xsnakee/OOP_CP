#include "ground_t.h"

ground_t::ground_t()
{
	texture = nullptr;
	int spriteCoordX = 0;
	int spriteCoordY = 0;
	int height = tiles::SPRITE_HEIGHT;
	int width = tiles::SPRITE_WIDTH;
	float posX = 0;
	float posY = 0;

	id = 0;

}


ground_t::ground_t(sf::Texture *_texture, int _posX, int _posY, int _x, int _y, int _id)
{
	texture = _texture;
	sprite.setTexture(*texture);
	spriteCoordX = _x;
	spriteCoordY = _y;

	height = tiles::SPRITE_HEIGHT;
	width = tiles::SPRITE_WIDTH;
	posX = _posX;
	posY = _posY;
	
	id = _id;

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
	sprite.setPosition(posX, posY);
}

ground_t::~ground_t()
{
}
