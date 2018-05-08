#include "game_t.h"



game_t::game_t(sf::RenderWindow *_window)
{
	window = _window;
	mode = modes::START_MENU;
}


game_t::~game_t()
{
}


void game_t::start(std::string _levelName, size_t _difficulity) {
	difficulity = _difficulity;

	level = std::unique_ptr<Level_t>(new Level_t(_levelName));
	game = std::unique_ptr<GameEngine_t>(new GameEngine_t(window, *level.get()));
	interface = std::unique_ptr<InterfaceEngine_t>(new InterfaceEngine_t(window, *level.get()));
	controller = std::unique_ptr<keyboardController>(new PlayerController(level->mainHero->get()));
	mode = modes::PLAY;
	play();
}

void game_t::play() {
	using namespace sf;

	Event event;

	while (window->isOpen()) {
		switch (mode) {

		case modes::PLAY: {
			float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
			clock.restart();
			game->setSpeed(timer);

			while (window->pollEvent(event)) {
				if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) {
					window->close();
				}
			}
			keyController(event);
			game->update();
			interface->update();
			break;
		}

		case modes::PAUSED:{
		
			break;
		}
		}




		window->clear();
		game->draw();
		interface->draw();
		window->display();
		
	}
}

void game_t::keyController(sf::Event &event) {
	if (level->mainHero->get()->getAlive()) {
		controller->eventHandler(event);
	}
}
