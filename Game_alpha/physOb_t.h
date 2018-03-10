#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"


class physOb_t : public obPreference_t
{
protected:
	bool destroyble;
	bool alive;
	float HP;
	bool collision;
public:

	physOb_t();
	physOb_t(std::string _fileTexturePath);
	physOb_t(obPreference_t spritePref);

	~physOb_t();
};

