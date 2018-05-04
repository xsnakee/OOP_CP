#include "player_t.h"
#include <iostream>



//*
player_t::player_t(float _x, float _y, std::string fileName, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock, std::list<std::unique_ptr <bullet_t>> &_bulletList) : character_t(_x, _y, fileName, _coordX, _coordY, _width, _height, _clock, _bulletList)
{
	fraction = 0;
	collision = true;
	state = std::unique_ptr<CharacterState_t>(new CharacterPlayerControll_t(this));
}

player_t::player_t(std::shared_ptr<sf::Texture> _texture, std::list<std::unique_ptr <bullet_t>> &_bulletList, float _x, float _y, int _coordX, int _coordY, int _width, int _height, sf::Clock *_clock):
	 character_t(_texture, _bulletList, _x, _y, _coordX, _coordY, _width, _height, _clock)
{
	fraction = 0;
	collision = true;
	state = std::unique_ptr<CharacterState_t>(new CharacterPlayerControll_t(this));
	elemStatus = 17;
}
//*/

player_t::~player_t()
{
}


void player_t::update(float _speed) {
	character_t::update(_speed);

}

void player_t::attack() {
	if (timer.attackReady()) {
		timer.updateAttackCD();
		skill->useSkill();
		std::cout << "Attacked!!" << std::endl;
	}
}
