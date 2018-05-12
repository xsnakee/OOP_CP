#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "game_t.h"

using namespace sf;

const int windowWidth = 1024;
const int windowHeight = 768;


int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	//std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));// , sf::Style::Fullscreen));
	RenderWindow *window = new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA");
	std::unique_ptr<game_t> GAME;
	std::string levelName;
	size_t difficulty = 0;

	std::unique_ptr<mainMenu_t> mainMenu;
	do {
		mainMenu = std::move(std::unique_ptr<mainMenu_t>(new mainMenu_t(window, levelName, difficulty)));
		mainMenu->makeMenu();
		mainMenu->action();
		do {
		GAME = std::unique_ptr<game_t>(new game_t(window, levelName, difficulty));
		GAME->start();	

		} while (GAME->getStatus() == game::RESTART);
		mainMenu.reset();
	} while (GAME->getStatus() == game::MAIN_MENU);
	delete window;
	return 0;
}