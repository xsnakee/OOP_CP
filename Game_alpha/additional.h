#pragma once
#include <SFML\Graphics.hpp>

namespace elements {
	const size_t SKILL_ELEMENT_AMOUNT = 3;
	enum element {
		NONE = 0,
		WIND = 1,
		FIRE = 2,
		EARTH = 8
	};
}


namespace tiles {

	const int size = 32;

	const int SPRITE_HEIGHT = 32;
	const int SPRITE_WIDTH = 32;

	const int TEXTURE_TILE_AMOUNT_X = 21;
	const int TEXTURE_TILE_AMOUNT_Y = 30;

	const int TEXTURE_FILE_WIDHT = 672;
	const int TEXTURE_FILE_HEIGHT = 960;

	const int OB_TEXTURE_VALUE = 400;

	enum tile {
		DARK = 0,
		GRACE = 1,
		SAND = 2,
		WATER = 3,
		MAGMA = 4,
		STONE = 5,
		BUSH = 6,
		//...
	};

}