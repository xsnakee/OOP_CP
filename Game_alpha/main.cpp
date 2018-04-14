#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "game_t.h"

using namespace sf;

const int windowWidth = 1024;
const int windowHeight = 768;


int main() {

	RenderWindow window(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA");

	game_t game("maps/test_map.txt", "img/maps/mapTilesCombine.png", 29, 14*3);
	
	Clock clock;

	while (window.isOpen()) {
		Event event;
		float timer = static_cast<sf::Int64>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		game.setSpeed(timer);

		while (window.pollEvent(event)) {

			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) {
				window.close();
			}
		}

		game.keyController(event);

		window.clear();

		game.checkAlive();
		game.update();
		game.draw(&window);

		window.display();
	}


	return 0;
}