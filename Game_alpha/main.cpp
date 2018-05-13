//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "game_t.h"

using namespace sf;
const int windowWidth = 1024;const int windowHeight = 768;

//const int windowWidth = 1920;const int windowHeight = 1600;


int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));//, sf::Style::Fullscreen));
	


	while (window->isOpen()) {
		std::unique_ptr<game_t> GAME;
		std::unique_ptr<mainMenu_t> mainMenu;
		std::string levelName;
		size_t difficulty = 0;

		mainMenu.swap(std::unique_ptr<mainMenu_t>(new mainMenu_t(window.get(), levelName, difficulty)));
		mainMenu->makeMenu();
		mainMenu->action();
		do {
			if (GAME) {
				if (GAME->getStatus() == game::RESTART) {
					GAME->resetGame();
				}
			}
		GAME.swap(std::unique_ptr<game_t>(new game_t(window.get(), levelName, difficulty)));
		GAME->start();
		} while (GAME->getStatus() == game::RESTART);
		mainMenu.get_deleter();
		mainMenu.reset();
	}
	
	return 0;
}