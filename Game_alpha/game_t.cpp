#include "game_t.h"



game_t::game_t()
{
	charactersList.push_back(new player_t(200.f,200.f));
}


game_t::game_t(sf::RenderWindow window):game_t() {
}

game_t::~game_t()
{
}
