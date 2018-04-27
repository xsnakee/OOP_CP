#include "CharacterState_t.h"


CharacterState_t::CharacterState_t()
{
}




CharacterState_t::CharacterState_t(character_t *__mainCharacter)
{
	mainCharacter = __mainCharacter;
	stateNum = 0;
	targetCoords = sf::Vector2f(mainCharacter->getPosX(), mainCharacter->getPosY());
}

CharacterState_t::CharacterState_t(CharacterState_t &_state)
{
	mainCharacter = _state.getCharacterPtr();
	stateNum = _state.stateNum;
	targetCoords = _state.targetCoords;
}

CharacterState_t::~CharacterState_t()
{
}

bool CharacterState_t::leaveFromSpot() {
	sf::Vector2f tempSpotVector = mainCharacter->getSpotCoords();

	float distanceX = tempSpotVector.x - mainCharacter->getPosX();
	float distanceY = tempSpotVector.y - mainCharacter->getPosY();
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (vectorLength > mainCharacter->getMoveRadius()) {
		return true;
	}
	
	return false;
}




//CHARACTER STATE MOVE

CharacterStateMove_t::CharacterStateMove_t(character_t *__mainCharacter) :CharacterState_t(__mainCharacter)
{
	stateNum = 0;
}

CharacterStateMove_t::CharacterStateMove_t(CharacterState_t &_state) : CharacterState_t(_state) {
	stateNum = 0;
}


CharacterStateMove_t::~CharacterStateMove_t()
{
}

void CharacterStateMove_t::Action(std::list<std::unique_ptr<character_t>> &charList) {
	sf::Vector2f tempSpawntVector = mainCharacter->getSpawnCoords();

	float distanceX = tempSpawntVector.x - mainCharacter->getPosX();
	float distanceY = tempSpawntVector.y - mainCharacter->getPosY();
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (leaveFromSpot()) {
		setTargetCoords(tempSpawntVector);
	}
	else {

		for (auto &i : charList) {
			if ((mainCharacter->getFraction() != i.get()->getFraction()) && (mainCharacter->checkEnemy(i.get()))) {
				targetCoords = i.get()->getCoords();
				mainCharacter->changeState(new CharacterStateFolow_t(*this));
				delete this;
				return;
			}
		}

		float  kX = distanceX / abs(distanceX);
		float  kY = distanceY / abs(distanceY);

		mainCharacter->setdX(kX * mainCharacter->getStats().speed);
		mainCharacter->setdY(kY * mainCharacter->getStats().speed);
	}	
}

//CHARACTER STATE FOLOW



CharacterStateFolow_t::CharacterStateFolow_t(character_t *__mainCharacter) :CharacterState_t(__mainCharacter)
{
	stateNum = 1;
}

CharacterStateFolow_t::CharacterStateFolow_t(CharacterState_t &_state) : CharacterState_t(_state) {
	stateNum = 1;
}


CharacterStateFolow_t::~CharacterStateFolow_t()
{
}

void CharacterStateFolow_t::Action(std::list<std::unique_ptr<character_t>> &charList) {
	
	float distanceX = targetCoords.x - mainCharacter->getPosX();
	float distanceY = targetCoords.y - mainCharacter->getPosY();
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	float visionMultiple = 2.f;

	if (leaveFromSpot() || (vectorLength > mainCharacter->getStats().visionDistance * visionMultiple)) {
		mainCharacter->changeState(new CharacterStateMove_t(*this));
		delete this;
		return;
	}
	else {

		if (vectorLength < mainCharacter->getStats().attackRange) {
			mainCharacter->changeState(new CharacterStateAttack_t(*this));
			delete this;
			return;
		}

		float  kX = distanceX / abs(distanceX);
		float  kY = distanceY / abs(distanceY);

		mainCharacter->setdX(kX * mainCharacter->getStats().speed);
		mainCharacter->setdY(kY * mainCharacter->getStats().speed);
	}
}


//CHARACTER STATE ATTACK

CharacterStateAttack_t::CharacterStateAttack_t(character_t *__mainCharacter) :CharacterState_t(__mainCharacter)
{
	stateNum = 2;
}

CharacterStateAttack_t::CharacterStateAttack_t(CharacterState_t &_state) : CharacterState_t(_state) {
	stateNum = 2;
}


CharacterStateAttack_t::~CharacterStateAttack_t()
{
}
void CharacterStateAttack_t::Action(std::list<std::unique_ptr<character_t>> &charList) {
}

void CharacterStateAttack_t::Action(std::list<bullet_t*> &obList) {

}

//CHARACTER STATE PLAYER CONTROLL

CharacterPlayerControll_t::CharacterPlayerControll_t(character_t *__mainCharacter) :CharacterState_t(__mainCharacter)
{
	stateNum = 3;
}


CharacterPlayerControll_t::~CharacterPlayerControll_t()
{
}
void CharacterPlayerControll_t::Action(std::list<std::unique_ptr<character_t>> &charList) {
}
//*/