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
	sf::Vector2f getOuterRectSize() const;
	sf::Vector2f getInnerRectSize() const;
	sf::Vector2f getPosCoords() const;
	sf::Color getOuterColor() const;
	sf::Color getInnerColor() const;
	bool getDisplay() const ;
	//SET
	void setOuterRectSize(sf::Vector2f newSize);

	void setInnerRectSize(sf::Vector2f newSize);
	void setPosCoords(sf::Vector2f newCoords);
	void setOuterRectColor(sf::Color newColor);
	void setInnerRectColor(sf::Color newColor);
	void setBorders(sf::Vector2f newBorders);
	void serRelativeCoords(sf::Vector2f newCoords);
};

class progressBar : public InterfaceBar {
protected:
	sf::Vector2f relativePos;
	float &curValue;
	float &maxValue;
public:
	progressBar(sf::RenderWindow *_window, sf::Vector2f _relativeCoords,float &_curVal, float &_maxValue);
	virtual ~progressBar();

	virtual void update();

	virtual void toDefaultPosition();
	void setRelativePos(sf::Vector2f newCoords);
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