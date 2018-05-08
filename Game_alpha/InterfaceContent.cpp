#include "InterfaceContent.h"



InterfaceContent::InterfaceContent(sf::RenderWindow *_window, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos):
	defaultCoords(_defaultCoords)
{
	window = _window;
	relativePos = _relativePos;
}


InterfaceContent::~InterfaceContent()
{
}

//SPRITE OB
InterfaceSpriteOb_t::InterfaceSpriteOb_t(sf::RenderWindow *_window, sf::Texture *_texture, sf::Vector2f _defaultCoords, sf::Vector2f _relativePos):
	InterfaceContent(_window,_defaultCoords, _relativePos)
{
	setTexture(_texture);
	sizes = texture->getSize();
	sprite.setPosition(defaultCoords + relativePos);
}

InterfaceSpriteOb_t::~InterfaceSpriteOb_t() {

}

void InterfaceSpriteOb_t::setTexture(sf::Texture *newTexture) {
	texture.reset();
	texture = std::move(std::unique_ptr<sf::Texture>(newTexture));
	sprite.setTexture(*texture);
	sizes = texture->getSize();
	sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));
}

void InterfaceSpriteOb_t::swapContent(std::string _newPath) {
	sf::Texture *newTempTexture = new sf::Texture;
	newTempTexture->loadFromFile(_newPath);

	setTexture(newTempTexture);
}

void InterfaceSpriteOb_t::update() {
	toDefaultPosition();
}

void InterfaceSpriteOb_t::draw() {
	window->draw(getSprite());
}

void InterfaceSpriteOb_t::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	sprite.setPosition(tempPos + defaultCoords + relativePos);
}