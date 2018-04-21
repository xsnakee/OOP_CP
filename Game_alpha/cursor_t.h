#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>


class cursor_t
{
	sf::Texture texture;
	sf::Sprite sprite;
	int height;
	int width;

	sf::RenderWindow *window;
public:
	cursor_t();
	cursor_t(std::string fileName, int _height, int _width, sf::RenderWindow *_window);
	~cursor_t();

	void setCursorPosition();


	//GET


	sf::Sprite getSprite() const {
		return sprite;
	}

	sf::Vector2f getPosition() const {
		sf::Vector2i mousePos(sf::Mouse::getPosition(*window));
		sf::Vector2f globalPos = window->mapPixelToCoords(mousePos);
		return globalPos;
	}
};

