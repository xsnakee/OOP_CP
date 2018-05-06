#include "InterfaceEngine_t.h"



InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level):level(_level)
{
	window = _window;
	generateHPbars();
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
		barsList.push_back(std::unique_ptr<LifeBar>(new LifeBar(window, i.get())));
	}
}