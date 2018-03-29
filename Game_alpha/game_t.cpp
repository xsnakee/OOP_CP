#include "game_t.h"
#include <iostream>


game_t::game_t():clock()
{
	speedMultipple = 800.f;
	speed = 10.f;
	charactersList.push_back(new player_t(200.f,200.f,MAIN_HERO_TEXTURE_FILE,SPRITE_X,SPRITE_Y,MAIN_HERO_SPRITE_WIDTH,MAIN_HERO_SPRITE_HEIGHT,&clock));

	//obList.push_back(new physOb_t(400.f, 400.f));
}

game_t::game_t(std::string mapFileName, std::string _tileFileName, int _sizeX, int _sizeY):clock(), map(mapFileName, _sizeX, _sizeY,  _tileFileName)
{
	speedMultipple = 800.f;
	speed = 10.f;
	
	charactersList.push_back(new player_t(200.f, 200.f, MAIN_HERO_TEXTURE_FILE, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT,&clock));
	//map.fillTheMap();
}

game_t::~game_t()
{
}


void game_t::update() {

	std::list<character_t*>::iterator tempCharIter = charactersList.begin();

	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		(*tempCharIter)->update(speed);
	}


}

void game_t::draw(sf::RenderWindow *_window) {
	
	std::list<character_t*>::iterator tempCharIter = charactersList.begin();

	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
			_window->draw((*tempCharIter)->getSprite());			
	}
	
	std::list<physOb_t*>::iterator tempOb = obList.begin();

	for (int i = 0; i < obList.size(); ++i, ++tempOb){
			_window->draw((*tempOb)->getSprite());
				
	}


	std::list<ground_t*>::iterator tempIt;
	for (tempIt = map.groundTilesList.begin(); tempIt != map.groundTilesList.end(); ++tempIt) {
		_window->draw((*tempIt)->getSprite());
	}
}

void game_t::keyController(sf::Event &event) {
	using namespace sf;
	std::list<character_t*>::iterator mainHero = charactersList.begin();
	sf::Keyboard::Key tempKey = event.key.code;
	//NAVIGATION CONTROLLER	{
		if ((*mainHero)->getAlive()) {
			(*mainHero)->controller(event);
		}
	
	

	//ATACK CONTROLLER
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
					//obList.push_back(new bullet_t(&clock, (*mainHero)->getPosX(), (*mainHero)->getPosY(), 0.1f,elements::WIND, 10.f));
	}

}

void game_t::checkAlive() {

	std::list<character_t*>::iterator tempCharIter = charactersList.begin();
	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		if (!(*tempCharIter)->getAlive()) {
			delete (*tempCharIter);
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
	charactersList.push_back(NPC);
}

