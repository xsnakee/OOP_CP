#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>

const std::string MENU_BG_TEXTURE_FILE = "img/menu/menu_bg.jpg";
const std::string NAME_TEXTURE_FILE = "img/menu/nameTexture.png";
const std::string FONT_FILE = "fonts/hercules_modern.ttf";

typedef std::unique_ptr<sf::Texture> texture;
typedef std::unique_ptr<sf::Texture> sprite;
typedef std::vector<std::string> strVec;

class mainMenu_t
{
	sf::RenderWindow *window;
	texture bgTexture;
	texture nameTexture;
	sf::Sprite bgSprite;
	sf::Sprite nameSprite;

	strVec menuItems;
	strVec levelNamesList;
	strVec difficulValuesList;
	sf::Text levelNameText;
	sf::Text difficultyText;

	std::vector<sf::Text> menuItemsText;
	std::vector<sf::FloatRect> menuItemsRectList;

	sf::Font textFont;
	unsigned int fontSize;
	sf::Color itemsMainColor;
	sf::Color targetItemColor;
	sf::Color variativeItemsColor;
	
	void makeMenu();
	void draw();
	int itemChoice();

	std::string &levelName;
	size_t &difficulty;

public:
	bool active;

	mainMenu_t(sf::RenderWindow *_window,std::string &_levelName,size_t &_difficulty);
	~mainMenu_t();

	void action();
};



