#pragma once

#include "addons.hpp"

class skill_t
{
	float damage;
	float range;
	float AOE;
	bool penetrate;
	character::elements element;

public:
	skill_t();
	~skill_t();
};


class AOEskill_t : public skill_t {
	float AOErange;

};

class effect_t {
	sf::Clock timer;


};

