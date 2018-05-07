#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "additional.h"

class InterfaceContent
{
protected:
	sf::RenderWindow *window;
	sf::Vector2f defaultCoords;
	sf::Vector2f relativePos;
	sf::Vector2u sizes;

public:
	InterfaceContent(sf::RenderWindow *_window, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos);
	virtual ~InterfaceContent();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void toDefaultPosition() = 0;

	void setRelativePos(sf::Vector2f newCoords) {
		relativePos = newCoords;
	}
	
	virtual void setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
	}
};


class InterfaceSpriteOb_t : public InterfaceContent {
public:
	std::unique_ptr<sf::Texture> texture;
	sf::Sprite sprite;
public:
	InterfaceSpriteOb_t(sf::RenderWindow *_window, sf::Texture *_texture, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos);
	virtual ~InterfaceSpriteOb_t();

	virtual void update();
	virtual void draw();
	virtual void toDefaultPosition();

	//GET
	sf::Sprite getSprite() const {
		return sprite;
	}


	//SET
	void setTexture(sf::Texture *newTexture);

	virtual void setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
		sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));
	}
};