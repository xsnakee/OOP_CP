#include "InterfaceEngine_t.h"



InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level):level(_level)
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
	sf::Vector2f tempPos(100.f,100.f);
	windowsList.push_back(interfaceWindow_t(new InterfaceOb_t(window,tempPos,interface::STD_WINDOW_SIZE)));
	windowsList.back()->setTitle("kyky");
	windowsList.back()->setTitlePos(sf::Vector2f(100.f, 100.f));
}