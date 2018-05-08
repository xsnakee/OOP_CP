#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "game_t.h"
#include "mainMenu_t.h"

using namespace sf;

const int windowWidth = 1024;
const int windowHeight = 768;


int main() {

	std::unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(windowWidth, windowHeight), "SFML GAME ALPHA"));// , sf::Style::Fullscreen));

	size_t difficulity = mainMenu(window.get());

	//game_t GAME(window.get());
	//GAME.start("level0");

	return 0;
}