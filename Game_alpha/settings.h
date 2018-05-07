#pragma once
#include <iostream>

namespace textSettings{
	const std::string MAIN_FONT_FILE = "fonts/main_font.ttf";
};

namespace interface {
	const sf::Vector2f STD_BAR_SIZE(400.f, 20.f);
	const sf::Vector2f STD_BORDER_SIZE(2.f,2.f);


	static sf::Vector2f getScreenCoords(sf::RenderWindow *window) {
		return sf::Vector2f(window->getView().getCenter().x - window->getSize().x /2, window->getView().getCenter().y - window->getSize().y / 2);
	}
};