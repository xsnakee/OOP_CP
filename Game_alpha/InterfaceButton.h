#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "InterfaceWindow_t.h"

const sf::Vector2f STD_BUTTON_SIZE(50.f, 50.f);

class InterfaceButton : public InterfaceWindow_t
{
protected:
	InterfaceWindow_t *linkedOb;
	bool tracking;

public:
	InterfaceButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos);
	virtual ~InterfaceButton();

	virtual void update();
	virtual bool action() = 0;
	bool trackDisplay();
};


class IntefaceToggleButton : public InterfaceButton {

public:
	IntefaceToggleButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos);
	~IntefaceToggleButton();
	virtual bool action();
};

class InterfaceRestartButton : public InterfaceButton {

public:
	InterfaceRestartButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos);
	~InterfaceRestartButton();
	virtual bool action();
};

class IntefaceExitButton : public InterfaceButton {

public:
	IntefaceExitButton(InterfaceWindow_t &_linkedOb, sf::Vector2f _pos);
	~IntefaceExitButton();
	virtual bool action();
};

