#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "game_t.h"

using namespace sf;

const int windowWidth = 1024;
const int windowHeight = 768;

void START_GAME(sf::RenderWindow *window);
int main() {

	std::unique_ptr<RenderWindow> window (new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));

	START_GAME(window.get());


	return 0;
}




void START_GAME(sf::RenderWindow *window) {

	game_t game(window, "level0");

	Clock clock;

	while (window->isOpen()) {
		Event event;
		float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		game.setSpeed(timer);

		while (window->pollEvent(event)) {

			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) {
				window->close();
			}
		}

		game.keyController(event);

		game.update();
		window->clear();

		game.checkAlive();
		game.draw();

		window->display();
	}
}
