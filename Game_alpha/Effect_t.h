#pragma once
#include <SFML/Graphics.hpp>
#include "character_t.h"
class Effect_t
{
	character_t *character;

public:
	sf::Int32 startTime;
	sf::Int32 duration;
	characterStats_t stat;
	bool activity;

	Effect_t(character_t *_character, characterStats_t _stats, sf::Int32 _duration = 5000);
	virtual ~Effect_t();

	void useEffect();
	bool timerIsOver();
	void cancelEffect();
	void checkActivity();
};

