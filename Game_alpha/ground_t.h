#pragma once

#include "SFML\Graphics.hpp"
#include "physOb_t.h"
#include "additional.h"

class ground_t
{
	sf::Texture *texture;
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


	sf::Sprite getSprite() const {
		return sprite;
	}
};

