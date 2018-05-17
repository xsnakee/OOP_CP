#include "InterfaceContent.h"


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

//GET
	sf::Vector2u InterfaceContent::getSize() const {
		return sizes;
	}
	sf::Vector2f InterfaceContent::getRelPos()const {
		return relativePos;
	}
	unsigned int InterfaceContent::getFontSize() const {
		return fontSize;
	}
	//SET
	void InterfaceContent::setRelativePos(sf::Vector2f newCoords) {
		relativePos = newCoords;
	}

	void InterfaceContent::setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
	}

	void InterfaceContent::setFont(sf::Font newFont) {
		font = newFont;
	}

	void InterfaceContent::setFontSize(unsigned int newSize){
		fontSize = newSize;
	}

	void InterfaceContent::setFontColor(sf::Color newColor) {
		textColor = newColor;
	}

	void InterfaceContent::setFontStyle(sf::Text::Style newStyle) {
		textStyle = newStyle;
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
	texture.get_deleter();
	texture.reset();
	texture.swap(std::unique_ptr<sf::Texture>(newTexture));
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
	texture.get_deleter();
}

//GET
	sf::Sprite InterfaceSpriteContent_t::getSprite() const {
		return sprite;
	}


//SET

	void InterfaceSpriteContent_t::setSize(sf::Vector2u newSizes) {
		sizes = newSizes;
		sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));
	}



//TEXT CONTENT
InterfaceTextContent_t::InterfaceTextContent_t(sf::RenderWindow *_window, std::string _str, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos):
InterfaceContent(_window, _defaultCoords, _relativePos)
{
	str = _str;	
	text.swap(std::unique_ptr<sf::Text>(new sf::Text(_str, font, fontSize)));
	text->setFillColor(textColor);
	text->setStyle(textStyle);
}

InterfaceTextContent_t::~InterfaceTextContent_t() {

}

sf::Text InterfaceTextContent_t::getText() {
	return *text.get();
}

void InterfaceTextContent_t::setText(sf::Text *_newText) {
	text.get_deleter();
	text.swap(std::unique_ptr<sf::Text>(_newText));
	str = _newText->getString();
}

void InterfaceTextContent_t::swapContent(std::string _newPath) {
	font.loadFromFile(textSettings::STRIKE_THROUGHT_FONT_FILE);
	text->setFont(font);
	text->setCharacterSize(fontSize);
	setFontColor(textColor);
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
	text.get_deleter();
}

void InterfaceTextContent_t::setText(std::string newStr) {
	str = newStr;
}

void InterfaceTextContent_t::setFontSize(unsigned int newSize) {
	fontSize = newSize;
	text->setCharacterSize(fontSize);
}