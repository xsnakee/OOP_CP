#ifndef _CHAR_T_H
#define _CHAR_T_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "addons.hpp"
#include "skill_t.h"

//*
class characterStats_t {
private:
	float HP;
	float AP;
	float atackPower;
	float physDef;
	float magDef;
	float stamina;
	float speed;
	float castSpeed;
	float damageRand;
	float attackMultiple;
	float defMulttiple;
	float attackRang;


};


class character_t {
protected:
	sf::Texture texture;
	float CoordX;
	float coordY;
	float dX;
	float dY;
	bool collision;
	float viewRange;
	characterStats_t stats;
	bool alive;
	bool godMode;


};


class NPC_t : public character_t {
public:
	bool alied;


};

class alied_t : public NPC_t {
public:
	std::vector<std::string> dialog;
};

class enemy_t : public NPC_t {
public:
	std::list<int> dropList;
	std::list<skill_t> skill;
};


class player_t : public character_t {
public:
	skill_t *curSkill;
	character::elements elPoints[character::ELEMENT_POINTS_AMOUNT];
};

//*/
#endif //_CHAR_T