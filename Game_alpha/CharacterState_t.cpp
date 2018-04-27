#include "CharacterState_t.h"



CharacterState_t::CharacterState_t(character_t *__mainCharacter)
{
	mainCharacter = __mainCharacter;
	targetOb = nullptr;
	stateNum = 0;
}


CharacterState_t::~CharacterState_t()
{
}

bool CharacterState_t::leaveFromSpot() {
	return false;
}