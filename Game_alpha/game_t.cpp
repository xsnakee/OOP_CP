#include "game_t.h"



game_t::game_t():clock()
{
	speedMultipple = 800.f;
	speed = 10.f;

	obPreference ob("img/mainHeroSprite.png",195,0,25,30);
	charactersList.push_back(new player_t(200.f,200.f,ob));


	//obList.push_back(new physOb_t(400.f, 400.f));
}


game_t::~game_t()
{
}


void game_t::update() {

	for (int i = 0; i < charactersList.size(); ++i) {
		charactersList[i]->update(speed);
	}


}

void game_t::draw(sf::RenderWindow *_window) {
	
	

	for (int i = 0; i < charactersList.size(); ++i) {

		character_t *temp = charactersList[i];

		if (charactersList[i]->getAlive()) {
			_window->draw(temp->getSprite());
		}
			
	}
	
	std::list<physOb_t*>::iterator tempOb = obList.begin();

	for (int i = 0; i < obList.size(); ++i, ++tempOb){
			_window->draw((*tempOb)->getSprite());
				
	}
}

void game_t::keyController(sf::Event &event) {
	using namespace sf;

	//NAVIGATION CONTROLLER	
	charactersList[0]->controller(event);

	

	//ATACK CONTROLLER


}

void game_t::checkAlive() {

	physOb_t *temp;

	for (int i = 0; i < charactersList.size(); ++i) {

		temp = charactersList[i];

		if (!charactersList[i]->getAlive()) {
			charactersList.erase(charactersList.begin() + i);
		}

	}

	std::list<physOb_t*>::iterator tempOb = obList.begin();

	for (int i = 0; i < obList.size(); ++i, ++tempOb) {

		if (!(*tempOb)->getAlive()) {
			obList.erase(tempOb);
		}

	}
}