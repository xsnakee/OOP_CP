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

void InterfaceEngine_t::createIterface() {

	//ELEMENT GENERATOR STATUS
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	size_t elemWindowAmount = 3;

	while(elemWindowAmount-- > 0){
		float positionCorrectionX = (window->getSize().x - static_cast<float>(elemWindowAmount) * interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.x - 60.f);
		float positionCorrectionY = (window->getSize().y - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.y - 10.f);

		sf::Vector2f coordCorection(positionCorrectionX, positionCorrectionY);

		windowsList.push_back(interfaceWindow_t(new InterfaceWindow_t(window, (tempPos+ coordCorection), interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE)));
	}
		
	
	
	/*
	//Element icon
	sf::Texture *temp = new sf::Texture;
	temp->loadFromFile(animation::ICON_ELEMENT_FIRE_FILE);
	windowsList.back()->contentList.push_back(content(new InterfaceSpriteOb_t(window,temp, windowsList.back()->getPos(),sf::Vector2f(0.f,0.f))));
	*/
}