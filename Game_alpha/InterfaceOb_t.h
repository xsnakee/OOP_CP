#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "additional.h"

const sf::Vector2f STD_BORDERS_SIZE(10.f,10.f);

class InterfaceOb_t
{
protected:
	bool display;
	bool clickable;

	sf::Vector2f pos;
	sf::Vector2f sizes;
	sf::RenderWindow *window;
	sf::Vector2f borders;
	std::unique_ptr<sf::Texture> texture;

	sf::Font font;
	sf::Text text;
	std::string title;
	sf::Vector2f textRelativePos;

	sf::RectangleShape rectangle;

	sf::Int32 startTime;
	sf::Int32 displayDuration;

public:
	InterfaceOb_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes);
	virtual ~InterfaceOb_t();

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

	void setTitlePos(sf::Vector2f _newpos) {
		textRelativePos = _newpos;
	}
	void setTextFontSize(unsigned int size) {
		text.setCharacterSize(size);
	}

	void setFont(std::string _path) {
		font.loadFromFile(_path);
	}
	
	void setTexture(sf::Texture *newTexture) {
		texture = std::move(std::unique_ptr<sf::Texture>(newTexture));
		rectangle.setTexture(texture.get());
	}

};

