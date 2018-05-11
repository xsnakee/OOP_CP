#include "mouseController.h"



mouseController::mouseController(sf::RenderWindow *_window, std::list<button> &_buttonList, cursor_t &_cursor) :buttonList(_buttonList), cursor(_cursor)
{
	window = _window;
}


mouseController::~mouseController()
{
}

void mouseController::eventHandler(sf::Event &event) {
	if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
		for (auto &i : buttonList) {
			if (i->getIntRect().contains(sf::Mouse::getPosition(*window))) {
				i->action();
			}
		}
	}
}
