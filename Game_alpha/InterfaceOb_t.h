#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "settings.h"

const sf::Vector2f STD_BORDERS_SIZE(10.f,10.f);

class InterfaceOb_t
{
protected:
	bool display;
	bool clickable;

	sf::Vector2f coords;
	sf::Vector2f sizes;
	sf::RenderWindow *window;
	sf::Vector2f borders;

	sf::Font font;
	sf::Text text;
	std::string title;

	sf::RectangleShape rectangle;

	sf::Int32 startTime;
	sf::Int32 displayDuration;

public:
	InterfaceOb_t(sf::RenderWindow *_window, sf::Vector2f _coords = sf::Vector2f(100.f,100.f), sf::Vector2f _sizes = sf::Vector2f(100.f,100.f));
	virtual ~InterfaceOb_t();

	virtual void draw();
	bool toggleDisplay();

	//GET
	sf::Vector2f getCoords() const {
		return coords;
	}

	sf::Vector2f getSizes() const {
		return sizes;
	}

	bool getClickable() const {
		return clickable;
	}
	bool getDisplayState() const {
		return display;
	}

	sf::RenderWindow *getWindowPtr()const {
		return window;
	}

	sf::Vector2f getBorders() const {
		return borders;
	}


	//SET
	void setCoords(sf::Vector2f &newCoords) {
		coords = newCoords;
	}

	void setSizes(sf::Vector2f &newSizes) {
		sizes = newSizes;
	}

	void setClickble(bool newState) {
		clickable = newState;
	}

	void setDisplay(bool newState) {
		display = newState;
	}

	void setTitle(std::string newTitle) {
		title = newTitle;
		text.setString(title);
	}
	void setTextFontSize(unsigned int size) {
		text.setCharacterSize(size);
	}

	void setFont(std::string _path) {
		font.loadFromFile(_path);
	}
};

