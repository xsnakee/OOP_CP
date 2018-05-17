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

//GET
	sf::Vector2f InterfaceWindow_t::getPos() const {
		return pos;
	}

	sf::Vector2f InterfaceWindow_t::getSizes() const {
		return sizes;
	}

	sf::FloatRect InterfaceWindow_t::getFloatRect()const {
		return sf::FloatRect(pos,sizes);
	}

	sf::IntRect InterfaceWindow_t::getIntRect() const {
		return sf::IntRect(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(sizes.x), static_cast<int>(sizes.y));
	}
	bool InterfaceWindow_t::getClickable() const {
		return clickable;
	}
	bool InterfaceWindow_t::getDisplayState() const {
		return display;
	}

	sf::RenderWindow *InterfaceWindow_t::getWindowPtr()const {
		return window;
	}

	sf::Vector2f InterfaceWindow_t::getBorders() const {
		return borders;
	}


	//SET
	void InterfaceWindow_t::setPos(sf::Vector2f &newpos) {
		pos = newpos;
		rectangle.setPosition(pos);
	}

	void InterfaceWindow_t::setSizes(sf::Vector2f &newSizes) {
		sizes = newSizes;
		rectangle.setSize(sizes);
	}

	void InterfaceWindow_t::setBgColor(sf::Color newColor) {
		rectangle.setFillColor(newColor);
	}

	void InterfaceWindow_t::setClickble(bool newState) {
		clickable = newState;
	}

	void InterfaceWindow_t::setBorderColor(sf::Color newColor) {
		outerBorderRect.setFillColor(newColor);
	}

	void InterfaceWindow_t::setDisplay(bool newState) {
		display = newState;
	}

	void InterfaceWindow_t::setTitle(std::string newTitle) {
		title = newTitle;
		text.setString(title);
	}

	void InterfaceWindow_t::setTitlePos(sf::Vector2f _newpos) {
		textRelativePos = _newpos;
	}
	void InterfaceWindow_t::setTextFontSize(unsigned int size) {
		text.setCharacterSize(size);
	}

	void InterfaceWindow_t::setFont(std::string _path) {
		font.loadFromFile(_path);
	}
	
	void InterfaceWindow_t::setTextColor(sf::Color newColor) {
		text.setFillColor(newColor);
	}