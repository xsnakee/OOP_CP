#include "character_t.h"



character_t::character_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : physOb_t(_x, _y, fileName, _coordX, _coordY, _width, _height), timer(_clock) {

	skill.swap(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	buff.swap(std::unique_ptr<Effect_t>(new Effect_t(this,this->getStats())));
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
	
	skill.swap(std::unique_ptr<skillObGenerator_t>(new skillObGenerator_t(this, _bulletList)));
	buff.swap(std::unique_ptr<Effect_t>(new Effect_t(this, this->getStats())));
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
	else if (stat.HP > stat.stdHP) {
		stat.HP = stat.stdHP;
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

bool character_t::checkCollision(physOb_t &Object) {

	if (getFloatRect().contains(Object.getPosOfCenter())){
		return true;
	}

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
	state.get_deleter();
	state.swap(std::unique_ptr<CharacterState_t>(newState));
}
void character_t::changeEffect(Effect_t *newEffect) {
	buff.get_deleter();
	buff.swap(std::unique_ptr<Effect_t>(newEffect));
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

void character_t::updateTimerDependenceStats() {
	timer.attackCDcorrection(stat.attackSpeed);
	timer.castDelayCorrection(stat.castSpeed);
}


//GET
characterStats_t &character_t::getStats() {
	return stat;
}
	
	Effect_t *character_t::getEffectPtr() {
		return buff.get();
	}

	character_t *character_t::getPtr() {
		return this;
	}

	sf::Vector2f character_t::getTargetPos()  {
		return targetPos;
	}

	sf::Vector2f character_t::getSpotCoords()  {
		return sf::Vector2f(1800.f,1800.f);
	}

	sf::Vector2f character_t::getSpawnCoords() {
		return spawnCoords;
	}


	float character_t::getMoveRadius() const {
		return moveRadius;
	}
	sf::Clock *character_t::getClockPtr() const {
		return clock;
	}


	size_t character_t::getElemStatus() const {
		return elemStatus;
	}

	characterTimers_t &character_t::getTimer() {
		return timer;
	}


	std::list<elements::element> character_t::getElements() {
		return skillGeneratorArr;
	}

	skillObGenerator_t *character_t::getSkillGeneratorPtr() {
		return skill.get();
	}

	float character_t::getComputedDmg() const {
		float tempDmg = stat.attackPower + getRand(-stat.damageRand, stat.damageRand);
		return tempDmg;
	}
	CharacterState_t *character_t::getState() const {
		return state.get();
	}

	//SET

	void character_t::setStats(characterStats_t &_stats) {

		stat = _stats;
		timer.attackCDcorrection(stat.attackSpeed);
		timer.castDelayCorrection(stat.castSpeed);
	}
	float character_t::setFrame(float _frame) {
		frame = _frame;
		return frame;
	}
	sf::Vector2f character_t::setTargetPos(sf::Vector2f _targetPos) {
		targetPos = _targetPos;
		return targetPos;
	}



	void character_t::setMoveRadius(float _radius) {
		moveRadius = _radius;
	}