#include "obPreference.h"

obPreference::obPreference() {

	spriteCoordX = 0;
	spriteCoordY = 0;
	heigth = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;
	texture.loadFromFile("img/default.jpg");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));
}

obPreference::obPreference(std::string _fileTexturePath)
{

	spriteCoordX = 0;
	spriteCoordY = 0;
	heigth = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;

	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));

}

obPreference::obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _heigth, int _width){

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	heigth = _heigth;
	width = _width;
	
	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));
}

obPreference::~obPreference()
{
}
