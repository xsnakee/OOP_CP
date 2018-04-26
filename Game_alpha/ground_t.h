#pragma once

#include "SFML\Graphics.hpp"
#include <memory>
#include "physOb_t.h"
#include "additional.h"

class ground_t
{
	std::shared_ptr<sf::Texture> texture;
	sf::Sprite sprite;
	int spriteCoordX;
	int spriteCoordY;
	int height;
	int width;
	float posX;
	float posY;

	int id;

public:
	ground_t();
	ground_t(sf::Texture *_texture,float _posX, float _posY, int _x, int _y, int _id);
	~ground_t();


	//GET
	sf::Texture *getTexture() const {
		return texture.get();
	}

	sf::Sprite getSprite() const {
		return sprite;
	}

	int getCoordX() const {
		return spriteCoordX;
	}

	int getCoordY() const {
		return spriteCoordY;
	}

	int getHeight() const {
		return height;
	}

	int getWidth() const {
		return width;
	}

	float getPosX() const {
		return posX;
	}

	float getPosY() const {
		return posY;
	}

	int getId() const {
		return id;
	}
};

