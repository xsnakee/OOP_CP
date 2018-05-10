#include "InterfaceWindow_t.h"

//INTERFACE OB

InterfaceWindow_t::InterfaceWindow_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes): rectangle(_sizes),borders(interface::STD_BORDER_SIZE)
{
	display = true;
	clickable = false;
	window = _window;
	pos = _pos;
	sizes = _sizes;

	rectangle.setSize(sizes);
	rectangle.setFillColor(sf::Color(0, 0, 0, 255));
	rectangle.setPosition(pos);


	outerBorderRect.setSize(sizes + borders*2.f);
	outerBorderRect.setFillColor(sf::Color::Color(238, 238, 238, 255));


	font.loadFromFile(textSettings::STD_FONT_FILE);
	text.setCharacterSize(textSettings::STD_FONT_SIZE);
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
		window->draw(outerBorderRect);
		window->draw(rectangle);
		window->draw(text);

		for (auto &i : contentList) {
			i->draw();
		}
	}
}

void InterfaceWindow_t::update() {
	toDefaultPosition();

	for (auto &i : contentList) {
		i->update();
	}
}

void InterfaceWindow_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	rectangle.setPosition(tempPos + pos);
	text.setPosition(tempPos + pos + textRelativePos);
	outerBorderRect.setPosition(tempPos + pos - borders);
}