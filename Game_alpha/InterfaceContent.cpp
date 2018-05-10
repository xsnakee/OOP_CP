#include "InterfaceContent.h"
#include <iostream>


InterfaceContent::InterfaceContent(sf::RenderWindow *_window, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos)
{
	window = _window;
	defaultCoords = _defaultCoords;
	relativePos = _relativePos;
	font.loadFromFile(textSettings::STD_FONT_FILE);
	fontSize = textSettings::STD_FONT_SIZE;
	textColor = textSettings::STD_TEXT_COLOR;
	textStyle = textSettings::STD_TEXT_STYLE;
}


InterfaceContent::~InterfaceContent()
{
}


void InterfaceContent::setTexture(sf::Texture *newTexture){
}
void InterfaceContent::setText(std::string newStr) {

}
//SPRITE CONTENT
InterfaceSpriteContent_t::InterfaceSpriteContent_t(sf::RenderWindow *_window, sf::Texture *_texture, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos):
	InterfaceContent(_window,_defaultCoords, _relativePos)
{
	setTexture(_texture);
	sizes = texture->getSize();
	sprite.setPosition(defaultCoords + relativePos);
}

InterfaceSpriteContent_t::~InterfaceSpriteContent_t() {

}

void InterfaceSpriteContent_t::setTexture(sf::Texture *newTexture) {
	texture.reset();
	texture = std::move(std::unique_ptr<sf::Texture>(newTexture));
	sprite.setTexture(*texture);
	sizes = texture->getSize();
	sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));
}

void InterfaceSpriteContent_t::swapContent(std::string _newPath) {
	sf::Texture *newTempTexture = new sf::Texture;
	newTempTexture->loadFromFile(_newPath);

	setTexture(newTempTexture);
}

void InterfaceSpriteContent_t::update() {
	toDefaultPosition();
}

void InterfaceSpriteContent_t::draw() {
	window->draw(getSprite());
}

void InterfaceSpriteContent_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	sprite.setPosition(tempPos + defaultCoords + relativePos);
}


void InterfaceSpriteContent_t::resetContent() {
	texture.reset();
}



//TEXT CONTENT
InterfaceTextContent_t::InterfaceTextContent_t(sf::RenderWindow *_window, std::string _str, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos):
InterfaceContent(_window, _defaultCoords, _relativePos)
{
	str = _str;	
	text = std::unique_ptr<sf::Text>(new sf::Text(_str, font, fontSize));
	text->setFillColor(textColor);
	text->setStyle(textStyle);
}

InterfaceTextContent_t::~InterfaceTextContent_t() {

}

sf::Text InterfaceTextContent_t::getText() {
	return *text.get();
}

void InterfaceTextContent_t::setText(sf::Text *_newText) {
	text.reset();
	text = std::move(std::unique_ptr<sf::Text>(_newText));
	str = _newText->getString();
}

void InterfaceTextContent_t::swapContent(std::string _newPath) {
	font.loadFromFile(textSettings::STRIKE_THROUGHT_FONT_FILE);
	text->setFont(font);
	setFontColor(sf::Color::White);
}
void InterfaceTextContent_t::update() {
	toDefaultPosition();
	text->setFillColor(textColor);
	text->setFont(font);
	text->setString(str);
}

void InterfaceTextContent_t::draw() {
	window->draw(getText());
}

void InterfaceTextContent_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	text->setPosition(tempPos + defaultCoords + relativePos);
}


void InterfaceTextContent_t::resetContent() {
	text.reset();
}

void InterfaceTextContent_t::setText(std::string newStr) {
	str = newStr;
}