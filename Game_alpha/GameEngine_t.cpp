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
	temp->loadFromFile(BOSS_FINALY_DEMON_TEXURE_FILE);//
	tiles::sizes tempSizes = tiles::getSizesFromStr(BOSS_FINALY_DEMON_TEXURE_FILE);
	level.charactersList.push_back(std::unique_ptr <character_t>(new player_t(temp, level.bulletsList, 1350.f, 1550.f, tempSizes.width, tempSizes.height, clock.get())));
	level.mainHero = level.charactersList.begin();

	generateNpc();
}

	

GameEngine_t::~GameEngine_t()
{
	delete view;
	delete cursor;
}


void GameEngine_t::update() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = level.charactersList.begin();

	checkAlive();

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
			}
		}
		else {
			if (!(*tempCharIter)->getAlive()) {
				std::cout << "GAME OVER";
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
			if (outerElement->checkCollision(*innerElement, 10.f)) {
				outerElement->collisionHandler(*innerElement, speed);
			}
		}
	}
}




void GameEngine_t::setCamera() {

	float _x = level.mainHero->get()->getPosX();
	float _y = level.mainHero->get()->getPosY();
	

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



void GameEngine_t::generateNpc() {
	std::list<std::unique_ptr<Npc_t>> NpcTypeList;
	size_t NpcTypeAmount = 3;
	size_t tempCounter = 0;
	tiles::sizes tempSizes;

	while (tempCounter++ < NpcTypeAmount) {
		using namespace animation;
		switch (tempCounter) {
		case 1: {
			size_t demonsAmount = 20;
			size_t temp = 0;


			std::shared_ptr<sf::Texture> demonText = std::make_shared<sf::Texture>();

			demonText->loadFromFile(ENEMY_DEMON_FILE);
			tempSizes = tiles::getSizesFromStr(ENEMY_DEMON_FILE);

			while (temp++ < demonsAmount) {
				sf::Vector2f spawnCoords(1800.f+temp*10, 1800.f + temp * 10);
				level.charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(demonText, level.bulletsList, clock.get(), spawnCoords, tempSizes.width, tempSizes.height))));

			}

			break;
		}
		case 2: {
			size_t warriorsAmount = 20;
			size_t temp = 0;


			std::shared_ptr<sf::Texture> WarriorText = std::make_shared<sf::Texture>();

			WarriorText->loadFromFile(ENEMY_WARRIOR_FILE);
			tempSizes = tiles::getSizesFromStr(ENEMY_WARRIOR_FILE);
			sf::Vector2f spawnCoords(1900.f + temp * 10, 1800.f + temp * 10);
			while (temp++ < warriorsAmount) {
				level.charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(WarriorText, level.bulletsList, clock.get(), spawnCoords, tempSizes.width, tempSizes.height))));
			}

			break;
		}
		case 3: {
			size_t magesAmount = 20;
			size_t temp = 0;


			std::shared_ptr<sf::Texture> magesText(new sf::Texture());

			magesText->loadFromFile(ENEMY_MAGE_FILE);
			tempSizes = tiles::getSizesFromStr(ENEMY_MAGE_FILE);
			while (temp++ < magesAmount) {
				sf::Vector2f spawnCoords(1700.f + temp * 10, 1500.f + temp * 10);
				level.charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(magesText, level.bulletsList, clock.get(), spawnCoords, tempSizes.width, tempSizes.height))));
				level.charactersList.back()->setElemStatus(5);
				level.charactersList.back()->getStats().attackRange = 150.f;
			}
			break;
		}
		}
	}
}