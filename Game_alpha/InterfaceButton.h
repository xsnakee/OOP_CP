#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "InterfaceWindow_t.h"

const sf::Vector2f STD_BUTTON_SIZE(50.f, 50.f);

class InterfaceButton : public InterfaceWindow_t
{
protected:
	InterfaceWindow_t *linkedOb;
	

public:
	InterfaceButton(InterfaceWindow_t *_linkedOb, sf::Vector2f _pos);
	virtual ~InterfaceButton();

	virtual bool action() = 0;
};


class IntefaceButtonClose : public InterfaceButton {

public:
	IntefaceButtonClose(InterfaceWindow_t *_linkedOb, sf::Vector2f _pos);
	~IntefaceButtonClose();
	virtual bool action();
};