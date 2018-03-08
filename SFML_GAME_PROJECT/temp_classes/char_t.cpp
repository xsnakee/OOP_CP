#ifndef _CHAR_T
#define _CHAR_T

#include "char_t.hpp"

//*
// characterStats_t
characterStats_t::characterStats_t() {
	HP = 100.F;
	AP = 5.F;
	atackPower = 1.f;
	physDef = 1.f;
	magDef = 1.f;
	stamina = 100.f;
	speed = 1.f;
	castSpeed = 1.f;
	damageRand = 5.f;
	attackMultiple = 1.f;
	defMulttiple = 1.f;
	attackRang = 20.f;

}

// character_t
character_t::character_t() {
	alive = true;
	coordX = 10.f;
	coordY = 10.f;

	//texture.loadFromFile();
	sprite.setTexture(texture);
	sprite.setPosition(coordX,coordY);
	dX = 0.1f;
	dY = 0.1f;
	collision = true;
	viewRange = 20.f;
	godMode = false;
}



//class NPC_t: public character_t;



//class alied_t: public NPC_t;

//class enemy_t: public NPC_t;


player_t::player_t():character_t() {

}


//*/
#endif //_CHAR_T