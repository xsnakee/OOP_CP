#include "obPreference.h"

obPreference::obPreference() {

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("img/default.png");
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY,width,height));
}

obPreference::obPreference(std::string _fileTexturePath)
{

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(_fileTexturePath);

	sprite.setTexture(*texture);

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _width, int _height){

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	height = _height;
	width = _width;

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(_fileTexturePath);
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::obPreference(std::shared_ptr<sf::Texture>&_texture, int _coordX, int _coordY, int _width, int _height) {

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	height = _height;
	width = _width;

	texture = _texture;

	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::~obPreference()
{
	if (texture.use_count() < 2) {
		texture.~shared_ptr();
	}
}
