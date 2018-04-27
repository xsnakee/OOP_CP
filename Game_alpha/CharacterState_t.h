#pragma once

#include "character_t.h"
#include <list>
#include <memory>


class CharacterState_t
{
	character_t *mainCharacter;
	std::shared_ptr<character_t> targetOb;
	int stateNum;

public:
	CharacterState_t(character_t *_targetOb);
	virtual ~CharacterState_t();

	character_t *getTargetObPtr()const {
		return targetOb.get();
	}

	int getStateNum() const {
		return stateNum;
	}



	virtual void Action(std::list<std::unique_ptr<character_t>> &charList) = 0;
	virtual void changeState(CharacterState_t *_state) = 0;
	bool leaveFromSpot();

};

