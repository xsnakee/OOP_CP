#pragma once
#include <initializer_list>

namespace game{
	enum status {
		PLAY,
		PAUSED,
		WIN,
		GAME_OVER,
		RESTART,
		MAIN_MENU
	};

}

namespace elements {
	const size_t SKILL_ELEMENT_AMOUNT = 3;
	enum element {
		NONE = 0,
		EARTH = 8,
		FIRE = 2,
		WIND = 1
	};
}

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
	const std::string DEFAULT_TEXTURE = "img/default.png";
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
	const std::string BULLET_FIRE_LIGHTING_TEXTURE_FILE = "img/skills/bullet_fire_lighting.png";
	const std::string BULLET_POISION_BALL_TEXTURE_FILE = "img/skills/bullet_poision_splash.png";

	//CHARACTER IMGS
	const std::string MAIN_HERO_TEXTURE_FILE = "img/characters/mainHero_32_32.png";
	const std::string MAIN_HERO_TEXTURE_FILE2 = "img/characters/mainHero(2)_32_32.png";
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

	const int COMMON_CHARACTER_SPRITE = 32;
	const int MAIN_HERO_SPRITE_HEIGHT = 32;
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;
	const int LARGE_SKILL_WIDTH = 64;
	const int LARGE_SKILL_HEIGHT = 64;

	const float frameRate = 3.f;
	const float frameSpeed = 0.05f;

	const float HEROES_SPRITE_COLLISION_CORRECTION_BORDER = 10.f;

	enum direction {
		BOTTOM = 0,
		LEFT = 1,
		RIGHT = 2,
		TOP = 3,
	};


}

namespace icon {
	//ICONS
	//const std::string ICON_ELEMENT__FILE = "img/icons/.png";
	const std::string ICON_ELEMENT_FIRE_FILE = "img/icons/icon_element_fire.png";
	const std::string ICON_ELEMENT_WIND_FILE = "img/icons/icon_element_wind.png";
	const std::string ICON_ELEMENT_EARTH_FILE = "img/icons/icon_element_earth.png";
	//SKILLS ICONS
	const std::string ICON_SKILL_BANG_BALL_FILE = "img/icons/icon_skill_bang_ball.png";
	const std::string ICON_SKILL_COMBO_BALL_FILE = "img/icons/icon_skill_combo_ball.png";
	const std::string ICON_SKILL_sWORD_ATTACK_FILE = "img/icons/icon_skill_common_attack.png";
	const std::string ICON_SKILL_EARTH_BALL_FILE = "img/icons/icon_skill_earth_ball.png";
	const std::string ICON_SKILL_FIRE_BALL_FILE = "img/icons/icon_skill_fire_ball.png";
	const std::string ICON_SKILL_HEAL_BALL_FILE = "img/icons/icon_skill_heal_ball.png";
	const std::string ICON_SKILL_LAVA_POOL_FILE = "img/icons/icon_skill_lava_pool.png";
	const std::string ICON_SKILL_POWER_UP_FILE = "img/icons/icon_skill_powerUp.png";
	const std::string ICON_SKILL_RUSH_FILE = "img/icons/icon_skill_rush.png";
	const std::string ICON_SKILL_SMALL_EARTH_BALLS_FILE = "img/icons/icon_skill_small_earth_balls.png";
	const std::string ICON_SKILL_SMALL_FIRE_BALLS_FILE = "img/icons/icon_skill_small_fire_balls.png";
	const std::string ICON_SKILL__FILE = "img/icons/.png";

	//BUTTONS ICONS
	const std::string ICON_BUTTON_JOURNAL = "img/icons/icon_button_journal.png";
	const std::string ICON_BUTTON_GAME_STATISTIC = "img/icons/icon_button_game_statistic.png";
	const std::string ICON_BUTTON_SKILLS = "img/icons/icon_button_skills.png";
	const std::string ICON_BUTTON_MAP = "img/icons/icon_button_map.png";

	//SKILL DESCRIPTION ICONS
	const int ICON_DESC_HEIGHT = 32;
	const int ICON_DESC_WIDTH = 32;

	const std::string DESC_ICON_ELEMENT_FIRE_FILE = "img/icons/description_icons/icon_element_fire.png";
	const std::string DESC_ICON_ELEMENT_WIND_FILE = "img/icons/description_icons/icon_element_wind.png";
	const std::string DESC_ICON_ELEMENT_EARTH_FILE = "img/icons/description_icons/icon_element_earth.png";
	const int DESC_ICON_ELEMENT_SIZE = 32;
	
	const std::string ICON_HEAL_111 = "img/icons/description_icons/111.png";
	const std::string ICON_BANG_112 = "img/icons/description_icons/112.png";
	const std::string ICON_STONE_113 = "img/icons/description_icons/113.png";
	const std::string ICON_COMBO_123 = "img/icons/description_icons/123.png";
	const std::string ICON_FIRE_BREATH_221 = "img/icons/description_icons/221.png";
	const std::string ICON_POWER_BUFF_222 = "img/icons/description_icons/222.png";
	const std::string ICON_FIRE_BALL_223 = "img/icons/description_icons/223.png";
	const std::string ICON_SMALL_EARTH_BALLS_331 = "img/icons/description_icons/331.png";
	const std::string ICON_FIRE_LIGHTING_332 = "img/icons/description_icons/332.png";
	const std::string ICON_SPEED_BUFF_333 = "img/icons/description_icons/333.png";
}
namespace textSettings {
	const std::string STD_FONT_FILE = "fonts/main_font_regular.otf";
	const std::string STRIKE_THROUGHT_FONT_FILE = "fonts/main_strike_throught_font.ttf";
	const size_t STD_FONT_SIZE = 14;

	const sf::Color STD_TEXT_COLOR = sf::Color::White;
	const sf::Text::Style STD_TEXT_STYLE = sf::Text::Style::Regular;
	const sf::Text::Style TEXT_STYLE_STRIKE_THROUGH = sf::Text::Style::StrikeThrough;
};

namespace interface {

	const sf::Vector2f STD_HP_BAR_HEIGHT(50.f, 10.f);
	const sf::Vector2f STD_BAR_SIZE(400.f, 20.f);
	const sf::Vector2f STD_BORDER_SIZE(2.f, 2.f);
	const sf::Vector2f STD_WINDOW_SIZE(48.f, 48.f);
	const sf::Vector2f STD_MARGIN_SIZE(5.f,5.f);

	const sf::Vector2f STD_WINDOW_MARGIN_SIZE(15.f, 15.f);
	
	const sf::Vector2f STD_SKILL_WINDOW_SIZE(64.f,64.f);
	const sf::Vector2f STD_ELEMENT_GENERATOR_WINDOW_SIZE(48.f,48.f);

	static sf::Vector2f getScreenCoords(sf::RenderWindow *window) {
		return sf::Vector2f(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
	}
};

namespace buttons {
	const std::string JOURNAL_KEY_NAME = "journal";
	const std::string GAME_STATS_KEY_NAME = "gameStats";
	const std::string MAP_KEY_NAME = "map";
	const std::string SKILL_KEY_NAME = "skill";
}

template <typename T> T getRand(T a, T b) {
	T temp = static_cast<T>(static_cast<int>(a) + (rand() % (static_cast<int>(b - a))));
	return temp;
}


static bool timeIsOver(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? true : false;
}

static sf::Vector2f generateRandomSpawnCoords(const sf::Vector2i mapSize) {

	sf::Vector2f vect;
	vect.x = static_cast<float>(rand() % mapSize.x);
	vect.y = static_cast<float>(rand() % mapSize.y);

	return vect;
}

static size_t findBigestLength(std::vector<std::string> list) {
	size_t maxLength = 0;
	for (auto &i : list) {
		maxLength = (i.size() > maxLength) ? i.size() : maxLength;
	}
	return maxLength;
}
