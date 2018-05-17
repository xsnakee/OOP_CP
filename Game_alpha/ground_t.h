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
	ground_t(std::shared_ptr<sf::Texture>_texture,float _posX, float _posY, int _x, int _y, int _id);
	~ground_t();


	//GET
	std::shared_ptr<sf::Texture> getTexture() const;
	sf::Sprite getSprite() const;
	int getCoordX() const;
	int getCoordY() const;
	int getHeight() const;
	int getWidth() const;
	float getPosX() const;
	float getPosY() const;
	int getId() const;
};

