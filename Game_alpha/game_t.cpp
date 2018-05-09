#include "game_t.h"



game_t::game_t(sf::RenderWindow *_window)
{
	window = _window;
}


game_t::~game_t()
{
}


void game_t::start() {
	mainMenu = std::unique_ptr<mainMenu_t>(new mainMenu_t(window,levelName,difficulty));
	mainMenu->action();

	mode = modes::PLAY;
	level = std::unique_ptr<Level_t>(new Level_t(levelName));
	if (!level->succesfull) {
		std::cout << "MAP_FILE_IS_NOT_OPEN";
		return;
	}
	game = std::unique_ptr<GameEngine_t>(new GameEngine_t(window, *level.get(),difficulty));
	interface = std::unique_ptr<InterfaceEngine_t>(new InterfaceEngine_t(window, *level.get()));
	controller = std::unique_ptr<keyboardController>(new PlayerController(level->mainHero->get()));

	mainMenu.reset();
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
