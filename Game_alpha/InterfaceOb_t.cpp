#include "InterfaceOb_t.h"



InterfaceOb_t::InterfaceOb_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes): rectangle(_sizes),borders(STD_BORDERS_SIZE)
{
	display = true;
	clickable = false;
	window = _window;
	pos = _pos;
	sizes = _sizes;

	rectangle.setSize(sizes);
	rectangle.setFillColor(sf::Color(0, 0, 0, 255));
	rectangle.setPosition(pos);


	font.loadFromFile(textSettings::MAIN_FONT_FILE);
	text.setCharacterSize(12);
	text.setFont(font);

	text.setPosition(pos + textRelativePos);
	text.setString(title);
}


InterfaceOb_t::~InterfaceOb_t()
{
}



bool InterfaceOb_t::toggleDisplay() {
	display = display ? false : true;
	return display;
}

void InterfaceOb_t::draw() {
	if (display) {
		window->draw(rectangle);
		window->draw(text);
	}
}

void InterfaceOb_t::update() {
	toDefaultPosition();
}

void InterfaceOb_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window) + pos);
	rectangle.setPosition(tempPos);

	tempPos += textRelativePos;
	text.setPosition(tempPos);
}