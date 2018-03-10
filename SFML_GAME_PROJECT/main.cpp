#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock clock;
	float speedMultiple = 800.f;

	Game game;

	while (window.isOpen())
	{

		//calc game Speed
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		float gameSpeed = time / speedMultiple;
		//std::cout << gameSpeed << std::endl;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed)||(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
				window.close();
		
			if (event.type == sf::Event::EventType::KeyPressed) {
				game.charList[0]->getKey(event);
			}	

		}

		game.charList[0]->update(gameSpeed);

		window.clear();
		
		for (size_t i = 0; i < game.charList.size(); ++i) {
			window.draw(game.charList[i]->sprite);
		}

		//window.draw(shape);
		window.display();
	}

	return 0;
}
