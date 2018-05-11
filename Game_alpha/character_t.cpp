#include "character_t.h"
#include <iostream>



character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height), timer(_clock) {

	skill = std::move(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	buff = std::unique_ptr<Effect_t>(new Effect_t(this,this->getStats()));
	destroyble = true;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = false;
	fraction = 1;
	targetPos = spawnCoords = sf::Vector2f(_x, _y);
	clock = _clock;
	timer.attackCDcorrection(stat.attackSpeed);
	timer.castDelayCorrection(stat.castSpeed);
	skillGeneratorArr = std::list<elements::element>(elements::SKILL_ELEMENT_AMOUNT);

	moveRadius = 500.f;
}

character_t::character_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock) : physOb_t(_x, _y, _texture, _coordX, _coordY, _width, _height), timer(_clock) {
	
	skill = std::move(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	buff = std::unique_ptr<Effect_t>(new Effect_t(this, this->getStats()));
	destroyble = true;
	frame = .0f;
	direction = animation::BOTTOM;
	collision = false;
	fraction = 1;
	targetPos = spawnCoords = sf::Vector2f(_x, _y);
	clock = _clock;
	timer.attackCDcorrection(stat.attackSpeed);
	timer.castDelayCorrection(stat.castSpeed);
	skillGeneratorArr = std::list<elements::element>(elements::SKILL_ELEMENT_AMOUNT);

	moveRadius = 500.f;
}

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
void character_t::defaultAllStats() {
	stat.defaultAllStats();
}
bool character_t::kill() {
	alive = false;
	return false;
};

void character_t::update(float _speed) {
	checkAlive();
	if (alive) {

		physOb_t::update(_speed);

		if (buff.get()) {
			buff->checkActivity();
		}
	}
	
}


void character_t::animation() {


	int spriteCoordX = static_cast<int>(frame) * getWidth();
	int spriteCoordY = direction * getHeight();

	spritePref.setTexturePos(spriteCoordX, spriteCoordY);
}
void character_t::setSkills(std::initializer_list<size_t> _skillList) {
	elemStatus = *_skillList.begin();
}

std::vector<size_t> character_t::getSkillList() {
	return std::vector<size_t>(1,elemStatus);
}

bool character_t::checkAlive() {

	if (stat.HP < FLT_EPSILON) {
		alive = false;
	}

	return alive;
}


float character_t::takeDamage(float _dmg, bool _dmgType, elements::element _elem) {

	if (alive) {
		float tempDmg = 0.f;

		if (_dmgType) {
			tempDmg = (_elem == elements::NONE) ? (_dmg - abs(stat.physDef)) : (_dmg - abs(stat.magDef));
			if (tempDmg < 0) {
				tempDmg = 1.f;
			}

			stat.HP -= tempDmg;
			std::cout << tempDmg << " Dmg" << std::endl;
		}
		
		return tempDmg;
	}
	return 0.f;
}
float character_t::takeHeal(float _heal) {
	if (alive && stat.HP<stat.stdHP) {
		stat.HP += _heal;
	}
	return _heal;
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

	if (getFloatRect().intersects(Object.getCollisionRect())) {
		return true;
	}


	/*if ((abs(obCenterX - thisCenterX) < (thisWidth + obWidth - _borderError)) && (posY + getHeight() > Object.getPosY() + _borderError ) && 
		(Object.getPosY() + Object.getHeight() - borderError > posY - getHeight()/2 - 1.f)) {
		return true;
	}*/

	return false;
}




bool character_t::checkEnemy(character_t *ob) {


	float distanceX = (ob->getPosOfCenter().x )- (getPosOfCenter().x);
	float distanceY = (ob->getPosOfCenter().y) - (getPosOfCenter().y);
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (vectorLength < stat.visionDistance && ob->getAlive() && fraction != ob->getFraction()) {
		return true;
	}

	return false;
}


void character_t::changeState(CharacterState_t *newState) {
	state.reset();
	state = std::unique_ptr<CharacterState_t>(newState);
}
void character_t::changeEffect(Effect_t *newEffect) {
	buff.reset();
	buff = std::unique_ptr<Effect_t>(newEffect);
}

void character_t::attack() {

	//start cast
	if (timer.attackReady()) {
		timer.updateAttackCD();
		skill->useSkill();
	}
}


bool character_t::checkSkillGenerator() {

	if (skillGeneratorArr.size() == elements::SKILL_ELEMENT_AMOUNT) {
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
	if (skillGeneratorArr.size() >= elements::SKILL_ELEMENT_AMOUNT) {
		skillGeneratorArr.pop_front();
		skillGeneratorArr.push_back(_elem);
		return true;
	}
	return false;
}

void character_t::generateSkillAndClearElemList() {
	std::cout << "generated" << std:: endl;
	stat.MP = stat.stdMP;
	elemStatus = std::accumulate(skillGeneratorArr.begin(), skillGeneratorArr.end(), 0);
	resetElemsList();
}

void character_t::resetElemsList() {
	for (auto &i : skillGeneratorArr) {
		i = elements::NONE;
	}
}

void character_t::useMP(float _mp) {
	if (stat.MP > FLT_EPSILON) {
		stat.MP -= _mp;
	}
}

size_t character_t::setElemStatus(size_t _elemStatus) {
	elemStatus = _elemStatus;
	return elemStatus;
}