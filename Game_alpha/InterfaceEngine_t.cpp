#include "InterfaceEngine_t.h"

InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level) :level(_level)
{
	window = _window;
	generateHPbars();
	setObservedBards();
	createIterfaceWindows();

}
InterfaceEngine_t::~InterfaceEngine_t()
{
}
void InterfaceEngine_t::update() {

	for (auto i = barsList.begin(); i != barsList.end(); ++i) {
		if (i->get()->getDisplay()) {
			i->get()->update();
		}
		else {
			barsList.erase(i);
		}
	}

	for (auto &i: windowsList) {
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

	barsList.push_back(bar_t(new progressBar(window, tempMargin,level.charactersList.begin()->get()->getStats().HP, level.charactersList.begin()->get()->getStats().stdHP)));
	
	++tempBarCounter;
	tempMargin.y += interface::STD_BAR_SIZE.y;
	barsList.push_back(bar_t(new progressBar(window, tempMargin,level.charactersList.begin()->get()->getStats().MP, level.charactersList.begin()->get()->getStats().stdMP)));
	barsList.back()->setInnerRectColor(sf::Color::Blue);
}

void InterfaceEngine_t::createIterfaceWindows() {
	sf::Vector2f tempPos(500.f,500.f);
	windowsList.push_back(interfaceWindow_t(new InterfaceWindow_t(window,tempPos,interface::STD_WINDOW_SIZE)));
	windowsList.back()->setTitle("kyky");
	windowsList.back()->setTitlePos(sf::Vector2f(100.f, 100.f));
	sf::Texture *temp = new sf::Texture;
	temp->loadFromFile(animation::ICON_ELEMENT_FIRE_FILE);
	windowsList.back()->contentList.push_back(content(new InterfaceSpriteOb_t(window,temp, windowsList.back()->getPos(),sf::Vector2f(0.f,0.f))));
	
}