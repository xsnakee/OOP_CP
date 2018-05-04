#pragma once

#include <SFML\Graphics.hpp>
#include <memory>

const int DEFAULT_HEIGHT = 32;
const int DEFAULT_WIDTH = 32;

class obPreference
{
private:
	std::shared_ptr<sf::Texture> texture;
	sf::Sprite sprite;

	int spriteCoordX;
	int spriteCoordY;
	int height;
	int width;

public:
	obPreference();
	obPreference(std::string _fileTexturePath);
	obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _width, int _height);
	obPreference(std::shared_ptr<sf::Texture>&_texture, int _coordX, int _coordY, int _width, int _height);

	virtual ~obPreference();

	//GET
	sf::Texture getTexture() const{
		return *texture;
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
	int getWidth() const {
		return width;
	}

	//SET
	void setTexturePtr(std::shared_ptr<sf::Texture> &newTexture) {
		texture = newTexture;
		sprite.setTexture(*texture);
	}

	void setTexturePos(int coordX, int coordY) {
		spriteCoordX = coordX;
		spriteCoordY = coordY;
		sprite.setTextureRect(sf::IntRect(coordX,coordY,width,height));
	}

	void setSpritePos(float coordX, float coordY) {
		sprite.setPosition(coordX, coordY);
	}

	void setRotation(float _rotation) {
		sprite.setRotation(_rotation);
	}

	void setCenterWithOrigin() {
		sprite.setOrigin(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
	}
	//FOR CHECK COLLISION
	sf::FloatRect getRect()const {
		sf::FloatRect rect(static_cast<float>(spriteCoordX), static_cast<float>(spriteCoordY), static_cast<float>(width), static_cast<float>(height));
		return rect;
	}
};

