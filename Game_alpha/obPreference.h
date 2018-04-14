#pragma once

#include <SFML\Graphics.hpp>
const int DEFAULT_HEIGHT = 31;
const int DEFAULT_WIDTH = 27;

class obPreference
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int spriteCoordX;
	int spriteCoordY;
	int height;
	int width;

public:
	obPreference();
	obPreference(std::string _fileTexturePath);
	obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _width, int _height);
	virtual ~obPreference();

	//GET
	sf::Texture getTexture() const{
		return texture;
	}

	sf::Sprite getSprite() const{
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

	//SET
	void setTexturePos(int coordX, int coordY) {
		spriteCoordX = coordX;
		spriteCoordY = coordY;
	}

	void setSpritePos(int coordX, int coordY) {
		sprite.setPosition(coordX, coordY);
	}

	//FOR CHECK COLLISION
	sf::FloatRect getRect()const {
		sf::FloatRect rect(static_cast<float>(spriteCoordX), static_cast<float>(spriteCoordY), static_cast<float>(width), static_cast<float>(height));
		return rect;
	}
};

