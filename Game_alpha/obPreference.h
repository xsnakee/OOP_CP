#pragma once

#include <SFML\Graphics.hpp>

const int SPRITE_HEIGHT = 32;
const int SPRITE_WIDTH = 32;

class obPreference
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	int spriteCoordX;
	int spriteCoordY;
	int height;
	int width;

public:
	obPreference();
	obPreference(std::string _fileTexturePath);
	obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _height, int _width);
	virtual ~obPreference();

	//GET
	sf::Texture getTexture() const{
		return texture;
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
	int getWdith() const {
		return width;
	}

	//FOR CHECK COLLISION
	sf::FloatRect getRect()const {
		sf::FloatRect rect(spriteCoordX, spriteCoordY, width, height);
		return rect;
	}
};

