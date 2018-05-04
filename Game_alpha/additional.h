#pragma once
#include <list>
#include <vector>
#include <iterator>

const std::shared_ptr<sf::Texture> MAIN_HERO_TEXTURE = std::make_shared<sf::Texture>();

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
	const std::string MAIN_HERO_TEXTURE_FILE = "img/characters/mainHero.png";

	const std::string ENEMY_DEMON_FILE = "img/characters/enemy_demon.png";
	const std::string ENEMY_SLENDER_DEMON_FILE = "img/characters/enemy_slenderDemon.png";
	const std::string ENEMY_WARRIOR_FILE = "img/characters/enemy_warrior.png";
	const std::string ENEMY_MAGE_FILE = "img/characters/enemy_mage.png";


	const int MAIN_HERO_SPRITE_WIDTH = 32;
	const int MAIN_HERO_SPRITE_HEIGHT = 32;
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

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







//TRASH

/*
class textureList_t {
public:
	std::shared_ptr<sf::Texture>SWORD_ATTACK_TEXTURE;//0
	std::shared_ptr<sf::Texture>BULLET_SMALL_FIRE_BALLS_TEXTURE;//1
	std::shared_ptr<sf::Texture>BULLET_SMALL_EARTH_BALL_TEXTURE;//2
	std::shared_ptr<sf::Texture>BULLET_FIRE_BALL_TEXTURE;//3
	std::shared_ptr<sf::Texture>BULLET_EARTH_BALL_TEXTURE;//4
	std::shared_ptr<sf::Texture>BULLET_LAVA_TEXTURE;//5
	std::shared_ptr<sf::Texture>BULLET_FIREWALL_TEXTURE;//6
	std::shared_ptr<sf::Texture>BULLET_EARTH_SLAM_TEXTURE;//7
	std::shared_ptr<sf::Texture>BULLET_COMBO_BALL_TEXTURE;//8
	std::shared_ptr<sf::Texture>MAIN_HERO_TEXTURE;//9
	std::shared_ptr<sf::Texture>ENEMY_SLENDER_DEMON;// 10
	std::shared_ptr<sf::Texture>ENEMY_WARRIOR;//11
	std::shared_ptr<sf::Texture>ENEMY_MAGE;//12
	std::shared_ptr<sf::Texture>ENEMY_DEMON; //13

	textureList_t() {
		SWORD_ATTACK_TEXTURE = std::make_shared<sf::Texture>();//0
		BULLET_SMALL_FIRE_BALLS_TEXTURE = std::make_shared<sf::Texture>();//1
		BULLET_SMALL_EARTH_BALL_TEXTURE = std::make_shared<sf::Texture>();//2
		BULLET_FIRE_BALL_TEXTURE = std::make_shared<sf::Texture>();//3
		BULLET_EARTH_BALL_TEXTURE = std::make_shared<sf::Texture>();//4
		BULLET_LAVA_TEXTURE = std::make_shared<sf::Texture>();//5
		BULLET_FIREWALL_TEXTURE = std::make_shared<sf::Texture>();//6
		BULLET_EARTH_SLAM_TEXTURE = std::make_shared<sf::Texture>();//7
		BULLET_COMBO_BALL_TEXTURE = std::make_shared<sf::Texture>();//8
		MAIN_HERO_TEXTURE = std::make_shared<sf::Texture>();//9
		ENEMY_SLENDER_DEMON = std::make_shared<sf::Texture>();// 10
		ENEMY_WARRIOR = std::make_shared<sf::Texture>();//11
		ENEMY_MAGE = std::make_shared<sf::Texture>();//12
		ENEMY_DEMON = std::make_shared<sf::Texture>();; //13

		std::list<std::string>::iterator it = animation::textureFileNames.begin();
		SWORD_ATTACK_TEXTURE->loadFromFile(*(it++));//0
		BULLET_SMALL_FIRE_BALLS_TEXTURE->loadFromFile(*(it++));//1
		BULLET_SMALL_EARTH_BALL_TEXTURE->loadFromFile(*(it++));//2
		BULLET_FIRE_BALL_TEXTURE->loadFromFile(*(it++));//3
		BULLET_EARTH_BALL_TEXTURE->loadFromFile(*(it++));//4
		BULLET_LAVA_TEXTURE->loadFromFile(*(it++));//5
		BULLET_FIREWALL_TEXTURE->loadFromFile(*(it++));//6
		BULLET_EARTH_SLAM_TEXTURE->loadFromFile(*(it++));//7
		BULLET_COMBO_BALL_TEXTURE->loadFromFile(*(it++));//8
		MAIN_HERO_TEXTURE->loadFromFile(*(it++));//9
		ENEMY_SLENDER_DEMON->loadFromFile(*(it++));// 10
		ENEMY_WARRIOR->loadFromFile(*(it++));//11
		ENEMY_MAGE->loadFromFile(*(it++));//12
		ENEMY_DEMON->loadFromFile(*(it++));; //13

	}
	~textureList_t() {

	}
};

//*/