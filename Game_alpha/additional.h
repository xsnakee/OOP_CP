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

}

namespace animation {

	const std::string MAIN_HERO_TEXTURE_FILE = "img/characters/mainHeroSprite.png";

	const int MAIN_HERO_SPRITE_WIDTH = 27;
	const int MAIN_HERO_SPRITE_HEIGHT = 32;
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	const float frameRate = 3.f;
	const float frameSpeed = 0.01f;

	enum direction{
		BOTTOM = 0,
		LEFT = 1,
		RIGHT = 2,
		TOP = 3
	};
}