#include "obPreference.h"


obPreference_t::obPreference_t() {

}

obPreference_t::obPreference_t(std::string _fileTexturePath)
{
	spriteCoordX = 0;
	spriteCoordY = 0;
	heigth = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;

	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));

}

obPreference_t::obPreference_t(std::string _fileTexturePath,
	size_t _coordX,
	size_t _coordY,
	size_t _heigth,
	size_t _width):spriteCoordX(_coordX),
	spriteCoordY(_coordY),heigth(_heigth),
	width(_width){
	
	texture.loadFromFile(_fileTexturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));
}

obPreference_t::~obPreference_t()
{
}
