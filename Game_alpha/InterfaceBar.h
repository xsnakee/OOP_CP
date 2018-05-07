#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "character_t.h"
#include "additional.h"

class InterfaceBar
{
protected:
	sf::RenderWindow *window;
	sf::Vector2f borders;

	std::unique_ptr<sf::RectangleShape> outerRect;
	std::unique_ptr<sf::RectangleShape> innerRect;

	sf::Vector2f outerRectSize;	
	sf::Vector2f innerRectSize;

	sf::Vector2f posCoords;

	sf::Color outerColor;
	sf::Color innerColor;


	bool display;

	void updateInnerRectPos();
public:
	InterfaceBar(sf::RenderWindow *_window);
	virtual ~InterfaceBar();

	virtual void draw();
	virtual void update();

	virtual void toDefaultPosition();

	//GET
	sf::Vector2f getOuterRectSize() const {
		return outerRectSize;
	}
	sf::Vector2f getInnerRectSize() const {
		return innerRectSize;
	}

	sf::Vector2f getPosCoords() const{
		return posCoords;
	}
	sf::Color getOuterColor() const{
		return outerColor;
	}
	sf::Color getInnerColor() const{
		return innerColor;
	}

	bool getDisplay() const {
		return display;
	}
	//SET
	void setOuterRectSize(sf::Vector2f newSize) {
		outerRect->setSize(newSize);
	}

	void setInnerRectSize(sf::Vector2f newSize) {
		innerRect->setSize(newSize);
	}


	void setPosCoords(sf::Vector2f newCoords) {
		posCoords = newCoords;
		outerRect->setPosition(posCoords);
		sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));
		innerRect->setPosition(innerRectPos);

	}

	void setOuterRectColor(sf::Color newColor) {
		outerColor = newColor;
		outerRect->setFillColor(outerColor);
	}
	void setInnerRectColor(sf::Color newColor) {
		innerColor = newColor;
		innerRect->setFillColor(innerColor);
	}
	void setBorders(sf::Vector2f newBorders) {
		borders = newBorders;
	}
};

class progressBar : public InterfaceBar {
protected:
	sf::Vector2f relativeCoords;
	float &curValue;
	float &maxValue;
public:
	progressBar(sf::RenderWindow *_window, sf::Vector2f _relativeCoords,float &_curVal, float &_maxValue);
	virtual ~progressBar();

	virtual void update();

	virtual void toDefaultPosition();
	//GET
};


class LifeBar : public InterfaceBar {
protected:
	character_t *character;
public:
	LifeBar(sf::RenderWindow *_window, character_t *character);
	virtual ~LifeBar();

	virtual void update();

	virtual void toDefaultPosition();
	//GET
};


class castTimeBar : public LifeBar {

public:
	castTimeBar(sf::RenderWindow *_window, character_t *character);
	virtual ~castTimeBar();

	virtual void update();

	virtual void toDefaultPosition();
};