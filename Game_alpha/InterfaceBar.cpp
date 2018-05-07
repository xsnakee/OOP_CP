#include "InterfaceBar.h"
#include <iostream>


InterfaceBar::InterfaceBar(sf::RenderWindow *_window)
{
	window = _window;
	display = true;

	borders = interface::STD_BORDER_SIZE;

	outerRectSize = sf::Vector2f(100.f, 100.f);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize));
	innerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize));

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

//LIFE BAR
LifeBar::LifeBar(sf::RenderWindow *_window, character_t *_character) :InterfaceBar(_window)
{
	character = _character;

	borders = interface::STD_BORDER_SIZE;
	float barSizeDiv = 8.f;

	outerRectSize = sf::Vector2f(character->getWidth() + borders.x, character->getHeight() / barSizeDiv + borders.y);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize));
	innerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize));

	sf::Vector2f tempPos(character->getPosX() - borders.x, character->getPosY() - borders.y);
	posCoords = tempPos;
	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Black;
	innerColor = sf::Color::Red;

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}


LifeBar::~LifeBar()
{
}
void LifeBar::draw() {
	window->draw(*outerRect.get());
	window->draw(*innerRect.get());
}

void LifeBar::update() {
	if (character->getAlive()) {
		sf::Vector2f tempPos(character->getPosX() - borders.x, character->getPosY() - borders.y * 5.f);
		setPosCoords(tempPos);

		float k = character->getStats().HP / character->getStats().stdHP;

		sf::Vector2f tempInnerRectSize(innerRectSize.x * k, innerRectSize.y);

		setInnerRectSize(tempInnerRectSize);
	}
	else {
		display = false;
	}

}

//CAST BAR
castTimeBar::castTimeBar(sf::RenderWindow *_window, character_t *_character) :InterfaceBar(_window)
{
	character = _character;

	borders = interface::STD_BORDER_SIZE;
	float barSizeDiv = 8.f;

	outerRectSize = sf::Vector2f(character->getWidth() + borders.x, character->getHeight() / barSizeDiv + borders.y);
	innerRectSize = sf::Vector2f((outerRectSize.x - borders.x * 2), (outerRectSize.y - borders.y * 2));

	outerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(outerRectSize));
	innerRect = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(innerRectSize));
	

	sf::Vector2f tempPos(character->getPosX() - borders.x, character->getPosY() + borders.y);
	posCoords = tempPos;
	sf::Vector2f innerRectPos((posCoords.x + borders.x), (posCoords.y + borders.y));
	

	outerRect->setPosition(posCoords);
	innerRect->setPosition(innerRectPos);

	outerColor = sf::Color::Black;
	innerColor = sf::Color::Blue;

	outerRect->setFillColor(outerColor);
	innerRect->setFillColor(innerColor);
}


castTimeBar::~castTimeBar()
{
}
void castTimeBar::draw() {
	window->draw(*outerRect.get());
	window->draw(*innerRect.get());
}

void castTimeBar::update() {
	if (character->getAlive()) {
		
		sf::Vector2f tempPos(character->getPosX() - borders.x, character->getPosY() + character->getHeight() + borders.y * 5.f);
		setPosCoords(tempPos);
		if (character->getState()->getStateNum() == 4) {

			int delay = character->getTimers().getCastDelay();;
			
			float k = (static_cast<float>(character->getTimers().getClockPtr()->getElapsedTime().asMilliseconds()) -
				static_cast<float>(character->getTimers().getCastStartTime())) / static_cast<float>(delay);

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