#include "InterfaceEngine_t.h"



InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level):level(_level)
{
	window = _window;
	generateHPbars();
	setObservedBards();
	
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

}

void InterfaceEngine_t::draw() {
	for (auto &i : barsList) {
		i->draw();
	}
}

void InterfaceEngine_t::generateHPbars() {
	for (auto &i : level.charactersList) {
		barsList.push_back(std::unique_ptr<InterfaceBar>(new LifeBar(window, i.get())));
	}
}

void InterfaceEngine_t::setObservedBards() {
	barsList.push_back(std::unique_ptr<InterfaceBar>(new castTimeBar(window, level.charactersList.begin()->get())));
	barsList.push_back(std::unique_ptr<InterfaceBar>(new progressBar(window, level.charactersList.begin()->get()->getStats().HP, level.charactersList.begin()->get()->getStats().stdHP)));
	barsList.push_back(std::unique_ptr<InterfaceBar>(new progressBar(window, level.charactersList.begin()->get()->getStats().MP, level.charactersList.begin()->get()->getStats().stdMP)));
}