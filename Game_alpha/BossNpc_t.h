#pragma once
#include "Npc_t.h"
#include <initializer_list>

class BossNpc_t :
	public Npc_t
{
	std::vector<size_t> elementStatusList; //skills
public:
	BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple = 3.f);
	BossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple);
	
	virtual ~BossNpc_t();

	void setSkills(std::initializer_list<size_t> _skillList);
	virtual void update(float _speed);
	virtual void attack();
	virtual void generateSkillAndClearElemList();
	virtual size_t setElemStatus(size_t _elemStatus);
};

