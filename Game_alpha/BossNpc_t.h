#pragma once
#include "Npc_t.h"
#include <initializer_list>

class BossNpc_t :
	public Npc_t
{protected:
	std::vector<size_t> elementStatusList; //skills
public:
	BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	BossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);
	
	virtual ~BossNpc_t();

	virtual void setSkills(std::initializer_list<size_t> _skillList);
	virtual void BossNpc_t::setSkills(std::vector<size_t> _skillList);
	virtual std::vector<size_t> getSkillList();
	virtual void update(float _speed);
	virtual void attack();
	virtual void generateSkillAndClearElemList();
	virtual size_t setElemStatus(size_t _elemStatus);
};

class TeantBossNpc_t : public BossNpc_t {
public:
	TeantBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	TeantBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);

	virtual ~TeantBossNpc_t();
};

class RedDragonBossNpc_t : public BossNpc_t {
public:
	RedDragonBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	RedDragonBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);

	virtual ~RedDragonBossNpc_t();
};
class BlackDragonBossNpc_t : public BossNpc_t {
public:
	BlackDragonBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	BlackDragonBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);

	virtual ~BlackDragonBossNpc_t();
};
class EnhBpssNpc_t : public BossNpc_t {
public:
	EnhBpssNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	EnhBpssNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);

	virtual ~EnhBpssNpc_t();
};
class DQBossNpc_t : public BossNpc_t {
public:
	DQBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	DQBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);

	virtual ~DQBossNpc_t();
};
