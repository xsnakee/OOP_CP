#include "game_t.h"



game_t::game_t(sf::RenderWindow *_window, std::string _levelName, size_t _difficulty)
{
	window = _window;
	levelName = _levelName;
	difficulty = _difficulty;
	status = game::MAIN_MENU;
}


game_t::~game_t()
{
	resetGame();
}


void game_t::start() {
			level.swap(std::unique_ptr<Level_t>(new Level_t(levelName)));
			if (!level->succesfull) {
				std::cout << "MAP_FILE_IS_NOT_OPEN";
				return;
			}
			gameEngine.swap(std::unique_ptr<GameEngine_t>(new GameEngine_t(window, *level.get(), difficulty)));
			interfaceEngine.swap(std::unique_ptr<InterfaceEngine_t>(new InterfaceEngine_t(window, *level.get())));
			KBcontroller.swap(std::unique_ptr<keyboardController>(new keyboardController(level->mainHero->get(), this)));
			Mcontroller.swap(std::unique_ptr<mouseController>(new mouseController(window, this, *interfaceEngine.get()->cursor)));

			play();
	
}

void game_t::play() {
	using namespace sf;

	Event event;

	status = game::PLAY;

	while (window->isOpen()) {

		float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
			
		}
		
		switch (status) {
		case game::status::PLAY: {
			gameEngine->setSpeed(timer);
			gameEngine->update();
			Mcontroller->eventHandler(event);
			status = gameEngine->getGameStatus();
			break;
		}

		case game::RESTART: {
			return;
		}
		case game::MAIN_MENU: {
			return;
		}
		case game::PAUSED: {
			Mcontroller->menuEventHandler(event);
			break;
		}
		case game::GAME_OVER: {
			interfaceEngine->pausedMenuIt->get()->contentList.back()->setFontColor(sf::Color::Red);
			interfaceEngine->pausedMenuIt->get()->contentList.back()->setText("YOU DIE");
			interfaceEngine->pausedMenuIt->get()->setDisplay(true);
			Mcontroller->menuEventHandler(event);
			break;
		}

		}

		keyController(event);
		interfaceEngine->update();
		window->clear();
		gameEngine->draw();
		interfaceEngine->draw();
		window->display();

		event.key.code = Keyboard::Unknown;
	}
}

void game_t::keyController(sf::Event &event) {
	if (level->mainHero->get()->getAlive()) {
		KBcontroller->eventHandler(event);
	}
}

game::status game_t::getStatus() const {
	return status;
}
void game_t::setGameStatus(game::status _newStatus) {
	status = _newStatus;
}

void game_t::resetGame() {
	clock.restart();
	KBcontroller.get_deleter();
	Mcontroller.get_deleter();
	gameEngine.get_deleter();
	interfaceEngine.get_deleter();
	level.get_deleter();
}
