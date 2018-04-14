#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>


class cursor_t
{
	sf::Texture texture;
	sf::Sprite sprite;
	int height;
	int width;

public:
	cursor_t();
	cursor_t(std::string fileName, int _height, int _width);
	~cursor_t();

	void setCursorPosition(sf::RenderWindow *_window);


	//GET


	sf::Sprite getSprite() const {
		return sprite;
	}
};

