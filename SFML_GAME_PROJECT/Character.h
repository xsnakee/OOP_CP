#pragma once

#include <SFML/Graphics.hpp>

class CharacterStats {
public:
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
	CharacterStats stats;
	bool alive;
	bool godMode;

	Character();
	~Character();
};

