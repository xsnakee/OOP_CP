#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "additional.h"

class InterfaceContent
{
protected:
	sf::RenderWindow *window;
	sf::Vector2f defaultCoords;
	sf::Vector2f relativePos;
	sf::Vector2u sizes;

	sf::Font font;
	unsigned int fontSize;
	sf::Color textColor;
	sf::Text::Style textStyle;
	

public:
	InterfaceContent(sf::RenderWindow *_window, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos = sf::Vector2f(0.f,0.f));
	virtual ~InterfaceContent();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void toDefaultPosition() = 0;
	virtual void swapContent(std::string _newPath = "") = 0;
	virtual void resetContent() = 0;
	virtual void setTexture(sf::Texture *newTexture);
	virtual void setText(std::string newStr);
	//GET
	sf::Vector2u getSize() const {
		return sizes;
	}
	sf::Vector2f getRelPos()const {
		return relativePos;
	}
	unsigned int getFontSize() const {
		return fontSize;
	}
	//SET
	void setRelativePos(sf::Vector2f newCoords) {
		relativePos = newCoords;
	}

	virtual void setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
	}

	void setFont(sf::Font newFont) {
		font = newFont;
	}

	virtual void setFontSize(unsigned int newSize){
		fontSize = newSize;
	}

	void setFontColor(sf::Color newColor) {
		textColor = newColor;
	}

	void setFontStyle(sf::Text::Style newStyle) {
		textStyle = newStyle;
	}
};

//SPRITE CONTENT
class InterfaceSpriteContent_t : public InterfaceContent {
public:
	std::unique_ptr<sf::Texture> texture;
	sf::Sprite sprite;
public:
	InterfaceSpriteContent_t(sf::RenderWindow *_window, sf::Texture *_texture, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos = sf::Vector2f(0.f, 0.f));
	virtual ~InterfaceSpriteContent_t();

	virtual void update();
	virtual void draw();
	virtual void toDefaultPosition();

	virtual void swapContent(std::string _newPath = "");
	virtual void resetContent();

	//GET
	sf::Sprite getSprite() const {
		return sprite;
	}


	//SET
	void setTexture(sf::Texture *newTexture);

	virtual void setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
		sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));
	}
};


//TEXT CONTENT


class InterfaceTextContent_t : public InterfaceContent {
public:
	std::string str;
	std::unique_ptr<sf::Text> text;


	void setText(sf::Text *_newText);
	sf::Text getText();
public:
	InterfaceTextContent_t(sf::RenderWindow *_window, std::string _str, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos = sf::Vector2f(0.f, 0.f));
	virtual ~InterfaceTextContent_t();

	void setText(std::string newStr);
	virtual void update();
	virtual void draw();
	virtual void toDefaultPosition();
	virtual void setFontSize(unsigned int newSize);

	virtual void swapContent(std::string _str = "");
	virtual void resetContent();


};