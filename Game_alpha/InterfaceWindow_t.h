#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "additional.h"
#include "InterfaceContent.h"

typedef std::unique_ptr<InterfaceContent> content;

class InterfaceWindow_t
{
protected:
	bool display;
	bool clickable;

	sf::Vector2f pos;
	sf::Vector2f sizes;
	sf::RenderWindow *window;

	sf::Font font;
	sf::Text text;
	std::string title;
	sf::Vector2f textRelativePos;

	sf::RectangleShape rectangle;

	sf::Vector2f borders;
	sf::RectangleShape outerBorderRect;

	sf::Int32 startTime;
	sf::Int32 displayDuration;

	public:
	std::list<content> contentList;

	InterfaceWindow_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes);
	virtual ~InterfaceWindow_t();

	virtual void draw();
	bool toggleDisplay();

	virtual void update();
	virtual void toDefaultPosition();

	//GET
	sf::Vector2f getPos() const {
		return pos;
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
	void setPos(sf::Vector2f &newpos) {
		pos = newpos;
		rectangle.setPosition(pos);
	}

	void setSizes(sf::Vector2f &newSizes) {
		sizes = newSizes;
		rectangle.setSize(sizes);
	}

	void setBgColor(sf::Color newColor) {
		rectangle.setFillColor(newColor);
	}

	void setClickble(bool newState) {
		clickable = newState;
	}

	void setBorderColor(sf::Color newColor) {
		outerBorderRect.setFillColor(newColor);
	}

	void setDisplay(bool newState) {
		display = newState;
	}

	void setTitle(std::string newTitle) {
		title = newTitle;
		text.setString(title);
	}

	void setTitlePos(sf::Vector2f _newpos) {
		textRelativePos = _newpos;
	}
	void setTextFontSize(unsigned int size) {
		text.setCharacterSize(size);
	}

	void setFont(std::string _path) {
		font.loadFromFile(_path);
	}
	
	void setTextColor(sf::Color newColor) {
		text.setFillColor(newColor);
	}


};

