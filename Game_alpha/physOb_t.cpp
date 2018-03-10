#include "physOb_t.h"

physOb_t::physOb_t():posX(0), posY(0)
{
	destroyble = false;
	alive = true;
	hitsToDestroy = 1.f;
	collision = 0;
}

physOb_t::physOb_t(float _posX, float _posY):posX(_posX), posY(_posY) {

	destroyble = false;
	alive = true;
	hitsToDestroy = 1.f;
	collision = 0;
}
physOb_t::physOb_t(obPreference_t spritePref):physOb_t() {
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
