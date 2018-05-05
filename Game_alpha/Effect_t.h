#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"
class Effect_t
{
	character_t *character;

public:
	sf::Int32 startTime;
	sf::Int32 duration;
	bool activity;

	Effect_t(character_t *_character, characterStats_t stat, sf::Int32 _duration = 5000);
	void useEffect(characterStats_t &stat);
	virtual ~Effect_t();

	bool timeIsOver();
	void cancelEffect();
};

