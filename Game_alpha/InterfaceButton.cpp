#include "InterfaceButton.h"



InterfaceButton::InterfaceButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos):InterfaceWindow_t(_linkedOb.getWindowPtr(), _pos, STD_BUTTON_SIZE),
linkedOb(&_linkedOb)
{
	
	clickable = true;
	borders =sf::Vector2f(2.f, 2.f);
	pos = _pos;

	text.setCharacterSize(20);
	title = "X";
	text.setPosition(pos);

	rectangle.setSize(sizes);	
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(pos);
	tracking = false;
}


InterfaceButton::~InterfaceButton()
{
}


bool InterfaceButton::trackDisplay() {
	display = linkedOb->getDisplayState();
	return display;
}

void InterfaceButton::update() {
	InterfaceWindow_t::update();
	if (tracking) {
		trackDisplay();
	}
}

//TOGGLE BUTTON CLASS
IntefaceToggleButton::IntefaceToggleButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos):InterfaceButton(_linkedOb, _pos)
{
	setBgColor(sf::Color::Transparent);
	setBorderColor(sf::Color::Transparent);
}


IntefaceToggleButton::~IntefaceToggleButton()
{
}

bool IntefaceToggleButton::action() {
	return linkedOb->toggleDisplay();
}

//RESTART BUTTON CLASS
InterfaceRestartButton::InterfaceRestartButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos) :InterfaceButton(_linkedOb, _pos)
{
	tracking = true;
	setBgColor(sf::Color::Transparent);
	setBorderColor(sf::Color::Transparent);
	//setBgColor(sf::Color::Blue);
}


InterfaceRestartButton::~InterfaceRestartButton()
{
}

bool InterfaceRestartButton::action() {
	return true;
}

//EXIT BUTTON CLASS
IntefaceExitButton::IntefaceExitButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos):InterfaceButton(_linkedOb, _pos)
{
	tracking = true;
	setBgColor(sf::Color::Transparent);
	setBorderColor(sf::Color::Transparent);
}


IntefaceExitButton::~IntefaceExitButton()
{
}

bool IntefaceExitButton::action() {
	return true;
}

