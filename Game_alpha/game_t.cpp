#include "game_t.h"
#include <iostream>


game_t::game_t():clock()
{
	window = nullptr;
	view = new sf::View;

	speedMultipple = 800.f;
	speed = 10.f;

	using namespace animation;

	charactersList.push_back(std::unique_ptr <character_t>(new player_t(200.f,200.f,MAIN_HERO_TEXTURE_FILE,SPRITE_X,SPRITE_Y,MAIN_HERO_SPRITE_WIDTH,MAIN_HERO_SPRITE_HEIGHT,&clock)));
}

game_t::game_t(sf::RenderWindow *_window, std::string _levelName):clock(), map(_levelName)
{
	window = _window;
	view = new sf::View;
	view->reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	window->setMouseCursorVisible(false);


	cursor = new cursor_t("img/cursor_aim.png",20,20, window);

	speedMultipple = 900.f; //formula (gameSpped = time/speedMultipple)
	speed = 10.f;
	
	using namespace animation;
	charactersList.push_back(std::unique_ptr <character_t>(new player_t(600.f, 600.f, MAIN_HERO_TEXTURE_FILE, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT,&clock)));
	mainHero = charactersList.begin();

	map.fillTheMap();

	generateMapObjects(map.mapObList);
}

game_t::~game_t()
{
	delete view;
	delete cursor;
}


void game_t::update() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();

	

	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		(*tempCharIter)->update(speed);
	}

	setCamera();//set Camera
	window->setView(*view); // Set camera
	cursor->setCursorPosition();
}

void game_t::draw() {
	


	window->draw(map.mapBgSprite);

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();

	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		window->draw((*tempCharIter)->getSprite());
	}

	std::list<physOb_t*>::iterator tempOb = obList.begin();

	for (int i = 0; i < obList.size(); ++i, ++tempOb) {
		window->draw((*tempOb)->getSprite());
	}

	drawCursor();
}

void game_t::keyController(sf::Event &event) {
	using namespace sf;

	std::list<std::unique_ptr <character_t>>::iterator mainHero = charactersList.begin();
	sf::Keyboard::Key tempKey = event.key.code;
	//NAVIGATION CONTROLLER	{
		if ((*mainHero)->getAlive()) {
			(*mainHero)->controller(event);
		}
	
	

	//ATACK CONTROLLER
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		
			obList.push_back(new bullet_t(&clock, 1000, (*mainHero)->getPosX(), (*mainHero)->getPosY(), 0.1f, elements::WIND, sf::Mouse::getPosition(*window), 10.f));
			
	}

}

void game_t::checkAlive() {

	std::list<std::unique_ptr <character_t>>::iterator tempCharIter = charactersList.begin();
	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		if (!(*tempCharIter)->getAlive()) {
			charactersList.erase(tempCharIter);		
		}
	}

	std::list<physOb_t*>::iterator tempOb = obList.begin();
	for (int i = 0; i < obList.size(); ++i, ++tempOb) {

		(*tempOb)->checkTimer(&clock);
		if (!(*tempOb)->getAlive()) {
			delete (*tempOb);
			obList.erase(tempOb);
		}

	}
}


void game_t:: addOb(physOb_t *bullet) {
	obList.push_back(bullet);
}

void game_t::addChar(character_t *NPC) {
	//charactersList.push_back(std::unique_ptr <character_t>(new ));
}

void game_t::generateMapObjects(std::list<physOb_t*> _obList) {
	obList.insert(obList.end(), _obList.begin(), _obList.end());
}

void game_t::setCamera() {

	float _x = (*mainHero)->getPosX();
	float _y = (*mainHero)->getPosY();
	

	//EDIT THIS FOR CAMERA CONTROLL
	float leftBorder = window->getSize().x / 2;
	float topBorder = window->getSize().y / 2;
	
	float rightBorder = map.getSize().x - (window->getSize().x / 2);
	float bottomBorder = map.getSize().y - (window->getSize().y / 2);
	

	
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



void game_t::drawCursor() {
	window->draw(cursor->getSprite());
}