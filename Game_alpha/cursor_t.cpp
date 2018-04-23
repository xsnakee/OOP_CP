#include "cursor_t.h"

cursor_t::cursor_t() {

}

cursor_t::cursor_t(std::string fileName, int _height, int _width, sf::RenderWindow *_window)
{
	height = _height;
	width = _width;
	window = _window;

	texture.loadFromFile("img/cursor_aim.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));
	sprite.setOrigin(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}


cursor_t::~cursor_t()
{
}



void cursor_t::setCursorPosition() {

	sf::Vector2i mousePos(sf::Mouse::getPosition(*window));
	sf::Vector2f globalPos = window->mapPixelToCoords(mousePos);

	sprite.setPosition(globalPos);
	
}
