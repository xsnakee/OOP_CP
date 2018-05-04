 #include "game_t.h"
#include <iostream>


game_t::game_t()
{
}

game_t::game_t(sf::RenderWindow *_window, std::string _levelName): map(_levelName)
{
	window = _window;
	view = new sf::View;
	view->reset(sf::FloatRect(0, 0, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	window->setMouseCursorVisible(false);
	clock = std::unique_ptr<sf::Clock>(new sf::Clock);

	cursor = new cursor_t("img/cursor_aim.png",20,20, window);

	speedMultipple = 900.f; //formula (gameSpeed = time/speedMultipple)
	speed = 10.f;
	
	//generateTextureList();

	map.fillTheMapObj();
	map.fillTheMapTiles();

	generateMapObjects(map.mapObList);
	generateMapTiles(map.groundTilesList);


	using namespace animation;
	std::shared_ptr<sf::Texture> temp = std::make_shared<sf::Texture>();
	temp->loadFromFile(MAIN_HERO_TEXTURE_FILE);

	//animation::generateTextureList();

	charactersList.push_back(std::unique_ptr <character_t>(new player_t(temp, bulletsList,1700.f, 1700.f, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT, clock.get())));
	mainHero = charactersList.begin();

	controller = std::unique_ptr<keyboardController>(new PlayerController(clock.get(), (*mainHero).get()));
	generateNpc();
}

	

game_t::~game_t()
{
	delete view;
	delete cursor;
}


void game_t::update() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();

	checkAlive();

	bulletEngine();
	visionEngine();
	charsAction();
	collisionEngine();

	(*mainHero)->setTargetCoords(cursor->getPosition());
	//*
	if (((*mainHero)->getState()->getStateNum() == 4) && (*mainHero)->checkSkillGenerator() && ((*mainHero)->getTimers().castReady())) {
		(*mainHero)->generateSkillAndClearElemList();
		(*mainHero)->changeState(new CharacterPlayerControll_t(mainHero->get()));
	}
	//*/

	for (auto &character : charactersList) {
		(character)->update(speed);
	}

	
	for (auto &bullet : bulletsList) {
		bullet->update(speed);
	}
	

	setCamera();//set Camera
	window->setView(*view); // Set camera
	cursor->setCursorPosition();
}

void game_t::charsAction() {
	for (auto &i : charactersList) {
		i.get()->getState()->Action();
	}
}

void game_t::draw() {
	

	for (auto &texture : mapTilesList) {
		window->draw(texture->getSprite());
	}

	for (auto &ob : obList) {
		window->draw(ob->getSprite());
	}

	for (auto &character : charactersList) {
		window->draw(character->getSprite());
	}

	for (auto &bullet : bulletsList) {
		window->draw(bullet->getSprite());
	}
	drawCursor();
}

void game_t::keyController(sf::Event &event) {
		if ((*mainHero)->getAlive()) {
			controller->eventHandler(event);
		}
}

void game_t::checkAlive() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();
	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		(*tempCharIter)->checkAlive();

		if (tempCharIter != mainHero) {
			if (!(*tempCharIter)->getAlive()) {
				tempCharIter->reset();
				charactersList.erase(tempCharIter);
				//(*tempCharIter)->getSprite().scale(0.1f,0.1f);
			}
		}
		else {
			if (!(*tempCharIter)->getAlive()) {
				std::cout << "GAME OVER";
			}
		}

		
	}

	
	std::list<std::unique_ptr <bullet_t>>::iterator tempOb = bulletsList.begin();

	for (auto &bullet : bulletsList) {
		bullet->checkAlive();
		if (!bullet->getAlive()) {
			bulletsList.erase(tempOb);
		}

		++tempOb;
	}
	//*/
}

void game_t::bulletEngine() {

	// Bullet collision
	for (auto &outerElement : bulletsList) {
		for (auto &innerElement : obList) {
			if (outerElement->checkCollision(*innerElement)) {
				outerElement->collisionHandler(*innerElement, speed);
			}
		}
		for (auto &innerElement : charactersList) {
			if ((outerElement->checkCollision(*innerElement.get()))) {
				outerElement->collisionHandler(*innerElement.get(), speed);
				innerElement.get()->getState()->setTargetCharacter((outerElement.get()->getGenericObject()));
			}
		}
	}
}

void game_t::visionEngine() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();

	for (auto &outerElement : charactersList) {
		if (tempCharIter++ != mainHero) {
			for (auto &innerElement : charactersList) {
				if ((outerElement->getFraction() != innerElement->getFraction() && (outerElement->checkEnemy(innerElement.get())))) {
					outerElement->getState()->setTargetCharacter(innerElement.get());
				}
			}
		}
		
	}
}

void game_t::collisionEngine() {
	float characterBorderError = 10.f;
	for (auto &outerElement : charactersList) {
		/*
		for (auto &innerElement : charactersList) {
			if ((outerElement != innerElement) && (outerElement->checkCollision(*innerElement.get()))) {
				outerElement->collisionHandler(*innerElement.get(), speed);
			}
		}*/
		for (auto &innerElement : obList) {
			if (outerElement->checkCollision(*innerElement,characterBorderError/2)) {
				outerElement->collisionHandler(*innerElement, speed);
			}
		}
	}
}

void game_t:: addOb(physOb_t *bullet) {
	obList.push_back(bullet);
}

void game_t::addChar(character_t *NPC) {
	//charactersList.push_back(std::unique_ptr <character_t>(new ));
}

void game_t::generateMapObjects(std::list<physOb_t*> &_obList) {

	obList.insert(obList.end(), _obList.begin(), _obList.end());
	map.mapObList.clear();
}

void game_t::generateMapTiles(std::list<ground_t*> &_obList) {

	mapTilesList.insert(mapTilesList.end(), _obList.begin(), _obList.end());
	map.groundTilesList.clear();
}

void game_t::setCamera() {

	float _x = (*mainHero)->getPosX();
	float _y = (*mainHero)->getPosY();
	

	//EDIT THIS FOR CAMERA CONTROLL
	float leftBorder = static_cast<float>(window->getSize().x) / 2;
	float topBorder = static_cast<float>(window->getSize().y) / 2;
	
	float rightBorder = map.getSize().x - (static_cast<float>(window->getSize().x) / 2);
	float bottomBorder = map.getSize().y - (static_cast<float>(window->getSize().y) / 2);
	
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

void game_t::generateTextureList() {
	
}

void game_t::drawCursor() {
	window->draw(cursor->getSprite());
}



void game_t::generateNpc() {
	size_t NpcTypeAmount = 3;
	size_t tempCounter = 0;
	while (tempCounter++ < NpcTypeAmount) {
		using namespace animation;
		switch (tempCounter) {
		case 1: {
			size_t demonsAmount = 20;
			size_t temp = 0;

			sf::Vector2f spawnCoords(1800.f, 1800.f);

			std::shared_ptr<sf::Texture> demonText = std::make_shared<sf::Texture>();

			demonText->loadFromFile(ENEMY_DEMON_FILE);

			while (temp++ < demonsAmount) {
				charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(demonText, bulletsList, clock.get(), spawnCoords, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT, 1.f, temp*10.f, temp*10.f))));
			}

			break;
		}
		case 2: {
			size_t warriorsAmount = 20;
			size_t temp = 0;

			sf::Vector2f spawnCoords(1900.f, 1800.f);

			std::shared_ptr<sf::Texture> WarriorText = std::make_shared<sf::Texture>();

			WarriorText->loadFromFile(ENEMY_WARRIOR_FILE);
			while (temp++ < warriorsAmount) {
				charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(WarriorText, bulletsList, clock.get(), spawnCoords, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT, 1.f, temp*10.f, temp*10.f))));
			}

			break;
		}
		case 3: {
			size_t magesAmount = 20;
			size_t temp = 0;

			sf::Vector2f spawnCoords(1700.f, 1500.f);

			std::shared_ptr<sf::Texture> magesText(new sf::Texture());

			magesText->loadFromFile(ENEMY_MAGE_FILE);
			while (temp++ < magesAmount) {
				charactersList.push_back(std::move(std::unique_ptr <character_t>(new Npc_t(magesText, bulletsList, clock.get(), spawnCoords, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT, 1.f, temp*10.f, temp*10.f))));
			}
			break;
		}
		}
	}
}