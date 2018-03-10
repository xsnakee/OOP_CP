#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "game_t.h"

using namespace sf;


game_t game;

int main() {

	RenderWindow window(VideoMode(1024, 768), "SFML GAME ALPHA");
	
	while (window.isOpen()) {

		Event event;

		while (window.pollEvent(event)) {

			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) {
				window.close();
			}

		}

		window.clear();

		//game.draw(window);

		//*
		for (size_t i = 0; i < game.charactersList.size(); ++i) {
			window.draw(game.charactersList[i]->getSprite());
		}
		//*/
		window.display();
	}


	return 0;
}