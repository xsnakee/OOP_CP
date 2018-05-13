#include "InterfaceBar.h"
#include <iostream>


InterfaceBar::InterfaceBar(sf::RenderWindow *_window)
{
	window = _window;
	display = true;

	borders = interface::STD_BORDER_SIZE;



	outerRectSize = sf::Vector2f(interface::STD_BAR_SIZE);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize)));
	innerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize)));

	posCoords = sf::Vector2f(0.f, 0.f);
	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Black;
	innerColor = sf::Color::Red;

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}


InterfaceBar::~InterfaceBar()
{
}


void InterfaceBar::updateInnerRectPos() {
	innerRect->setPosition(sf::Vector2f((posCoords.x + borders.x), (posCoords.y + borders.y)));
}

void InterfaceBar::draw() {
	window->draw(*outerRect.get());
	window->draw(*innerRect.get());
}

void InterfaceBar::update() {
	outerRect->setPosition(posCoords);
	updateInnerRectPos();
}

void InterfaceBar::toDefaultPosition(){
	outerRect->setPosition(posCoords);
	updateInnerRectPos();
}
//PROGRESS BAR
progressBar::progressBar(sf::RenderWindow *_window, sf::Vector2f _relativeCoords, float &_curVal, float &_maxValue) : InterfaceBar(_window), curValue(_curVal), maxValue(_maxValue)
{
	borders = interface::STD_BORDER_SIZE;
	relativePos = _relativeCoords;

	outerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize)));
	innerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize)));

	toDefaultPosition();
	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Color(0, 0, 0, 190);
	innerColor = sf::Color::Color(255, 0, 0, 255);

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}
progressBar::~progressBar() {

}

void progressBar::update() {

	toDefaultPosition();

	float k = curValue / maxValue;
	if (k < 0) {
		k = 0;
	}

	sf::Vector2f tempInnerRectSize(innerRectSize.x * k, innerRectSize.y);

	setInnerRectSize(tempInnerRectSize);
}

void progressBar::toDefaultPosition() {
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	tempPos += relativePos;

	setPosCoords(tempPos);
}


//LIFE BAR
LifeBar::LifeBar(sf::RenderWindow *_window, character_t *_character) :InterfaceBar(_window)
{
	character = _character;

	borders = interface::STD_BORDER_SIZE;
	float barSizeDiv = 8.f;

	outerRectSize = sf::Vector2f(character->getWidth() + borders.x, interface::STD_HP_BAR_HEIGHT.y);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize)));
	innerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize)));


	toDefaultPosition();

	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Color(0, 0, 0, 190);
	innerColor = sf::Color::Color(255,0,0,255);

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}

LifeBar::~LifeBar()
{
}

void LifeBar::update() {
	if (character->getAlive()) {

		toDefaultPosition();

		float k = character->getStats().HP / character->getStats().stdHP;

		sf::Vector2f tempInnerRectSize(innerRectSize.x * k, innerRectSize.y);

		setInnerRectSize(tempInnerRectSize);
	}
	else {
		display = false;
	}

}

void LifeBar::toDefaultPosition() {
	sf::Vector2f tempPos(character->getPosX() - borders.x, character->getPosY() - borders.y * 5.f);
	setPosCoords(tempPos);
}

//CAST BAR
castTimeBar::castTimeBar(sf::RenderWindow *_window, character_t *_character) :LifeBar(_window, _character)
{
	character = _character;

	borders = interface::STD_BORDER_SIZE;
	float barSizeDiv = 7.f;

	outerRectSize = sf::Vector2f(interface::STD_BAR_SIZE.x/2, interface::STD_BAR_SIZE.y);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize)));
	innerRect.swap(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize)));
	
	toDefaultPosition();
	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));
	

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Color(0, 0, 0, 100);
	innerColor = sf::Color::Color(1,255,4,255);

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}


castTimeBar::~castTimeBar()
{
}

void castTimeBar::update() {
	if (character->getAlive()) {
		toDefaultPosition();
		if (character->getState()->getStateNum() == 4) {

			int delay = character->getTimer().getCastDelay();;
			
			float k = (static_cast<float>(character->getTimer().getClockPtr()->getElapsedTime().asMilliseconds()) -
				static_cast<float>(character->getTimer().getCastStartTime())) / static_cast<float>(delay);

			sf::Vector2f tempInnerRectSize(innerRectSize.x * k, innerRectSize.y);
			setInnerRectSize(tempInnerRectSize);
		}
		else {
			sf::Vector2f tempInnerRectSize(0.f, 0.f);
			setInnerRectSize(tempInnerRectSize);

		}

	}
	else {
		display = false;
	}

}

void castTimeBar::toDefaultPosition() {
	sf::View view = window->getView();

	sf::Vector2f tempPos(view.getCenter().x - outerRectSize.x/2 + interface::STD_BORDER_SIZE.x, view.getCenter().y + window->getSize().y / 2 - outerRectSize.y*2 - interface::STD_BORDER_SIZE.y);
	setPosCoords(tempPos);
}