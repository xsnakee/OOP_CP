#pragma once
#include <SFML/Graphics.hpp>

namespace characterAddons {
	const size_t ELEMENT_POINTS_AMOUNT = 3;

	enum elements {
		NONE,
		WIND,
		WATER,
		EARTH,
		FIRE
	};

	enum direction {
		TOP,
		RIGHT,
		DOWN,
		LEFT,

		TOP_RIGHT,
		DOWN_RIGHT,
		DOWN_LEFT,
		TOP_LEFT
	};
}