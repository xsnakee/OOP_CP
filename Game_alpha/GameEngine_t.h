#pragma once

#include <SFML/Graphics.hpp>

#include <list>
#include <memory>
#include "character_t.h"
#include "player_t.h"
#include "Npc_t.h"
#include "BossNpc_t.h"
#include "bullet_t.h"
#include "additional.h"
#include "Level_t.h"


const float STD_DIFFICULTY_COEFFICIENT = 0.7f;

class GameEngine_t
{
private:
	sf :: RenderWindow *window;

	Level_t &level;
	size_t difficulty;
	std::list<std::unique_ptr<character_t>> npcTypesList;
	std::list<std::unique_ptr<BossNpc_t>> npcBossesTypeList;

	game::status status;

	std::unique_ptr<sf::Clock> clock;
	float curTime;
	float speed;
	float speedMultipple;

	void generateNpcTypes();
	bool positionCollision(const sf::Vector2f _obPos);

public:

	GameEngine_t(sf::RenderWindow *_window, Level_t &_level, size_t _difficulty);
	~GameEngine_t();

	void update();
	void draw();

	void checkAlive();
	void visionEngine();
	void collisionEngine();
	void bulletEngine();
	void charsAction();
	
	void generateNpc();
	void generateBosses();
	
	//GET
	game::status getGameStatus() const;
	float getSpeed()const;
	sf::Int32 getCurTimeSec() const;
	float getSpeedMultipple()const;
	std::list<std::unique_ptr <bullet_t>> &getBulletList();
	sf::Clock *getClockPtr() const;
	//SET
	float setSpeed(float _time);
};

