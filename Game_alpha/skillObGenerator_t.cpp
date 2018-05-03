#include "skillObGenerator_t.h"



skillObGenerator_t::skillObGenerator_t(player_t *_character)
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
	case 4: {//SMALL FIRE BALLS
		
		sf::Texture *tempTexture = new sf::Texture();
		tempTexture->loadFromFile(animation::BULLET_FIRE_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setAOE(50.f);
		tempBullet->setCollision(false);
		tempBullet->setSpeed(0.2f);
		tempBullet->setType(true);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(2000);

		float tempDmg = 5.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		bulletList.push_back(tempBullet);

		break;
	}

	case 10: {//SMALL FIRE BALLS

		sf::Texture *tempTexture = new sf::Texture();
		tempTexture->loadFromFile(animation::BULLET_FIRE_BALL_TEXTURE_FILE);

		std::unique_ptr<bullet_t> tempBullet(new bullet_t(character->getClockPtr(), character, character->getTargetCoords()));
		tempBullet->setTexturePtr(tempTexture);

		tempBullet->setAOE(50.f);
		tempBullet->setCollision(false);
		tempBullet->setSpeed(0.2f);
		tempBullet->setType(true);
		tempBullet->setElement(elements::FIRE);
		tempBullet->setTimer(2000);

		float tempDmg = 5.f + character->getStats().attackPower;
		tempBullet->setDmg(tempDmg);


		bulletList.push_back(tempBullet);

		break;
	}

	}
}



void skillObGenerator_t::upCharacterStat(characterStats_t &_stats) {
	character->getStats().upStat(_stats);
}
void skillObGenerator_t::generateBullet(bullet_t *bullet) {

}