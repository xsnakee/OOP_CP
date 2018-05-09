 #include "GameEngine_t.h"
#include <iostream>

//, level.charactersList(level.level.charactersList),level.bulletsList(level.level.bulletsList), level.mapTilesList(level.level.mapTilesList), level.obList(level.level.obList)

GameEngine_t::GameEngine_t(sf::RenderWindow *_window, Level_t &_level, size_t _difficulty):level(_level)
{
	window = _window;
	difficulty = _difficulty;
	view = new sf::View;
	view->reset(sf::FloatRect(0, 0, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	window->setMouseCursorVisible(false);
	clock = std::unique_ptr<sf::Clock>(new sf::Clock);

	cursor = new cursor_t("img/cursor_aim.png",20,20, window);
	speedMultipple = 900.f; //formula (gameSpeed = time/speedMultipple)
	speed = 10.f;


	using namespace animation;
	std::shared_ptr<sf::Texture> temp = std::make_shared<sf::Texture>();
	temp->loadFromFile(MAIN_HERO_TEXTURE_FILE);//
	tiles::sizes tempSizes = tiles::getSizesFromStr(MAIN_HERO_TEXTURE_FILE);
	level.charactersList.push_back(std::unique_ptr <character_t>(new player_t(temp, level.bulletsList, 1350.f, 1550.f, tempSizes.width, tempSizes.height, clock.get())));
	level.mainHero = level.charactersList.begin();
	generateNpcTypes();

	generateNpc();
	generateBosses();
}

	

GameEngine_t::~GameEngine_t()
{
	delete view;
	delete cursor;
}


bool GameEngine_t::positionCollision(const sf::Vector2f _obPos) {
	for (auto &i :level.obList) {
		if (i->getFloatRect().contains(_obPos)) {
			return true;
		}
	}
	return false;
}

void GameEngine_t::generateNpcTypes() {
	using namespace animation;
	tiles::sizes tempSizes;
	sf::Vector2f defaultSpawnCoords(0.f, 0.f);

	//DEMON TYPE NPC
	std::shared_ptr<sf::Texture> demonTexture = std::make_shared<sf::Texture>();
	demonTexture->loadFromFile(ENEMY_DEMON_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_DEMON_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new Npc_t(demonTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));

	//WARRIOR TYPE NPC
	std::shared_ptr<sf::Texture> WarriorTexture = std::make_shared<sf::Texture>();
	WarriorTexture->loadFromFile(ENEMY_WARRIOR_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_WARRIOR_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new WarriorNpc_t(WarriorTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));


	//MAGE TYPE NPC 
	std::shared_ptr<sf::Texture> magesTexture(new sf::Texture());
	magesTexture->loadFromFile(ENEMY_MAGE_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_MAGE_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new MageNpc_t(magesTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));

	//ZOMBIE WITCH NPC ZombieWitch_t
	std::shared_ptr<sf::Texture> zombiWitchTexture(new sf::Texture());
	zombiWitchTexture->loadFromFile(ENEMY_ZOMBIE_WITCH_TEXTURE_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_ZOMBIE_WITCH_TEXTURE_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new ZombieWitch_t(zombiWitchTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));


	//FAT ZOMBIE CLASS FatZombie_t
	std::shared_ptr<sf::Texture> fatZombieTexture(new sf::Texture());
	fatZombieTexture->loadFromFile(ENEMY_ZOMBIE_PUDGE_TEXURE_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_ZOMBIE_PUDGE_TEXURE_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new FatZombie_t(fatZombieTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));


	//SKELETON MAGE CLASS SkeletonMage_t
	std::shared_ptr<sf::Texture> skeletonMageTexture(new sf::Texture());
	skeletonMageTexture->loadFromFile(ENEMY_SKELETON_MAGE_TEXTURE_FILE);
	tempSizes = tiles::getSizesFromStr(ENEMY_SKELETON_MAGE_TEXTURE_FILE);
	npcTypesList.push_back(std::unique_ptr <character_t>(new SkeletonMage_t(skeletonMageTexture, level.bulletsList, clock.get(), defaultSpawnCoords, tempSizes.width, tempSizes.height)));

	

}

void GameEngine_t::generateNpc() {
	size_t NpcTypeAmount = npcTypesList.size();
	size_t tempCounter = 0;

	size_t NpcAmount = 20 * difficulty;

	sf::Vector2f tempCoords;

	for (auto &i : npcTypesList) {
		tempCounter = 0;
		while (tempCounter++ < NpcAmount) {
			do {
				tempCoords = generateRandomSpawnCoords(level.map.getSize());
			} while (positionCollision(tempCoords));

			level.charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(i.get(), tempCoords,STD_DIFFICULTY_COEFFICIENT + static_cast<float>(difficulty)))));
		}
	}

}

void GameEngine_t::generateBosses() {
}


void GameEngine_t::update() {
	if (level.checkLevelComplete()) {
		return;
	}

	checkAlive();

	if (!level.gameOver) {

		bulletEngine();
		visionEngine();
		charsAction();
		collisionEngine();

		level.mainHero->get()->setTargetCoords(cursor->getPosition());

		for (auto &character : level.charactersList) {
			(character)->update(speed);
		}


		for (auto &bullet : level.bulletsList) {
			bullet->update(speed);
		}


		setCamera();//set Camera
		window->setView(*view); // Set camera
		cursor->setCursorPosition();
	}
	
}

void GameEngine_t::charsAction() {
	for (auto &i : level.charactersList) {
		i.get()->getState()->Action();
	}
}

void GameEngine_t::draw() {
	

	for (auto &texture : level.mapTilesList) {
		window->draw(texture->getSprite());
	}

	for (auto &ob : level.obList) {
		window->draw(ob->getSprite());
	}

	for (auto &character : level.charactersList) {
		window->draw(character->getSprite());
	}

	for (auto &bullet : level.bulletsList) {
		window->draw(bullet->getSprite());
	}
	drawCursor();
}


void GameEngine_t::checkAlive() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = level.charactersList.begin();
	for (int i = 0; i < level.charactersList.size(); ++i, ++tempCharIter) {

		if (tempCharIter != level.mainHero) {
			if (!(*tempCharIter)->getAlive()) {
				tempCharIter->reset();
				level.charactersList.erase(tempCharIter);
				level.checkMissionsTarget();
			}
		}
		else {
			if (!(*tempCharIter)->getAlive()) {
				level.gameOver = true;
			}
		}

		
	}

	
	std::list<std::unique_ptr <bullet_t>>::iterator tempOb = level.bulletsList.begin();

	for (auto &bullet : level.bulletsList) {
		if (!bullet->getAlive()) {
			level.bulletsList.erase(tempOb);
		}

		++tempOb;
	}
	//*/
}

void GameEngine_t::bulletEngine() {

	// Bullet collision
	for (auto &outerElement : level.bulletsList) {
		for (auto &innerElement : level.obList) {
			if (outerElement->checkCollision(*innerElement)) {
				outerElement->collisionHandler(*innerElement, speed);
			}
		}
		for (auto &innerElement : level.charactersList) {
			if ((outerElement->checkCollision(*innerElement.get()))) {
				outerElement->collisionHandler(*innerElement.get(), speed);
				if (outerElement->getFraction() != innerElement->getFraction() && innerElement->getAlive()) {
					innerElement.get()->getState()->setTargetCharacter((outerElement.get()->getGenericObject()));
				}
			}
		}
	}
}

void GameEngine_t::visionEngine() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = level.charactersList.begin();

	for (auto &outerElement : level.charactersList) {
		if (tempCharIter++ != level.mainHero) {
			for (auto &innerElement : level.charactersList) {
				if ( (innerElement->getAlive() && outerElement->getFraction() != innerElement->getFraction() && (outerElement->checkEnemy(innerElement.get())))) {
					outerElement->getState()->setTargetCharacter(innerElement.get());
				}
			}
		}
		
	}
}

void GameEngine_t::collisionEngine() {
	float characterBorderError = 10.f;
	for (auto &outerElement : level.charactersList) {
		
		for (auto &innerElement : level.obList) {
			if (outerElement->checkCollision(*innerElement, 2.f)) {
				outerElement->collisionHandler(*innerElement, speed);
			}
		}
	}
}

void GameEngine_t::setCamera() {

	float _x = level.mainHero->get()->getCoordsOfCenter().x;
	float _y = level.mainHero->get()->getCoordsOfCenter().y;
	

	//EDIT THIS FOR CAMERA CONTROLL
	float leftBorder = static_cast<float>(window->getSize().x) / 2;
	float topBorder = static_cast<float>(window->getSize().y) / 2;
	
	float rightBorder = level.map.getSize().x - (static_cast<float>(window->getSize().x) / 2);
	float bottomBorder = level.map.getSize().y - (static_cast<float>(window->getSize().y) / 2);
	
	float error = 5.0f;
	
	if (_x < leftBorder) {
		_x = leftBorder;
	}
	else if (_x > rightBorder) {
		_x = rightBorder;
	}

	if (_y > bottomBorder) {
		_y = bottomBorder;
	}
	else if (_y < topBorder) {
		_y = topBorder;
	}

	view->setCenter(_x, _y);
}



void GameEngine_t::drawCursor() {
	window->draw(cursor->getSprite());
}



