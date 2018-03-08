#include "Character.h"


//CHARACTER_STATS
CharacterStats::CharacterStats()
{
	HP = 100.F;
	AP = 5.F;
	atackPower = 1.f;
	physDef = 1.f;
	magDef = 1.f;
	stamina = 100.f;
	speed = 1.f;
	castSpeed = 1.f;
	damageRand = 5.f;
	attackMultiple = 1.f;
	defMulttiple = 1.f;
	attackRang = 20.f;
}


CharacterStats::~CharacterStats()
{
}


//CHARACTER

Character::Character()
{
	alive = true;
	coordX = 10.f;
	coordY = 10.f;

	
	texture.loadFromFile("img/hero_sprite.png");//load texture
	sprite.setTexture(texture);//load texture to sprite
	sprite.setTextureRect(sf::IntRect(104, 30, 135, 150));//set texture height, width from img
	sprite.setPosition(coordX, coordY);//set coords

	sprite.scale(0.5f,0.5f);//temp_funct zoomOut(0.5)

	dX = 0.1f;
	dY = 0.1f;
	collision = true;
	viewRange = 20.f;
	godMode = false;
}


Character::~Character()
{
}
