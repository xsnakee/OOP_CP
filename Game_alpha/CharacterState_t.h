#pragma once

#include "character_t.h"
#include "bullet_t.h"
#include <list>
#include <memory>

class character_t;

class CharacterState_t
{
protected:
	int stateNum;
	character_t *mainCharacter;
	character_t *targetCharacter;
	sf::Vector2f targetCoords;

	float moveXdistanceFromSpawn;

	CharacterState_t();
	CharacterState_t(character_t *_targetOb);
	CharacterState_t(CharacterState_t &_state);

public:

	virtual ~CharacterState_t();
	virtual void Action() = 0;

	bool leaveFromSpot();
	void reversXTrajectory();




	character_t *getCharacterPtr() const {
		return mainCharacter;
	}
	character_t *getTargetCharacterPtr()const {
		return targetCharacter;
	}
	int getStateNum() const {
		return stateNum;
	}
	sf::Vector2f getTargetCoords() const {
		return targetCoords;
	}

	sf::Vector2f setTargetCoords(sf::Vector2f _targetCoords) {
		targetCoords = _targetCoords;
		return targetCoords;
	}
	void setTargetCharacter(character_t *character) {
		targetCharacter = character;
	}

};




class CharacterStateMove_t :
	public CharacterState_t
{
public:
	CharacterStateMove_t(character_t *__mainCharacter);
	CharacterStateMove_t(CharacterState_t &_state);
	virtual ~CharacterStateMove_t();

	virtual void Action();
};



class CharacterStateFolow_t :
	public CharacterState_t
{
public:
	CharacterStateFolow_t(character_t *__mainCharacter);
	CharacterStateFolow_t(CharacterState_t &_state);
	virtual ~CharacterStateFolow_t();

	virtual void Action();
};




class CharacterStateAttack_t :
	public CharacterState_t
{
public:
	CharacterStateAttack_t(character_t *__mainCharacter);
	CharacterStateAttack_t(CharacterState_t &_state);
	virtual ~CharacterStateAttack_t();

	virtual void Action();
	void Action(std::list<bullet_t*> &obList);
};


//PLAYER

class CharacterPlayerControll_t :
	public CharacterState_t
{
public:
	CharacterPlayerControll_t(character_t *__mainCharacter);
	virtual ~CharacterPlayerControll_t();

	virtual void Action();
};
//*/