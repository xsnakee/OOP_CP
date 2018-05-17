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
	std::vector<content> contentList;

	InterfaceWindow_t(sf::RenderWindow *_window, sf::Vector2f _pos, sf::Vector2f _sizes);
	virtual ~InterfaceWindow_t();

	virtual void draw();
	bool toggleDisplay();

	virtual void update();
	virtual void toDefaultPosition();

	//GET
	sf::Vector2f getPos() const;
	sf::Vector2f getSizes() const;
	sf::FloatRect getFloatRect()const;
	sf::IntRect getIntRect() const;
	bool getClickable() const;
	bool getDisplayState() const;
	sf::RenderWindow *getWindowPtr()const;
	sf::Vector2f getBorders() const;


	//SET
	void setPos(sf::Vector2f &newpos);
	void setSizes(sf::Vector2f &newSizes);
	void setBgColor(sf::Color newColor);
	void setClickble(bool newState);
	void setBorderColor(sf::Color newColor);
	void setDisplay(bool newState);
	void setTitle(std::string newTitle);
	void setTitlePos(sf::Vector2f _newpos);
	void setTextFontSize(unsigned int size);
	void setFont(std::string _path);
	void setTextColor(sf::Color newColor);

};

