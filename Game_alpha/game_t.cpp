#include "game_t.h"



game_t::game_t():clock()
{
	speedMultipple = 100.f;
	speed = 0.f;

	obPreference ob("img/mainHeroSprite.png",195,0,25,30);
	charactersList.push_back(new player_t(200.f,200.f,ob));


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
		_window->draw(charactersList[i]->getSprite());
	}
}

void game_t::keyController(sf::Event &event) {
	using namespace sf;

	//NAVIGATION CONTROLLER
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		charactersList[0]->stat.speed = charactersList[0]->stat.stdSpeed;
		float tempSpeed = charactersList[0]->stat.speed;
		charactersList[0]->setdY(-tempSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {

		charactersList[0]->stat.speed = charactersList[0]->stat.stdSpeed;
		float tempSpeed = charactersList[0]->stat.speed;
		charactersList[0]->setdY(tempSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {

		charactersList[0]->stat.speed = charactersList[0]->stat.stdSpeed;
		float tempSpeed = charactersList[0]->stat.speed;
		charactersList[0]->setdX(-tempSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {

		charactersList[0]->stat.speed = charactersList[0]->stat.stdSpeed;
		float tempSpeed = charactersList[0]->stat.speed;
		charactersList[0]->setdX(tempSpeed);
	}

	//ATACK CONTROLLER


}