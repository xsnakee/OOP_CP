#include "BossNpc_t.h"



BossNpc_t::BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple):
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
}

BossNpc_t::BossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : Npc_t(copyedNpc,spotPoint,powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

BossNpc_t::~BossNpc_t()
{
}

void BossNpc_t::setSkills(std::initializer_list<size_t> _skillList) {
	elementStatusList.insert(elementStatusList.end(), _skillList.begin(), _skillList.end());
}
void BossNpc_t::setSkills(std::vector<size_t> _skillList) {
	elementStatusList.insert(elementStatusList.end(), _skillList.begin(), _skillList.end());
}
std::vector<size_t> BossNpc_t::getSkillList() {
	return elementStatusList;
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

//TREANT
TeantBossNpc_t::TeantBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	BossNpc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setSkills({ 3,6,24,10,18,2 });
	stat.stdattackPower = 50.f;
	stat.attackRange = 150.f;
	stat.stdPhysDef = 40.f;
	stat.stdMagDef = 25.f;
	stat.damageRand = 15.f;
	stat.stdHP = 550.f;
	stat.visionDistance = 300.f;
	stat.stdAttackSpeed = 5.f;
	stat.stdSpeed = 0.2f;
	defaultAllStats();Npc_t::setTypeStats();
}

TeantBossNpc_t::TeantBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

TeantBossNpc_t::~TeantBossNpc_t()
{
}

//RED DRAGON
RedDragonBossNpc_t::RedDragonBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	BossNpc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setSkills({ 12,18,5,4 });
	stat.stdattackPower = 60.f;
	stat.attackRange = 300.f;
	stat.stdPhysDef = 30.f;
	stat.stdMagDef = 30.f;
	stat.damageRand = 15.f;
	stat.stdHP = 450.f;
	stat.visionDistance = 300.f;
	stat.stdAttackSpeed = 3.f;
	stat.stdSpeed = 0.15f;
	defaultAllStats();Npc_t::setTypeStats();
}

RedDragonBossNpc_t::RedDragonBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

RedDragonBossNpc_t::~RedDragonBossNpc_t()
{
}

//BLACK DRAGON

BlackDragonBossNpc_t::BlackDragonBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	BossNpc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setSkills({ 24,4,17,18,2 });
	stat.stdattackPower = 70.f;
	stat.attackRange = 200.f;
	stat.stdPhysDef = 30.f;
	stat.stdMagDef = 20.f;
	stat.damageRand = 15.f;
	stat.stdHP = 550.f;
	stat.visionDistance = 320.f;
	stat.stdAttackSpeed = 4.f;
	stat.stdSpeed = 0.12f;
	defaultAllStats();Npc_t::setTypeStats();
}

BlackDragonBossNpc_t::BlackDragonBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

BlackDragonBossNpc_t::~BlackDragonBossNpc_t()
{
}

//ENH
EnhBpssNpc_t::EnhBpssNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	BossNpc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setSkills({ 1,3,6,2,11,5,12 });
	stat.stdattackPower = 90.f;
	stat.attackRange = 300.f;
	stat.stdPhysDef = 20.f;
	stat.stdMagDef = 50.f;
	stat.damageRand = 10.f;
	stat.stdHP = 650.f;
	stat.visionDistance = 250.f;
	stat.stdAttackSpeed = 4.f;
	stat.stdSpeed = 0.2f;
	defaultAllStats();Npc_t::setTypeStats();
}

EnhBpssNpc_t::EnhBpssNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

EnhBpssNpc_t::~EnhBpssNpc_t()
{
}

//DARK QUEEN
DQBossNpc_t::DQBossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple) :
	BossNpc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	setSkills({ 6,2,11,5,12,4,7 });
	stat.stdattackPower = 100.f;
	stat.attackRange = 350.f;
	stat.stdPhysDef = 40.f;
	stat.stdMagDef = 40.f;
	stat.damageRand = 30.f;
	stat.stdHP = 500.f;
	stat.visionDistance = 400.f;
	stat.stdAttackSpeed = 2.f;
	stat.stdSpeed = 0.15f;
	defaultAllStats();Npc_t::setTypeStats();
}

DQBossNpc_t::DQBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

DQBossNpc_t::~DQBossNpc_t()
{
}