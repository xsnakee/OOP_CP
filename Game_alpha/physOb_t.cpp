#include "physOb_t.h"

physOb_t::physOb_t()
{
	destroyble = false;
	alive = true;
	HP = 1.f;
	collision = 0;
}


physOb_t::physOb_t(std::string _fileTexturePath) : obPreference_t(_fileTexturePath){
	destroyble = false;
	alive = true;
	HP = 1.f;
	collision = 0;
}


physOb_t::physOb_t(obPreference_t spritePref) {
	spriteCoordX = spritePref.getCoordX();
	spriteCoordY = spritePref.getCoordY();
	heigth = spritePref.getHeight();
	width = spritePref.getWdith();

	texture = spritePref.getTexture();
	sprite = spritePref.getSprite();

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));
}

physOb_t::~physOb_t()
{
}
