#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "Level_t.h"
#include "GameEngine_t.h"
#include "InterfaceEngine_t.h"

using namespace sf;

const int windowWidth = 1024;
const int windowHeight = 768;

void START_GAME(sf::RenderWindow *window);
int main() {

	std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));// , sf::Style::Fullscreen));

	START_GAME(window.get());


	return 0;
}




void START_GAME(sf::RenderWindow *window) {

	Level_t level("level0");

	GameEngine_t game(window, level);
	InterfaceEngine_t interface(window, level);

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
		interface.update();
		window->clear();
		game.draw();
		interface.draw();

		window->display();
	}
}
