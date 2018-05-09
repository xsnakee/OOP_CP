#include "BossNpc_t.h"



BossNpc_t::BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple):Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
}


BossNpc_t::~BossNpc_t()
{
}

void BossNpc_t::attack() {
	character_t::attack();
	//����� ��������� �����
}

void BossNpc_t::generateSkillAndClearElemList() {
	
}

size_t BossNpc_t::setElemStatus(size_t _elemStatus) {

	return elemStatus;
}
