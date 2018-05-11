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

void mouseController::menuEventHandler(sf::Event &event) {	
		
			game.interfaceEngine->restartButton->get()->contentList.back()->setFontColor(sf::Color::White);
			game.interfaceEngine->backTomainMenuButton->get()->contentList.back()->setFontColor(sf::Color::White);

			if (game.interfaceEngine->restartButton->get()->getIntRect().contains(sf::Mouse::getPosition(*window))) {
				game.interfaceEngine->restartButton->get()->contentList.back()->setFontColor(sf::Color::Green);
				if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
					game.interfaceEngine->restartButton->get()->action();
					game.setGameStatus(game::RESTART);
				}
			}
			else if (game.interfaceEngine->backTomainMenuButton->get()->getIntRect().contains(sf::Mouse::getPosition(*window))) {
				game.interfaceEngine->backTomainMenuButton->get()->contentList.back()->setFontColor(sf::Color::Green);
				if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
					game.setGameStatus(game::MAIN_MENU);
				}
			}	
	
}