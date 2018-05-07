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

	std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));// , sf::Style::Fullscreen));

	game_t GAME(window.get());
	GAME.start();

	return 0;
}