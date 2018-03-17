#include "obPreference.h"

obPreference::obPreference() {

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;

	texture.loadFromFile("img/default.jpg");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, height, width));
}

obPreference::obPreference(std::string _fileTexturePath)
{

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;

	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, height, width));
}

obPreference::obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _height, int _width){

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	height = _height;
	width = _width;
	
	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, height, width));
}

obPreference::~obPreference()
{
}
