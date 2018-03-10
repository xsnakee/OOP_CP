#include "game_t.h"



game_t::game_t()
{
	//obPreference_t ob("img/mainHeroSprite.png",110,40,135,150);
	charactersList.push_back(new player_t(200.f,200.f));
}


game_t::~game_t()
{
}


void game_t::draw(sf::RenderWindow _window) {
	
	for (size_t i = 0; i < charactersList.size(); ++i) {
		_window.draw(charactersList[i]->getSprite());
	}
}