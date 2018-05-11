#include "BossNpc_t.h"



BossNpc_t::BossNpc_t(std::shared_ptr<sf::Texture>_texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Clock *_clock, sf::Vector2f _spotCoords, int _width, int _height, float _multiple):
	Npc_t(_texture, _bulletList, _clock, _spotCoords, _width, _height, _multiple)
{
	destroyble = false;
}

BossNpc_t::BossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : Npc_t(copyedNpc,spotPoint,powerMultiple) {
	setSkills(copyedNpc->getSkillList());
	destroyble = false;
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
	stat.stdattackPower = 20.f;
	stat.attackRange = 150.f;
	stat.stdPhysDef = 25.f;
	stat.stdMagDef = 15.f;
	stat.damageRand = 10.f;
	stat.stdHP = 350.f;
	stat.visionDistance = 300.f;
	stat.attackSpeed = -0.5f;
	stat.stdSpeed = 0.11f;
	defaultAllStats();
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
	stat.stdattackPower = 30.f;
	stat.attackRange = 300.f;
	stat.stdPhysDef = 20.f;
	stat.stdMagDef = 25.f;
	stat.damageRand = 15.f;
	stat.stdHP = 450.f;
	stat.visionDistance = 300.f;
	stat.attackSpeed = -0.5f;
	stat.stdSpeed = 0.15f;
	defaultAllStats();
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
	setSkills({ 24,4,10,17,18,2 });
	stat.stdattackPower = 40.f;
	stat.attackRange = 200.f;
	stat.stdPhysDef = 25.f;
	stat.stdMagDef = 25.f;
	stat.damageRand = 15.f;
	stat.stdHP = 550.f;
	stat.visionDistance = 320.f;
	stat.attackSpeed = -0.1f;
	stat.stdSpeed = 0.11f;
	defaultAllStats();
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
	setSkills({ 3,6,1,2,11,5,12 });
	stat.stdattackPower = 50.f;
	stat.attackRange = 300.f;
	stat.stdPhysDef = 15.f;
	stat.stdMagDef = 30.f;
	stat.damageRand = 10.f;
	stat.stdHP = 550.f;
	stat.visionDistance = 250.f;
	stat.attackSpeed = 1.f;
	stat.stdSpeed = 0.15f;
	defaultAllStats();
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
	setSkills({ 3,6,1,2,11,5,12 });
	stat.stdattackPower = 55.f;
	stat.attackRange = 300.f;
	stat.stdPhysDef = 30.f;
	stat.stdMagDef = 30.f;
	stat.damageRand = 30.f;
	stat.stdHP = 500.f;
	stat.visionDistance = 200.f;
	stat.attackSpeed = 2.f;
	stat.stdSpeed = 0.15f;
	defaultAllStats();
}

DQBossNpc_t::DQBossNpc_t(character_t *copyedNpc, sf::Vector2f spotPoint, float powerMultiple) : BossNpc_t(copyedNpc, spotPoint, powerMultiple) {
	setSkills(copyedNpc->getSkillList());
}

DQBossNpc_t::~DQBossNpc_t()
{
}