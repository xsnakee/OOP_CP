#include "character_t.h"
#include <iostream>


character_t::character_t():physOb_t()
{
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = sf::Vector2f(0.f,0.f);
	spawnCoords = sf::Vector2f(0.f, 0.f);

}

character_t::character_t(float _x, float _y) :physOb_t(_x, _y) {
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = sf::Vector2f(_x, _y);
	spawnCoords = sf::Vector2f(_x, _y);
}

//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height){
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = sf::Vector2f(_x, _y);
	spawnCoords = sf::Vector2f(_x, _y);
}

character_t::character_t(sf::Texture *_texture, float _x, float _y, int _coordX, int _coordY, int _width, int _height) : physOb_t(_x, _y, _texture, _coordX, _coordY, _width, _height) {
	destroyble = true;
	skill = nullptr;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = sf::Vector2f(_x, _y);
	spawnCoords = sf::Vector2f(_x, _y);
}

//*/
character_t::~character_t()
{
}



void character_t::setStats(characterStats_t &_stats) {

	stat = _stats;

}

characterStats_t character_t::getStats() {
	return stat;
}

void character_t::defaultStats() {
	stat.defaultStats();
}

bool character_t::kill() {
	alive = false;
	return false;
};

void character_t::update(float _speed) {
	if (alive) {

		physOb_t::update(_speed);
		updateFrame();
		animation();
	}
	
}


void character_t::animation() {


	int spriteCoordX = static_cast<int>(frame) * animation::MAIN_HERO_SPRITE_WIDTH;
	int spriteCoordY = direction * animation::MAIN_HERO_SPRITE_HEIGHT;

	spritePref.setTexturePos(spriteCoordX, spriteCoordY);
}

void character_t::updateFrame() {

	frame += animation::frameSpeed;
	if (frame > animation::frameRate) {
		frame -= animation::frameRate;
	}
}

bool character_t::checkAlive() {

	if (stat.HP < FLT_EPSILON) {
		alive = false;
	}

	return alive;
}


float character_t::takeDamage(float _dmg, bool _dmgType) {

	if (alive) {
		float tempDmg = (_dmgType) ? (abs(_dmg) - abs(stat.physDef)) : (abs(_dmg) - abs(stat.magDef));
		stat.HP -= tempDmg;
		std::cout << tempDmg << " Dmg" << std::endl;
		return tempDmg;
	}
	return 0.f;
}

float character_t::toHit() const{

	return stat.atackPower + getRand(-stat.damageRand, stat.damageRand);
}

bool character_t::checkCollision(physOb_t &Object, float _borderError) {
	float borderError = static_cast<float>(getHeight());

	float thisWidth = static_cast<float>(spritePref.getWidth()) / 2;
	float thisHeight = static_cast<float>(spritePref.getHeight()) / 2;
	float obWidth = static_cast<float>(Object.getWidth()) / 2;
	float obHeight = static_cast<float>(Object.getHeight()) / 2;

	float obCenterX = Object.getPosX() + obWidth;
	float obCenterY = Object.getPosY() + obHeight;

	float thisCenterX = posX + thisWidth;
	float thisCenterY = posY + thisHeight;

	if ((abs(obCenterX - thisCenterX) < (thisWidth + obWidth - _borderError)) && (posY + getHeight() > Object.getPosY() + _borderError ) && 
		(Object.getPosY() + Object.getHeight() - borderError > posY - 1.f)) {
		return true;
	}


	return false;
}




bool character_t::checkEnemy(character_t *ob) {


	float distanceX = ob->getPosX() - posX;
	float distanceY = ob->getPosY() - posY;
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (vectorLength < stat.visionDistance) {
		return true;
	}

	return false;
}


void character_t::changeState(CharacterState_t *newState) {
	state.reset();
	state = std::unique_ptr<CharacterState_t>(newState);
}