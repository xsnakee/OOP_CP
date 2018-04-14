#include "cursor_t.h"

cursor_t::cursor_t() {

}

cursor_t::cursor_t(std::string fileName, int _height, int _width)
{
	height = _height;
	width = _width;

	texture.loadFromFile("img/cursor_aim.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}


cursor_t::~cursor_t()
{
}



void cursor_t::setCursorPosition(sf::RenderWindow *_window) {

	sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(*_window)));
}
