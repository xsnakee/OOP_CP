#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

const std::string MENU_BG_TEXTURE_FILE = "img/menu/menu_bg.jpg";
const std::string NAME_TEXTURE_FILE = "img/menu/nameTexture.png";
const std::string MENU_BG_TEXTURE2_FILE = "img/manu/menu_bg.jpg";

class mainMenu_t
{
	

public:
	mainMenu_t(sf::RenderWindow *_window);
	~mainMenu_t();
};


size_t mainMenu(sf::RenderWindow *window);

