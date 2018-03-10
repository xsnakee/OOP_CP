#include "player_t.h"



player_t::player_t():character_t()
{
}


player_t::player_t(float _x, float _y): character_t(_x, _y){
	spriteCoordX = 110;
	spriteCoordY = 40;
	heigth = 135;
	width = 150;
	texture.loadFromFile("img/mainHeroSprite.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, HERO_SPRITE_HEIGHT, HERO_SPRITE_WIDTH));
	sprite.setPosition(posX, posY);
}

/*
player_t::player_t(float _x, float _y, obPreference_t spritePref): character_t(_x,_y, spritePref) {

	spriteCoordX = 110;
	spriteCoordY = 40;
	heigth = 135;
	width = 150;
	texture.loadFromFile("img/mainHeroSprite.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0,0,HERO_SPRITE_HEIGHT,HERO_SPRITE_WIDTH));
	sprite.setPosition(posX, posY);
}
//*/

player_t::~player_t()
{
}
