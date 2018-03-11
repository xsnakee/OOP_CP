#include "game_t.h"



game_t::game_t()
{
	obPreference ob("img/mainHeroSprite.png",195,0,25,30);
	charactersList.push_back(new player_t(200.f,200.f,ob));
}


game_t::~game_t()
{
}


void game_t::draw(sf::RenderWindow _window) {
	
	for (int i = 0; i < charactersList.size(); ++i) {
		_window.draw(charactersList[i]->getSprite());
	}
}