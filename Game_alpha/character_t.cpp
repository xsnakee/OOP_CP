#include "character_t.h"
#include <iostream>



//*
character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height), timer(_clock) {

	skill = std::move(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	destroyble = true;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = spawnCoords = sf::Vector2f(_x, _y);
	clock = _clock;
}

character_t::character_t(sf::Texture *_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock) : physOb_t(_x, _y, _texture, _coordX, _coordY, _width, _height), timer(_clock) {
	
	skill = std::move(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	destroyble = true;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = true;
	fraction = 1;
	targetCoords = spawnCoords = sf::Vector2f(_x, _y);
	clock = _clock;
}

//*/
character_t::~character_t()
{
}



void character_t::setStats(characterStats_t &_stats) {

	stat = _stats;

}

characterStats_t &character_t::getStats() {
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
		float tempDmg = (_dmgType) ? (_dmg - abs(stat.physDef)) : (_dmg - abs(stat.magDef));
		if (tempDmg < 0){
			tempDmg = 0.f;
		}
		
		stat.HP -= tempDmg;
		std::cout << tempDmg << " Dmg" << std::endl;
		return tempDmg;
	}
	return 0.f;
}

float character_t::toHit() const{

	return stat.attackPower + getRand(-stat.damageRand, stat.damageRand);
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


	float distanceX = (ob->getCoordsOfCenter().x )- (getCoordsOfCenter().x);
	float distanceY = (ob->getCoordsOfCenter().y) - (getCoordsOfCenter().y);
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

void character_t::attack() {

	//*start cast
	if (timer.attackReady()) {
		timer.updateAttackCD();
		std::cout << "Attacked!!" << std::endl;
	}
}


bool character_t::checkSkillGenerator() {
	if (skillGeneratorArr.size() == 3) {
		std::list<elements::element>::iterator temp = skillGeneratorArr.begin();

		for (size_t i = 0; i < skillGeneratorArr.size(); ++i, ++temp) {
			if ((*temp) == elements::NONE) return false;
		}

		return true;
	}
	else {
		return false;
	}
	
}

bool character_t::addElement(elements::element _elem) {
	if (skillGeneratorArr.size() < 3) {
		skillGeneratorArr.push_back(_elem);
		return true;
	}
	else {
		skillGeneratorArr.pop_front();
		skillGeneratorArr.push_back(_elem);
		return true;
	}
	return false;
}

void character_t::generateSkillAndClearElemList() {
	std::cout << "generated" << std:: endl;
	elemStatus = std::accumulate(skillGeneratorArr.begin(), skillGeneratorArr.end(), 0);
	skillGeneratorArr.clear();
}