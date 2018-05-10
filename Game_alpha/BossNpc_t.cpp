#include "BossNpc_t.h"



BossNpc_t::BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple):
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
}

BossNpc_t::BossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : Npc_t(copyedNpc,spotPoint,powerMultiple) {
	setSkills({1,4,18});
}

BossNpc_t::~BossNpc_t()
{
}

void BossNpc_t::setSkills(std::initializer_list<size_t> _skillList) {
	elementStatusList.insert(elementStatusList.end(), _skillList.begin(), _skillList.end());
}

void BossNpc_t::update(float _speed) {
	checkAlive();
	if (alive) {

		physOb_t::update(_speed);

		if (buff.get()) {
			buff->checkActivity();
		}
	}

	generateSkillAndClearElemList();
}

void BossNpc_t::attack() {
	Npc_t::attack();
}

void BossNpc_t::generateSkillAndClearElemList() {
	size_t skillRandomIndex = rand() % elementStatusList.size();;
	elemStatus = elementStatusList[skillRandomIndex];
}

size_t BossNpc_t::setElemStatus(size_t _elemStatus) {

	return elemStatus;
}
