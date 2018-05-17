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


ground_t::ground_t(std::shared_ptr<sf::Texture>_texture, float _posX, float _posY, int _x, int _y, int _id)
{
	texture = std::shared_ptr<sf::Texture>(_texture);
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

//GET
	std::shared_ptr<sf::Texture> ground_t::getTexture() const {
		return texture;
	}

	sf::Sprite ground_t::getSprite() const {
		return sprite;
	}

	int ground_t::getCoordX() const {
		return spriteCoordX;
	}

	int ground_t::getCoordY() const {
		return spriteCoordY;
	}

	int ground_t::getHeight() const {
		return height;
	}

	int ground_t::getWidth() const {
		return width;
	}

	float ground_t::getPosX() const {
		return posX;
	}

	float ground_t::getPosY() const {
		return posY;
	}

	int ground_t::getId() const {
		return id;
	}
