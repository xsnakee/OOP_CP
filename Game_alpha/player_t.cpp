#include "player_t.h"



//*
player_t::player_t(sf::Vector2f _pos, std::string fileName, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : character_t(_pos.x, _pos.y, fileName, 0,0, _width, _height, _clock, _bulletList)
{
	fraction = 0;
	elemStatus = 5;
	collision = true;
	state.swap(std::unique_ptr<CharacterState_t>(new CharacterPlayerControll_t(*this)));
	stat.stdattackPower = 20.f;
	stat.attackRange = 250.f;
	stat.stdPhysDef = 15.f;
	stat.stdMagDef = 15.f;
	stat.damageRand = 10.f;
	stat.stdHP = 350.f;
	stat.visionDistance = 300.f;
	stat.stdAttackSpeed = 5.f;
	stat.stdSpeed = 0.15f;
	stat.stdCastSpeed = 17.f;
	defaultAllStats();
	timer.attackCDcorrection(stat.stdAttackSpeed);
	timer.castDelayCorrection(stat.stdCastSpeed);
}

player_t::player_t(std::shared_ptr<sf::Texture> _texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, sf::Vector2f _pos, int _width, int _height, sf::Clock *_clock) :
	character_t(_texture, _bulletList, _pos.x, _pos.y, 0,0, _width, _height, _clock)
{
	fraction = 0;
	elemStatus = 5;
	collision = true;
	state.swap(std::unique_ptr<CharacterState_t>(new CharacterPlayerControll_t(*this)));;
	stat.stdattackPower = 20.f;
	stat.attackRange = 250.f;
	stat.stdPhysDef = 25.f;
	stat.stdMagDef = 15.f;
	stat.damageRand = 10.f;
	stat.stdHP = 350.f;
	stat.visionDistance = 300.f;
	stat.stdAttackSpeed = 5.f;
	stat.stdSpeed = 0.15f;
	stat.stdCastSpeed = 17.f;
	defaultAllStats();
	timer.attackCDcorrection(stat.stdAttackSpeed);
	timer.castDelayCorrection(stat.stdCastSpeed);
}
//*/

player_t::~player_t()
{
}


void player_t::update(float _speed) {
	character_t::update(_speed);


	if (((this)->getState()->getStateNum() == 4) && (this)->checkSkillGenerator() && ((this)->getTimer().castReady())) {
		(this)->generateSkillAndClearElemList();
		(this)->changeState(new CharacterPlayerControll_t(*this));
	}
	else if ((this)->getTimer().castReady()){

		(this)->changeState(new CharacterPlayerControll_t(*this));
}

}

void player_t::attack() {
	if (stat.MP > 0) {
		if (timer.attackReady()) {
			timer.updateAttackCD();
			skill->useSkill();
		}
	}
}

void player_t::useMP(float _mp) {
	character_t::useMP(_mp);
	if (stat.MP < FLT_EPSILON){
		elemStatus = 0;
	}
}
