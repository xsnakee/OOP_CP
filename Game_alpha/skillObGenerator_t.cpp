#include "skillObGenerator_t.h"



skillObGenerator_t::skillObGenerator_t(character_t *_character, std::list<std::unique_ptr <bullet_t>> &_bulletList):skillGeneratorBulletList(_bulletList)
{
	character = _character;
}


skillObGenerator_t::~skillObGenerator_t()
{
}

void skillObGenerator_t::useSkill() {
	/*//SKILL LIST

	1 - sword attack
	2 - poision ball
	3 - speed buff
	4 - fire lighting
	5 - fire ball
	6 - power buff
	7 - attack speed buff
	10 - mass earth balls
	11 - combo ball
	12 - fire breath
	17 - earth ball
	18 - bang ball
	24 - heal stone
	//*/
	size_t skillType = character->getElemStatus();

	switch (skillType) {
	case 3: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.speed += 0.05f;
		upCharacterStat(tempStat);
		character->changeEffect(new Effect_t(character, tempStat));
		character->getEffectPtr()->useEffect();
		float buffMPcost = 50.f;
		character->useMP(buffMPcost);
		break;
	}
	case 6: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.attackPower += 20.f;
		tempStat.physDef += 20.f;
		tempStat.magDef += 20.f;
		upCharacterStat(tempStat);
		character->changeEffect(new Effect_t(character, tempStat, 10000));
		character->getEffectPtr()->useEffect();
		float buffMPcost = 50.f;
		character->useMP(buffMPcost);
		break;
	}
	case 7: {
		characterStats_t tempStat;
		tempStat.resetStats();
		tempStat.attackSpeed += 20.f;
		upCharacterStat(tempStat);
		character->changeEffect(new Effect_t(character, tempStat, 3000));
		character->getEffectPtr()->useEffect();
		float buffMPcost = 50.f;
		character->useMP(buffMPcost);
		break;
	}
	case 24: {//HEAL BALL
		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_CRYSTAL_HEAL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setRotation(0.f);
		tempBullet->getSprite().setScale(2.f,2.f);
		tempBullet->setTexturePtr(tempTexture);
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);

		tempBullet->setRng(character->getStats().attackRange);
		tempBullet->setCollision(false);
		tempBullet->setType(false);
		tempBullet->setdX(0.f);
		tempBullet->setdY(0.f);
		tempBullet->setSpeed(0.f);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(5000);
		tempBullet->setAOE(50.f);
		tempBullet->setDmgDelay(500);
		tempBullet->setRng(1000.f);

		float tempDmg = 5.f + character->getComputedDmg() * 0.1f;
		tempBullet->setDmg(tempDmg);
		tempBullet->setMPCost(30.f);

		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 1: {//PhysAttack

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::SWORD_ATTACK_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setSpriteSize(tempTexture->getSize().x/3, tempTexture->getSize().y);

		tempBullet->setCollision(false);
		tempBullet->speedMultiple(1.5f);
		tempBullet->setElement(elements::NONE);
		tempBullet->setTimer(500);
		tempBullet->setAOE(20.f);
		tempBullet->setRng((character->getStats().attackRange > 150.f)?150.f: character->getStats().attackRange);

		float tempDmg = 30.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);


		character->useMP(0.f);
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 2: {//POISION BALL
		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_POISION_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setRotation(0.f);
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setRng(character->getStats().attackRange);
		tempBullet->setCollision(false);
		tempBullet->speedMultiple(1.5f);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(4000);
		tempBullet->setAOE(80.f);

		tempBullet->setMPCost(10.f);

		float tempDmg = 10.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);


		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 4: {//FIRE LIGHTING
		
		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_FIRE_LIGHTING_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));

		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
		tempBullet->setTexturePtr(tempTexture);
		
		tempBullet->setCollision(true);
		tempBullet->speedMultiple(2.f);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(2000);
		tempBullet->setRng(character->getStats().attackRange);

		float tempDmg = 5.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);

		tempBullet->setMPCost(10.f);

		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 10: {//SMALL EARTH BALLS

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_SMALL_EARTH_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
		tempBullet->setTexturePtr(tempTexture);
		tempBullet->setAOE(50.f);
		tempBullet->setCollision(false);
		tempBullet->speedMultiple(1.5f);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(2000);
		tempBullet->setRng(character->getStats().attackRange);

		float tempDmg = 7.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);

		tempBullet->setMPCost(20.f);

		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 5: {//FIRE BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_FIRE_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setTexturePtr(tempTexture);
		tempBullet->setSpriteSize(tempTexture->getSize().x /3, tempTexture->getSize().y);

		tempBullet->setCollision(true);
		tempBullet->speedMultiple(1.5f);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(4000);
		tempBullet->setRng(100.f + character->getStats().attackRange);

		float tempDmg = 15.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);

		tempBullet->setMPCost(5.f);

		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 17: {//EARTH BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_EARTH_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setTexturePtr(tempTexture);
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);

		tempBullet->setCollision(true);
		tempBullet->speedMultiple(1.f);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(4000);
		tempBullet->setRng(100.f + character->getStats().attackRange);
		tempBullet->setAOE(10.f);
		tempBullet->setMPCost(20.f);

		float tempDmg = 30.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);


		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}

	case 12: {//FIRE BREATH

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_LAVA_TEXTURE_FILE);
		int amountPools = static_cast<int>(character->getStats().attackRange) / animation::LARGE_SKILL_WIDTH;

		{
			std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
			tempBullet->setRotation(0.f);

			tempBullet->setTexturePtr(tempTexture);
			tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
			tempBullet->setPosX(character->getPosOfCenter().x - character->getWidth()/2);
			tempBullet->setPosY(character->getPosOfCenter().y - character->getHeight() / 2);
			tempBullet->speedMultiple(1.2f);
			tempBullet->setCollision(false);

			tempBullet->setElement(elements::FIRE);
			tempBullet->setTimer(4000);
			tempBullet->setDmgDelay(300);
			tempBullet->setAOE(60.f);

			tempBullet->setMPCost(10.f);
			float tempDmg = (2.f + character->getComputedDmg() * 0.5f);
			tempBullet->setDmg(tempDmg);


			character->useMP(tempBullet->getMPCost());

			skillGeneratorBulletList.push_back(std::move(tempBullet));
		}
		

		break;
	}

	case 18: {//BANG BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_BANG_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setRng(character->getStats().attackRange /2);
		tempBullet->setCollision(false);
		tempBullet->speedMultiple(0.5f);
		tempBullet->setElement(elements::EARTH);
		tempBullet->setTimer(2000);


		float tempDmg = 60.f + character->getComputedDmg();
		tempBullet->setDmg(tempDmg);

		tempBullet->setMPCost(30.f);

		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	case 11: {//COMBO BALL

		std::shared_ptr<sf::Texture>tempTexture = std::make_shared<sf::Texture>();
		tempTexture->loadFromFile(animation::BULLET_COMBO_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetPos()));
		tempBullet->setSpriteSize(tempTexture->getSize().x / 3, tempTexture->getSize().y);
		tempBullet->setTexturePtr(tempTexture);
		tempBullet->speedMultiple(2.f);
		tempBullet->setAOE(30.f);
		tempBullet->setCollision(true);
		tempBullet->setElement(elements::WIND);
		tempBullet->setTimer(4000);
		tempBullet->setRng(character->getStats().attackRange);

		float tempDmg = character->getComputedDmg();
		tempBullet->setDmg(tempDmg);

		tempBullet->setMPCost(15.f);
		character->useMP(tempBullet->getMPCost());
		skillGeneratorBulletList.push_back(std::move(tempBullet));

		break;
	}
	}
}



void skillObGenerator_t::upCharacterStat(characterStats_t &_stats) {
	character->getStats().upStat(_stats);
}