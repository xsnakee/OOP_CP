#include "InterfaceOb_t.h"



InterfaceOb_t::InterfaceOb_t(sf::RenderWindow *_window, sf::Vector2f _coords, sf::Vector2f _sizes): rectangle(_sizes),borders(STD_BORDERS_SIZE)
{
	display = true;
	clickable = false;
	window = _window;
	coords = _coords;
	sizes = _sizes;

	font.loadFromFile(textSettings::MAIN_FONT_FILE);
	text.setCharacterSize(20);
	text.setFont(font);

	text.setPosition(coords.x + borders.x, coords.y + borders.y);
	text.setString(title);

	rectangle.setFillColor(sf::Color(0, 0, 0, 255));
	rectangle.setPosition(coords);
}


InterfaceOb_t::~InterfaceOb_t()
{
}



bool InterfaceOb_t::toggleDisplay() {
	display = display ? false : true;
	return display;
}

void InterfaceOb_t::draw() {
	window->draw(rectangle);
	window->draw(text);
}