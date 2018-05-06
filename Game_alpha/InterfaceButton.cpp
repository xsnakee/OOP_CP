#include "InterfaceButton.h"



InterfaceButton::InterfaceButton(InterfaceOb_t *_linkedOb):InterfaceOb_t(_linkedOb->getWindowPtr())
{
	linkedOb = _linkedOb;
	display = linkedOb->getDisplayState();
	clickable = true;
	sizes = STD_BUTTON_SIZE;
	borders =sf::Vector2f(2.f, 2.f);
	coords = sf::Vector2f((linkedOb->getCoords().x + linkedOb->getSizes().x - linkedOb->getBorders().x - sizes.x),(linkedOb->getCoords().y + linkedOb->getBorders().y));

	text.setCharacterSize(20);
	title = "X";
	text.setPosition(coords);

	rectangle.setSize(sizes);	
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(coords);
}


InterfaceButton::~InterfaceButton()
{
}



//CLOSE BUTTON CLASS
IntefaceButtonClose::IntefaceButtonClose(InterfaceOb_t *_linkedOb):InterfaceButton(_linkedOb)
{
	linkedOb = _linkedOb;
}


IntefaceButtonClose::~IntefaceButtonClose()
{
}

bool IntefaceButtonClose::action() {
	return linkedOb->toggleDisplay();
}