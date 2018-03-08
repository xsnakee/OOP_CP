#include <SFML/Graphics.hpp>
#include "temp_classes\addons.hpp"
#include "temp_classes\char_t.hpp"
#include "temp_classes\game_t.hpp"
#include "temp_classes\physPref_t.hpp"
#include "temp_classes\playerInterface_t.hpp"
#include "temp_classes\skill_t.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
