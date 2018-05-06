#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "InterfaceOb_t.h"

const sf::Vector2f STD_BUTTON_SIZE(50.f, 50.f);

class InterfaceButton : public InterfaceOb_t
{
protected:
	InterfaceOb_t *linkedOb;
	

public:
	InterfaceButton(InterfaceOb_t *_linkedOb);
	virtual ~InterfaceButton();

	virtual bool action() = 0;
};


class IntefaceButtonClose : public InterfaceButton {

public:
	IntefaceButtonClose(InterfaceOb_t *_linkedOb);
	~IntefaceButtonClose();
	virtual bool action();
};