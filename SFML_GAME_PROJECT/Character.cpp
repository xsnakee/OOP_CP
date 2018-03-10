#include "Character.h"


//CHARACTER_STATS
CharacterStats::CharacterStats()
{
	HP = stdHP = 100.F;
	AP = stdAP = 5.F;
	stamina = stdStamina = 100.f;
	atackPower = stdAtackPower = 1.f;
	physDef = stdPhysDef = 1.f;
	magDef = stdMagDef = 1.f;
	speed = stdSpeed = 0.f;
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

Character_t::Character_t()
{
	alive = true;
	coordX = 10.f;
	coordY = 10.f;

	
	texture.loadFromFile("img/hero_sprite.png");//load texture
	sprite.setTexture(texture);//load texture to sprite
	sprite.setTextureRect(sf::IntRect(104, 30, 135, 150));//set texture height, width from img
	sprite.setPosition(coordX, coordY);//set coords

	sprite.scale(0.5f,0.5f);//temp_funct zoomOut(0.5)

	dX = 0.f;
	dY = 0.f;

	dir = characterAddons::RIGHT;
	collision = true;
	viewRange = 20.f;
	godMode = false;
}
void Character_t::getKey(sf::Event) {

	using namespace sf;

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		stat.speed = 0.1f;
		dir = characterAddons::TOP;
		dY = -stat.speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {

		stat.speed = 0.1f;
		dir = characterAddons::RIGHT;
		dX = stat.speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {

		stat.speed = 0.1f;
		dY = stat.speed;
		dir = characterAddons::DOWN;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		stat.speed = 0.1f;
		dX = -stat.speed;
		dir = characterAddons::LEFT;
	}
}
void Character_t::move(float time) {

		coordX += dX*time;
	coordY += dY*time;

	stat.speed = stat.stdSpeed;
	sprite.setPosition(coordX, coordY);
}


void Character_t::update(float time) {
	this->move(time);
	
}

Character_t::~Character_t()
{
}
