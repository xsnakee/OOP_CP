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

}


ground_t::ground_t(sf::Texture *_texture, float _posX, float _posY, int _x, int _y)
{
	texture = _texture;
	sprite.setTexture(*texture);
	int spriteCoordX = _x;
	int spriteCoordY = _y;

	int height = tiles::SPRITE_HEIGHT;
	int width = tiles::SPRITE_WIDTH;
	float posX = _posX;
	float posY = _posY;

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
	sprite.setPosition(posX, posY);
}

ground_t::~ground_t()
{
}
