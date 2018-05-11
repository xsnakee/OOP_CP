#include "game_t.h"



game_t::game_t(sf::RenderWindow *_window)
{
	window = _window;
	status = game::MAIN_MENU;
}


game_t::~game_t()
{
}


void game_t::start() {
	while (status == game::MAIN_MENU) {
		mainMenu = std::unique_ptr<mainMenu_t>(new mainMenu_t(window, levelName, difficulty));
		mainMenu->action();


		status = game::PLAY;

		while (status != game::MAIN_MENU) {
			level = std::unique_ptr<Level_t>(new Level_t(levelName));
			if (!level->succesfull) {
				std::cout << "MAP_FILE_IS_NOT_OPEN";
				return;
			}
			play();
			resetGame();
		}
	}
	
}

void game_t::play() {
	using namespace sf;

	status = game::PLAY;
	gameEngine = std::unique_ptr<GameEngine_t>(new GameEngine_t(window, *level.get(), difficulty));
	interfaceEngine = std::unique_ptr<InterfaceEngine_t>(new InterfaceEngine_t(window, *level.get()));
	KBcontroller = std::move(std::unique_ptr<keyboardController>(new keyboardController(level->mainHero->get(), *this)));
	Mcontroller = std::move(std::unique_ptr<mouseController>(new mouseController(window, *this, *interfaceEngine.get()->cursor)));

	Event event;

	while (window->isOpen()) {

		float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();

		game::status gameStatus = gameEngine->getGameStatus();
		bool playContinue = (gameStatus == game::GAME_OVER || gameStatus == game::WIN) ? false : true;
		status =  playContinue ? status : gameStatus;

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
			break;
		}

		case game::status::PAUSED:{
			Mcontroller->menuEventHandler(event);
			break;
		}
		case game::RESTART:case game::MAIN_MENU: {
			return;
		}
		case game::GAME_OVER: {
			Mcontroller->menuEventHandler(event);
			interfaceEngine->pausedMenuIt->get()->contentList.back()->setFontColor(sf::Color::Red);
			interfaceEngine->pausedMenuIt->get()->contentList.back()->setText("YOU DIE");
			interfaceEngine->pausedMenuIt->get()->setDisplay(true);
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
	mainMenu.reset();
	gameEngine.reset();
	level.reset();
	interfaceEngine.reset();
	KBcontroller.reset();
	Mcontroller.reset();
	clock.restart();
}