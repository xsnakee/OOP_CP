#include "CharacterState_t.h"
#include <iostream>

CharacterState_t::CharacterState_t()
{
}




CharacterState_t::CharacterState_t(character_t *__mainCharacter)
{
	mainCharacter = __mainCharacter;
	targetCharacter = nullptr;
	stateNum = 0;
	moveXdistanceFromSpawn = 200.f;
	readyToFight = true;
}

CharacterState_t::CharacterState_t(CharacterState_t &_state)
{
	mainCharacter = _state.getCharacterPtr();
	targetCharacter = _state.getTargetCharacterPtr();
	stateNum = _state.stateNum;
	mainCharacter->setTargetCoords(_state.getCharacterPtr()->getTargetCoords());
	moveXdistanceFromSpawn = _state.moveXdistanceFromSpawn;
	readyToFight = true;
}

CharacterState_t::~CharacterState_t()
{
}

bool CharacterState_t::leaveFromSpot() {
	sf::Vector2f tempSpotVector = mainCharacter->getSpawnCoords();

	float distanceX = tempSpotVector.x - mainCharacter->getPosX();
	float distanceY = tempSpotVector.y - mainCharacter->getPosY();
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (vectorLength > mainCharacter->getMoveRadius()) {
		return true;
	}
	
	return false;
}

void CharacterState_t::reversXTrajectory() {
	moveXdistanceFromSpawn = -moveXdistanceFromSpawn;
}



//CHARACTER STATE MOVE

CharacterStateMove_t::CharacterStateMove_t(character_t *__mainCharacter) :CharacterState_t(__mainCharacter)
{
	stateNum = 0;
	targetCharacter = nullptr;

	mainCharacter->setTargetCoords(mainCharacter->getSpawnCoords());
	readyToFight = false;
}

CharacterStateMove_t::CharacterStateMove_t(CharacterState_t &_state) : CharacterState_t(_state) {
	stateNum = 0;
	targetCharacter = nullptr;

	mainCharacter->setTargetCoords(mainCharacter->getSpawnCoords());
	readyToFight = false;
}


CharacterStateMove_t::~CharacterStateMove_t()
{
}

void CharacterStateMove_t::Action() {

	float distanceX = mainCharacter->getTargetCoords().x - mainCharacter->getPosX();
	float distanceY = mainCharacter->getTargetCoords().y - mainCharacter->getPosY();
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if ((targetCharacter != nullptr) && (readyToFight)) {
		mainCharacter->changeState(new CharacterStateFolow_t(*this));
	}

		if (vectorLength > 1.f ) {

			float  kX = (distanceX / abs(distanceX)) * mainCharacter->getStats().speed;
			float  kY = (distanceY / abs(distanceY)) * mainCharacter->getStats().speed;
			
			
			if (abs(distanceX) > mainCharacter->getWidth() / 2) {
				if (abs(kX) > FLT_EPSILON) mainCharacter->setdX(kX);
			}
			else if (abs(distanceY) > mainCharacter->getHeight() / 2) {
					if (abs(kY) > FLT_EPSILON) mainCharacter->setdY(kY);
			}
			else {
				readyToFight = true;
			}
		}

		if (leaveFromSpot()) {
			mainCharacter->setTargetCoords(mainCharacter->getSpawnCoords());
			targetCharacter = nullptr;
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

void CharacterStateFolow_t::Action() 
{

	mainCharacter->setTargetCoords(targetCharacter->getCoordsOfCenter());
	float distanceX = targetCharacter->getCoordsOfCenter().x - mainCharacter->getCoordsOfCenter().x;
	float distanceY = targetCharacter->getCoordsOfCenter().y - mainCharacter->getCoordsOfCenter().y;
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	if (leaveFromSpot() ||  (vectorLength > mainCharacter->getStats().visionDistance )) {
		mainCharacter->setTargetCoords(mainCharacter->getSpawnCoords());
		mainCharacter->changeState(new CharacterStateMove_t(*this));
	}
	else {
		if (vectorLength < (mainCharacter->getStats().attackRange)) {
			mainCharacter->changeState(new CharacterStateAttack_t(*this));
		}

		float  kX = (distanceX / abs(distanceX)) * mainCharacter->getStats().speed;
		float  kY = (distanceY / abs(distanceY)) * mainCharacter->getStats().speed;

		
		if (abs(distanceX) > mainCharacter->getWidth() / 2) {
			if (abs(kX) > FLT_EPSILON) mainCharacter->setdX(kX);
		} else 
		if (abs(distanceY) > mainCharacter->getHeight() / 2) {
			if (abs(kY) > FLT_EPSILON) mainCharacter->setdY(kY);
		}
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
void CharacterStateAttack_t::Action() {

	float distanceX = targetCharacter->getCoordsOfCenter().x - mainCharacter->getCoordsOfCenter().x;
	float distanceY = targetCharacter->getCoordsOfCenter().y - mainCharacter->getCoordsOfCenter().y;
	float vectorLength = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	float visionMultiple = 2.f;

	mainCharacter->setTargetCoords(targetCharacter->getCoords());

	if (vectorLength > mainCharacter->getStats().visionDistance) {
			mainCharacter->changeState(new CharacterStateMove_t(*this));
	}
	else if (vectorLength > mainCharacter->getStats().attackRange){
		mainCharacter->changeState(new CharacterStateFolow_t(*this));
	}
	else {
		//std::cout << "So attacK!!!" << std::endl;
		mainCharacter->attack();
	}
}

void CharacterStateAttack_t::Action(std::list<bullet_t*> &obList) {

}

//CHARACTER STATE PLAYER CONTROLL

CharacterPlayerControll_t::CharacterPlayerControll_t(character_t *__mainCharacter): CharacterState_t(__mainCharacter)
{
	stateNum = 3;
}


CharacterPlayerControll_t::~CharacterPlayerControll_t()
{
}
void CharacterPlayerControll_t::Action() {
}
//*/