#include "game_t.h"



game_t::game_t():clock()
{
	speedMultipple = 800.f;
	speed = 10.f;

	charactersList.push_back(new player_t(200.f,200.f,MAIN_HERO_TEXTURE_FILE,SPRITE_X,SPRITE_Y,MAIN_HERO_SPRITE_WIDTH,MAIN_HERO_SPRITE_HEIGHT));

	//obList.push_back(new physOb_t(400.f, 400.f));
}

game_t::game_t(std::string mapFileName, std::string _tileFileName, int _sizeX, int _sizeY):clock(), map(mapFileName, _sizeX, _sizeY,  _tileFileName)
{
	speedMultipple = 800.f;
	speed = 10.f;
	
	charactersList.push_back(new player_t(200.f, 200.f, MAIN_HERO_TEXTURE_FILE, SPRITE_X, SPRITE_Y, MAIN_HERO_SPRITE_WIDTH, MAIN_HERO_SPRITE_HEIGHT));
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
}

void game_t::keyController(sf::Event &event) {
	using namespace sf;

	//NAVIGATION CONTROLLER	
	std::list<character_t*>::iterator mainHero = charactersList.begin();
	if ((*mainHero)->getAlive()) {
		(*mainHero)->controller(event);
	}

	//ATACK CONTROLLER


}

void game_t::checkAlive() {

	std::list<character_t*>::iterator tempCharIter = charactersList.begin();
	for (int i = 0; i < charactersList.size(); ++i, ++tempCharIter) {
		if (!(*tempCharIter)->getAlive()) {
			charactersList.erase(tempCharIter);		
		}
	}

	std::list<physOb_t*>::iterator tempOb = obList.begin();
	for (int i = 0; i < obList.size(); ++i, ++tempOb) {

		if (!(*tempOb)->getAlive()) {
			obList.erase(tempOb);
		}

	}
}