#include "InterfaceButton.h"



InterfaceButton::InterfaceButton(InterfaceWindow_t *_linkedOb, sf::Vector2f _pos):InterfaceWindow_t(_linkedOb->getWindowPtr(), _pos, STD_BUTTON_SIZE)
{
	linkedOb = _linkedOb;
	display = linkedOb->getDisplayState();
	clickable = true;
	borders =sf::Vector2f(2.f, 2.f);
	pos = sf::Vector2f((linkedOb->getPos().x + linkedOb->getSizes().x - linkedOb->getBorders().x - sizes.x),(linkedOb->getPos().y + linkedOb->getBorders().y));

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
IntefaceButtonClose::IntefaceButtonClose(InterfaceWindow_t *_linkedOb, sf::Vector2f _pos):InterfaceButton(_linkedOb, _pos)
{
	linkedOb = _linkedOb;
}


IntefaceButtonClose::~IntefaceButtonClose()
{
}

bool IntefaceButtonClose::action() {
	return linkedOb->toggleDisplay();
}