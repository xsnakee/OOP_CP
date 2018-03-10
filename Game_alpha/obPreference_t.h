#pragma once

#include <SFML\Graphics.hpp>

const size_t SPRITE_HEIGHT = 32;
const size_t SPRITE_WIDTH = 32;

class obPreference_t
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	size_t spriteCoordX;
	size_t spriteCoordY;
	size_t heigth;
	size_t width;

public:
	obPreference_t();
	obPreference_t(std::string _fileTexturePath);
	obPreference_t(std::string _fileTexturePath, size_t _coordX, size_t _coordY, size_t _heigth, size_t _width);
	virtual ~obPreference_t();

	//GET
	sf::Texture getTexture() const{
		return texture;
	}

	sf::Sprite getSprite() const {
		return sprite;
	}

	size_t getCoordX() const {
		return spriteCoordX;
	}
	size_t getCoordY() const {
		return spriteCoordY;
	}
	size_t getHeight() const {
		return spriteCoordX;
	}
	size_t getWdith() const {
		return spriteCoordX;
	}
};

