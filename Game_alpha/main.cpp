//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <cstdlib>
#include <memory>
#include "game_t.h"

using namespace sf;

const int windowWidth = 1600;const int windowHeight = 900;


int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));// , sf::Style::Fullscreen));
	


	while (window->isOpen()) {
		std::string levelName;
		size_t difficulty = 0;
		mainMenu_t mainMenu(window.get(), levelName, difficulty);
		mainMenu.makeMenu();
		mainMenu.action();
		game_t GAME(window.get(), levelName, difficulty);
		do {
		GAME.start();
		} while (GAME.getStatus() == game::RESTART);
	}
	
	return 0;
}