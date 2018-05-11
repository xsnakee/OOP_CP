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
	level = std::unique_ptr<Level_t>(new Level_t(levelName));
	if (!level->succesfull) {
		std::cout << "MAP_FILE_IS_NOT_OPEN";
		return;
	}
	game = std::unique_ptr<GameEngine_t>(new GameEngine_t(window, *level.get(),difficulty));
	interface = std::unique_ptr<InterfaceEngine_t>(new InterfaceEngine_t(window, *level.get()));
	KBcontroller = std::unique_ptr<keyboardController>(new PlayerController(level->mainHero->get()));
	Mcontroller = std::move(std::unique_ptr<mouseController>(new mouseController(window, interface.get()->buttonList, *interface.get()->cursor)));

	mainMenu.reset();
	play();
}

void game_t::play() {
	using namespace sf;

	Event event;
	game::status mode = game::PLAY;

	while (window->isOpen()) {

		float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();

		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape) {
				if (interface->toggleMenu()) {
					mode = game::PAUSED;
				}
				else {
					mode = game::PLAY;
				}
			}
		}
		game::status gameStatus = game->getGameStatus();
		mode = (gameStatus == game::GAME_OVER || gameStatus == game::WIN)? gameStatus:mode;
		switch (mode) {
		case game::status::PLAY: {			
			game->setSpeed(timer);			
			keyController(event);
			game->update();
			break;
		}

		case game::status::PAUSED:{
		
			break;
		}
		}

		Mcontroller->eventHandler(event);
		interface->update();
		window->clear();
		game->draw();
		interface->draw();
		window->display();

		event.key.code = Keyboard::Unknown;
	}
}

void game_t::keyController(sf::Event &event) {
	if (level->mainHero->get()->getAlive()) {
		KBcontroller->eventHandler(event);
	}
}
