#pragma once
#include <SFML/Graphics.hpp>

class InterfaceContent
{
	
public:
	InterfaceContent();
	virtual ~InterfaceContent();
	virtual void draw(sf::RenderWindow *window);
	virtual void setPref();
};

