#pragma once

#include "addons.hpp"

class skill_t
{
	float damage;
	float range;
	float AOE;
	bool penetrate;
	elem::elements element;

public:
	skill_t();
	~skill_t();
};


class AOEskill_t : public skill_t {
	float AOErange;

};

