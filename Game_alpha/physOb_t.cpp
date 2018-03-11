#include "physOb_t.h"

physOb_t::physOb_t():posX(0), posY(0)
{
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
}

physOb_t::physOb_t(float _posX, float _posY):posX(_posX), posY(_posY) {
	destroyble = true;
	alive = true;
	hitsToDestroy = 1.f;
	collision = true;
}
//*

physOb_t::physOb_t(float _posX, float _posY, obPreference spritePref):posX(_posX), posY(_posY) {

	spriteCoordX = spritePref.getCoordX();
	spriteCoordY = spritePref.getCoordY();
	heigth = spritePref.getHeight();
	width = spritePref.getWdith();

	texture = spritePref.getTexture();
	sprite = spritePref.getSprite();
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, heigth, width));

}
//*/
physOb_t::~physOb_t()
{
}
