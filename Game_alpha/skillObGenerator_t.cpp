#include "skillObGenerator_t.h"



skillObGenerator_t::skillObGenerator_t(character_t *_character, std::list<std::unique_ptr <bullet_t>> &_bulletList):skillGeneratorBulletList(_bulletList)
{
	character = _character;
}


skillObGenerator_t::~skillObGenerator_t()
{
}

void skillObGenerator_t::useSkill() {
	
	size_t skillType = character->getElemStatus();

	switch (skillType) {
	case 3: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.speed += 0.1f;
		upCharacterStat(tempStat);
		break;
	}
	case 6: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.attackPower += 20.f;
		upCharacterStat(tempStat);
		break;
	}
	case 24: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.physDef += 20.f;
		tempStat.magDef += 20.f;
		upCharacterStat(tempStat);
		break;
	}

	case 1: {//PhysAttack

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::SWORD_ATTACK_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setCollision(false);
		tempBullet->speedMultiple(0.5f);
		tempBullet->setType(false);
		tempBullet->setElement(elements::NONE);
		tempBullet->setTimer(500);
		tempBullet->setAOE(20.f);
		tempBullet->setRng(10.f);

		float tempDmg = 30.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 4: {//SMALL FIRE BALLS
		
		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_SMALL_FIRE_BALLS_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));

		tempBullet->setSpriteSize(animation::LARGE_SKILL_WIDTH, animation::LARGE_SKILL_HEIGHT);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setAOE(50.f);
		tempBullet->setCollision(false);
		tempBullet->speedMultiple(0.8f);
		tempBullet->setType(true);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(2000);
		tempBullet->setRng(100.f);

		float tempDmg = 5.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 10: {//SMALL EARTH BALLS

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_SMALL_EARTH_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setSpriteSize(animation::LARGE_SKILL_WIDTH, animation::LARGE_SKILL_HEIGHT);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setAOE(50.f);
		tempBullet->setCollision(false);
		tempBullet->speedMultiple(0.8f);
		tempBullet->setType(false);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(2000);
		tempBullet->setRng(100.f);

		float tempDmg = 7.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 5: {//FIRE BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_FIRE_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setCollision(true);
		tempBullet->speedMultiple(1.f);
		tempBullet->setType(true);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(4000);
		tempBullet->setRng(200.f);

		float tempDmg = 15.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 17: {//EARTH BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_EARTH_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setCollision(true);
		tempBullet->speedMultiple(0.5f);
		tempBullet->setType(false);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(4000);
		tempBullet->setRng(200.f);
		tempBullet->setAOE(10.f);

		float tempDmg = 30.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 12: {//LAVA POOL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_LAVA_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setPosX(character->getTargetCoords().x);
		tempBullet->setPosY(character->getTargetCoords().y);
		tempBullet->setSpriteSize(animation::LARGE_SKILL_WIDTH, animation::LARGE_SKILL_HEIGHT);
		tempBullet->setTexturePtr(tempTexture);
		
		tempBullet->setCollision(false);
		tempBullet->setdX(0.f);
		tempBullet->setdY(0.f);

		tempBullet->setType(true);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(4000);
		tempBullet->setRng(1000.f);
		tempBullet->setAOE(60.f);
		
		float tempDmg = (2.f + character->getStats().attackPower);
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 18: {//EARTH SLAM

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_EARTH_SLAM_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setSpriteSize(animation::LARGE_SKILL_WIDTH, animation::LARGE_SKILL_HEIGHT);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setRng(100.f);
		tempBullet->setCollision(false);
		tempBullet->setdX(0.f);
		tempBullet->setdY(0.f);
		tempBullet->setSpeed(0.f);
		tempBullet->setType(true);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(2000);
		tempBullet->setAOE(50.f);


		float tempDmg = 20.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 11: {//COMBO BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_COMBO_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setRotation(0.f);
		tempBullet->setSpriteSize(animation::LARGE_SKILL_WIDTH, animation::LARGE_SKILL_HEIGHT);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setCollision(false);
		tempBullet->setType(false);
		tempBullet->setElement(elements::WIND);
		tempBullet->setTimer(4000);
		tempBullet->setRng(200.f);
		tempBullet->setAOE(10.f);

		float tempDmg = 10.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);

		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	}
}



void skillObGenerator_t::upCharacterStat(characterStats_t &_stats) {
	character->getStats().upStat(_stats);
}