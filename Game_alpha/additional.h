#pragma once
#include <list>
#include <vector>
#include <iterator>


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
	bool type = true;//0 - heal, 1 - dmg
	int fraction = -1;
};


namespace tiles {
	const unsigned int WIDTH_SIZE_POSITION_IN_STR = 9U;
	const unsigned int HEIGHT_SIZE_POSITION_IN_STR = 6U;
	const int STD_SIZES_LENGTH = 2;
	struct sizes {
		int width;
		int height;
	};

	static sizes getSizesFromStr(std::string str, int widthStrPosCorrection = 2, int heightStrPosCorrection = 2) {
		sizes temp;
		size_t length = str.size();
		std::string width = str.substr(length - WIDTH_SIZE_POSITION_IN_STR + STD_SIZES_LENGTH - widthStrPosCorrection + STD_SIZES_LENGTH - heightStrPosCorrection,widthStrPosCorrection);
		std::string height = str.substr(length - HEIGHT_SIZE_POSITION_IN_STR + STD_SIZES_LENGTH - heightStrPosCorrection,heightStrPosCorrection);

		temp.width = atoi(width.c_str());
		temp.height = atoi(height.c_str());
		return temp;
	}

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
	const std::string SWORD_ATTACK_TEXTURE_FILE = "img/skills/bullet_sword.png";
	const std::string BULLET_SMALL_FIRE_BALLS_TEXTURE_FILE = "img/skills/bullet_small_fire_balls.png";
	const std::string BULLET_SMALL_EARTH_BALL_TEXTURE_FILE = "img/skills/bullet_small_earth_balls.png";
	const std::string BULLET_FIRE_BALL_TEXTURE_FILE = "img/skills/bullet_fire_ball.png";
	const std::string BULLET_EARTH_BALL_TEXTURE_FILE = "img/skills/bullet_earth_ball.png";
	const std::string BULLET_LAVA_TEXTURE_FILE = "img/skills/bullet_lava_pool.png";
	const std::string BULLET_BANG_BALL_TEXTURE_FILE = "img/skills/bullet_bang_ball.png";
	const std::string BULLET_EARTH_SLAM_TEXTURE_FILE = "img/skills/bullet_earth_slam.png";
	const std::string BULLET_COMBO_BALL_TEXTURE_FILE = "img/skills/bullet_combo.png";
	const std::string BULLET_CRYSTAL_HEAL_TEXTURE_FILE = "img/skills/bullet_crystal_heal.png";

	//CHARACTER IMGS
	const std::string MAIN_HERO_TEXTURE_FILE = "img/characters/mainHero_32_32.png";

	const std::string ENEMY_DEMON_FILE = "img/characters/enemy_demon_32_32.png";
	const std::string ENEMY_SLENDER_DEMON_FILE = "img/characters/enemy_slenderDemon_32_32.png";
	const std::string ENEMY_WARRIOR_FILE = "img/characters/enemy_warrior_32_32.png";
	const std::string ENEMY_MAGE_FILE = "img/characters/enemy_mage_32_32.png";

	//const std::string ENEMY_ _TEXURE_FILE = "img/characters/.png";
	const std::string ENEMY_ZOMBIE_PUDGE_TEXURE_FILE = "img/characters/enemy_zombie_pudge_64_64.png";
	const std::string ENEMY_SKELETON_MAGE_TEXTURE_FILE = "img/characters/enemy_skeleton_mage_32_48.png";
	const std::string ENEMY_ZOMBIE_WITCH_TEXTURE_FILE = "img/characters/enemy_zombie_witch_32_32.png";
	const std::string ENEMY_SOMBIE_WARRIOR_TEXTURE_FILE = "img/characters/enemy_zombie_warrior_32_32.png";

	const std::string BOSS_FINALY_DEMON_TEXURE_FILE = "img/characters/BOSSES/BOSS_FINALY_96_48.png";
	const std::string BOSS_TREANT_TEXURE_FILE = "img/characters/BOSSES/BOSS_TREANT_96_96.png";

	const std::string BOSS_BLACK_DRAGON_TEXURE_FILE = "img/characters/BOSSES/BOSS_BLACK_DRAGON_96_96.png";
	const std::string BOSS_RED_DRAGON_TEXURE_FILE = "img/characters/BOSSES/BOSS_RED_DRAGON_192_192.png";
	const std::string BOSS_ENH_TEXURE_FILE = "img/characters/BOSSES/BOSS_ENH_240_80.png";
	//ICONS
	//const std::string ICON_ELEMENT__FILE = "img/icons/.png";
	const std::string ICON_ELEMENT_FIRE_FILE = "img/icons/icon_element_fire.png";

	const int COMMON_CHARACTER_SPRITE = 32;
	const int MAIN_HERO_SPRITE_HEIGHT = 32;
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	const int LARGE_SKILL_WIDTH = 64;
	const int LARGE_SKILL_HEIGHT = 64;

	const float frameRate = 3.f;
	const float frameSpeed = 0.05f;

	enum direction {
		BOTTOM = 0,
		LEFT = 1,
		RIGHT = 2,
		TOP = 3,
	};


}
template <typename T> T getRand(T a, T b) {
	T temp = static_cast<T>(a + (rand() % static_cast<int>(b - a)));
	return temp;
}


static bool timeIsOver(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? true : false;
}


namespace textSettings {
	const std::string MAIN_FONT_FILE = "fonts/main_font.ttf";
	const size_t STD_FONT_SIZE = 12;
};

namespace interface {
	const sf::Vector2f STD_BAR_SIZE(400.f, 20.f);
	const sf::Vector2f STD_BORDER_SIZE(2.f, 2.f);
	const sf::Vector2f STD_WINDOW_SIZE(48.f, 48.f);

	static sf::Vector2f getScreenCoords(sf::RenderWindow *window) {
		return sf::Vector2f(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
	}
};