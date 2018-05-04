#pragma once
#include <map>


namespace elements {
	const size_t SKILL_ELEMENT_AMOUNT = 3;
	enum element {
		NONE = 0,
		WIND = 1,
		FIRE = 2,
		EARTH = 8
	};
}

struct bulletStats {
	float speed;
	float damage;
	float range;
	elements::element element = elements::NONE;
	float AOE = 0.1f;
	bool type = false;//0 - phys, 1 - magic
	int fraction = -1;
};


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

	//BULLETS IMGS
	const std::string SWORD_ATTACK_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_SMALL_FIRE_BALLS_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_SMALL_EARTH_BALL_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_FIRE_BALL_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_EARTH_BALL_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_LAVA_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_FIREWALL_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_EARTH_SLAM_TEXTURE_FILE = "img/skills/bullets.png";
	const std::string BULLET_COMBO_BALL_TEXTURE_FILE = "img/skills/bullets.png";

	//CHARACTER IMGS
	const std::string MAIN_HERO_TEXTURE_FILE = "img/characters/enemy_warrior.png";// "img/characters/mainHero.png";

	const std::string ENEMY_DEMON_FILE = "img/characters/enemy_demon.png";
	const std::string ENEMY_SLENDER_DEMON_FILE = "img/characters/enemy_slenderDemon.png";
	const std::string ENEMY_WARRIOR_FILE = "img/characters/enemy_warrior.png";
	const std::string ENEMY_MAGE_FILE = "img/characters/enemy_mage.png";

	const std::map<const std::string, const std::string> textureFileNamesMap = {
		{ "SWORD_ATTACK_TEXTURE_FILE" , "img/skills/bullets.png" },
	{ "BULLET_SMALL_FIRE_BALLS_TEXTURE_FILE" , "img/skills/bullets1.png" },
	{ "BULLET_SMALL_EARTH_BALL_TEXTURE_FILE" , "img/skills/bullets2.png" },
	{ "BULLET_FIRE_BALL_TEXTURE_FILE" , "img/skills/bullets3.png" },
	{ "BULLET_EARTH_BALL_TEXTURE_FILE" , "img/skills/bullets4.png" },
	{ "BULLET_LAVA_TEXTURE_FILE" , "img/skills/bullets5.png" },
	{ "BULLET_FIREWALL_TEXTURE_FILE" , "img/skills/bullets6.png" },
	{ "BULLET_EARTH_SLAM_TEXTURE_FILE" , "img/skills/bullets7.png" },
	{ "BULLET_COMBO_BALL_TEXTURE_FILE" , "img/skills/bullets8.png" },
	{ "MAIN_HERO_TEXTURE_FILE" , "img/characters/mainHero.png" },
	{ "ENEMY_SLENDER_DEMON_FILE" , "img/characters/enemy_slenderDemon.png" },
	{ "ENEMY_WARRIOR_FILE" , "img/characters/enemy_warrior.png" },
	{ "ENEMY_MAGE_FILE" , "img/characters/enemy_mage.png" },
	{ "ENEMY_DEMON_FILE" , "img/characters/enemy_demon.png" }
	};

	const int MAIN_HERO_SPRITE_WIDTH = 32;
	const int MAIN_HERO_SPRITE_HEIGHT = 32;
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	const float frameRate = 3.f;
	const float frameSpeed = 0.05f;

	enum direction{
		BOTTOM = 0,
		LEFT = 1,
		RIGHT = 2,
		TOP = 3,
	};
}

template <typename T> T getRand(T a, T b) {
	T temp = static_cast<T>(a + (rand() % static_cast<int>(b - a)) );
	return temp;
}