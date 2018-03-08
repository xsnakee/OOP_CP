#pragma once

#include <SFML/Graphics.hpp>
#include "additional.hpp"

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

class Character
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

	Character();
	~Character();

	void getKey(sf::Event::EventType);
	void move(float time);
	void update(float time);
};

