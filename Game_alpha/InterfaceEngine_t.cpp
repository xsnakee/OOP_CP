#include "InterfaceEngine_t.h"

InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level) :level(_level)
{
	window = _window;
	generateHPbars();
	setObservedBards();
	createIterface();

}
InterfaceEngine_t::~InterfaceEngine_t()
{
}
void InterfaceEngine_t::update() {
	updateGenerator();

	for (auto i = barsList.begin(); i != barsList.end(); ++i) {
		if (i->get()->getDisplay()) {
			i->get()->update();
		}
		else {
			barsList.erase(i);
		}
	}

	for (auto &i : windowsList) {
		i->update();
	}

}

void InterfaceEngine_t::draw() {
	for (auto &i : barsList) {
		i->draw();
	}
	for (auto &i : windowsList) {
		i->draw();
	}
}


//INTERFACE BUILD

void InterfaceEngine_t::generateHPbars() {
	for (auto &i : level.charactersList) {
		barsList.push_back(bar_t(new LifeBar(window, i.get())));
	}
}

void InterfaceEngine_t::setObservedBards() {
	barsList.push_back(bar_t(new castTimeBar(window, level.charactersList.begin()->get())));
	float tempBarCounter = .5f;
	sf::Vector2f tempMargin(interface::STD_BORDER_SIZE);

	barsList.push_back(bar_t(new progressBar(window, tempMargin, level.charactersList.begin()->get()->getStats().HP, level.charactersList.begin()->get()->getStats().stdHP)));

	++tempBarCounter;
	tempMargin.y += interface::STD_BAR_SIZE.y;
	barsList.push_back(bar_t(new progressBar(window, tempMargin, level.charactersList.begin()->get()->getStats().MP, level.charactersList.begin()->get()->getStats().stdMP)));
	barsList.back()->setInnerRectColor(sf::Color::Blue);
}

void InterfaceEngine_t::createIterface() {

	//ELEMENT GENERATOR STATUS
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	size_t elemWindowAmount = elements::SKILL_ELEMENT_AMOUNT;
	float betweenCorection = 7.f;

	float rightWindowPadding = 60.f;
	float bottomWindowPadding = 10.f;

	while (elemWindowAmount-- > 0) {
		float multipleCorection = static_cast<float>(elemWindowAmount);

		float positionCorrectionX = (window->getSize().x - multipleCorection * interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.x - multipleCorection * betweenCorection - rightWindowPadding);
		float positionCorrectionY = (window->getSize().y - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.y - bottomWindowPadding);

		sf::Vector2f coordCorection(positionCorrectionX, positionCorrectionY);

		windowsList.push_back(window_t(new InterfaceWindow_t(window, (tempPos + coordCorection), interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE)));
		auto &i = windowsList.back();
		i->setBgColor(sf::Color::Color(50, 50, 50, 150));
		i->setBorderColor(sf::Color::Color(238, 238, 238, 150));
	}
	elemIt = windowsList.end();

	for (size_t i = 0; i < elements::SKILL_ELEMENT_AMOUNT; ++i) {
		--elemIt;
	}

	rightWindowPadding = 80.f;
	bottomWindowPadding = 80.f;
	float positionCorrectionX = (window->getSize().x - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.x - rightWindowPadding);
	float positionCorrectionY = (window->getSize().y - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.y - bottomWindowPadding);
	sf::Vector2f coordCorection(positionCorrectionX, positionCorrectionY);

	windowsList.push_back(window_t(new InterfaceWindow_t(window, (tempPos + coordCorection), interface::STD_SKILL_WINDOW_SIZE)));
	sf::Texture *temp = new sf::Texture;
	temp->loadFromFile(animation::DEFAULT_TEXTURE);
	windowsList.back()->contentList.push_back(content(new InterfaceSpriteOb_t(window, temp, windowsList.back()->getPos(), sf::Vector2f(0.f, 0.f))));

	/*
	//Element icon
	sf::Texture *temp = new sf::Texture;
	temp->loadFromFile(animation::ICON_ELEMENT_FIRE_FILE);
	windowsList.back()->contentList.push_back(content(new InterfaceSpriteOb_t(window,temp, windowsList.back()->getPos(),sf::Vector2f(0.f,0.f))));
	*/
}

void InterfaceEngine_t::updateGenerator() {
	std::list<elements::element> &ElemsArr = level.mainHero->get()->getElements();
	std::list<window_t>::iterator tempElemIt = elemIt;


	for (auto &i : ElemsArr) {
		using namespace elements;
		switch (i) {
		case FIRE: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(animation::ICON_ELEMENT_FIRE_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteOb_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case WIND: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(animation::ICON_ELEMENT_WIND_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteOb_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case EARTH: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(animation::ICON_ELEMENT_EARTH_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteOb_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case NONE: {
			tempElemIt->get()->contentList.clear();
			break;
		}

		}
		++tempElemIt;
	}

	/*
	switch (level.mainHero->get()->getElemStatus()) {
	case 3: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_RUSH_FILE);
		break;
	}
	case 6: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_POWER_UP_FILE);
		break;
	}
	case 24: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_HEAL_BALL_FILE);
		break;
	}
	case 1: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_sWORD_ATTACK_FILE);
		break; }
	case 4: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_SMALL_FIRE_BALLS_FILE);
		break; }
	case 10: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_SMALL_EARTH_BALLS_FILE);
		break; }
	case 5: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_FIRE_BALL_FILE);
		break; }
	case 17: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_EARTH_BALL_FILE);
		break; }
	case 12: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_LAVA_POOL_FILE);
		break; }
	case 18: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_BANG_BALL_FILE);
		break; }
	case 11: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::ICON_SKILL_COMBO_BALL_FILE);
		break;
	}
	default: {

		tempElemIt->get()->contentList.begin()->get()->swapContent(animation::DEFAULT_TEXTURE);
		break;
	}
	}
	//*/
}