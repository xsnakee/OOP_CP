#pragma once

#include <SFML/Graphics.hpp>
#include "additional.hpp"
const size_t ELEMS_AMOUNT = 3;

class CharacterStats {
public:
	float HP;
	float stdHP;

	float AP;
	float stdAP;

	float stamina;
	float stdStamina;

	float atackPower;
	float stdAtackPower;

	float physDef;
	float stdPhysDef;

	float magDef;
	float stdMagDef;	

	float speed;
	float stdSpeed;

	float castSpeed;
	float damageRand;

	float attackMultiple;
	float defMulttiple;
	float attackRang;

	CharacterStats();
	virtual ~CharacterStats();
};

class Character_t
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	float coordX;
	float coordY;
	float dX;
	float dY;
	bool collision;
	float viewRange;
	CharacterStats stat;
	bool alive;
	bool godMode;
	characterAddons::direction dir;

	Character_t();
	virtual ~Character_t();
	virtual void getKey(sf::Event);
	virtual void move(float time);
	virtual void update(float time);
};

class NPC_t : public Character_t {

protected: 
	bool alied;

	NPC_t();
	virtual ~NPC_t();

	virtual void move(float time) = 0;
	virtual void update(float time) = 0;

	void traectory();
};

class enemy_t : public NPC_t {
private:	
	//std::vector<Skill_t> cSkills;
public:
	std::vector<size_t> dropList;

	enemy_t();
	virtual ~enemy_t();

	virtual void move(float time) = 0;
	virtual void update(float time) = 0;
};

class Player_t : public Character_t {
	//Skill_t curSkill;
	characterAddons::elements element[ELEMS_AMOUNT];
public:


	Player_t();
	~Player_t();



	void getKey(sf::Event);
	virtual void move(float time);
	virtual void update(float time);
};