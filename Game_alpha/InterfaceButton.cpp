#include "InterfaceButton.h"



InterfaceButton::InterfaceButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos):InterfaceWindow_t(_linkedOb.getWindowPtr(), _pos, STD_BUTTON_SIZE),
linkedOb(&_linkedOb)
{
	
	clickable = true;
	borders =sf::Vector2f(2.f, 2.f);
	pos = _pos;//sf::Vector2f((linkedOb->getPos().x + linkedOb->getSizes().x - linkedOb->getBorders().x - sizes.x),(linkedOb->getPos().y + linkedOb->getBorders().y));

	text.setCharacterSize(20);
	title = "X";
	text.setPosition(pos);

	rectangle.setSize(sizes);	
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(pos);
}


InterfaceButton::~InterfaceButton()
{
}



//CLOSE BUTTON CLASS
IntefaceToggleButton::IntefaceToggleButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos):InterfaceButton(_linkedOb, _pos)
{
	setBgColor(sf::Color::Transparent);
	setBorderColor(sf::Color::Transparent);
}


IntefaceToggleButton::~IntefaceToggleButton()
{
}

bool IntefaceToggleButton::action() {
	printf("1");
	return linkedOb->toggleDisplay();
}