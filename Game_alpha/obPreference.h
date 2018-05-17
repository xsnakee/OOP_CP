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

	void setOriginToCenter();
	//GET
	std::shared_ptr<sf::Texture> &getTextureSharedPtr();
	sf::Texture getTexture() const;
	sf::Sprite &getSprite();
	int getCoordX() const;
	int getCoordY() const;
	int getHeight() const;
	int getWidth() const;

	//SET
	void setTexturePtr(std::shared_ptr<sf::Texture> &newTexture);

	void setTexturePos(int coordX, int coordY);
	void setSize( int newWidth,int newHeight);
	void setSpritePos(float coordX, float coordY);
	void setRotation(float _rotation);

	//FOR CHECK COLLISION
	sf::FloatRect getRect()const;
};

