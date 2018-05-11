#include "mouseController.h"



mouseController::mouseController(sf::RenderWindow *_window, game_t &_game, cursor_t &_cursor) : cursor(_cursor), game(_game)
{
	window = _window;
}


mouseController::~mouseController()
{
}

void mouseController::eventHandler(sf::Event &event) {
	if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
		for (auto &i : game.interfaceEngine.get()->buttonList) {
			if (i->getIntRect().contains(sf::Mouse::getPosition(*window))) {
				i->action();
			}
		}
	}
}
