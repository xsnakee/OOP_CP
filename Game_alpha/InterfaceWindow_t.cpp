#include "InterfaceWindow_t.h"

//INTERFACE OB

InterfaceWindow_t::InterfaceWindow_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes): rectangle(_sizes),borders(STD_BORDERS_SIZE)
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


InterfaceWindow_t::~InterfaceWindow_t()
{
}



bool InterfaceWindow_t::toggleDisplay() {
	display = display ? false : true;
	return display;
}

void InterfaceWindow_t::draw() {
	if (display) {
		window->draw(rectangle);
		window->draw(text);
	}
}

void InterfaceWindow_t::update() {
	toDefaultPosition();
}

void InterfaceWindow_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	rectangle.setPosition(tempPos + pos);
	text.setPosition(tempPos + pos + textRelativePos);
}