#include "mainMenu_t.h"



mainMenu_t::mainMenu_t(sf::RenderWindow *_window)
{
}


mainMenu_t::~mainMenu_t()
{
}


size_t mainMenu(sf::RenderWindow *window) {
	sf::Texture bgTexture;
	bgTexture.loadFromFile(MENU_BG_TEXTURE_FILE);
	sf::Sprite bgSprite(bgTexture);

	float  kX = (static_cast<float>(window->getSize().x) / static_cast<float>(bgTexture.getSize().x));
	float  kY = (static_cast<float>(window->getSize().y) / static_cast<float>(bgTexture.getSize().y));
	bgSprite.setScale(kX,kY);

	sf::Texture nameTexure;
	nameTexure.loadFromFile(NAME_TEXTURE_FILE);
	sf::Sprite nameSprite(nameTexure);
	nameSprite.setScale(kX, kY);
	nameSprite.setOrigin(nameTexure.getSize().x / 2, nameTexure.getSize().y / 2);
	nameSprite.setPosition(window->getView().getCenter().x, nameTexure.getSize().y / 2);

	bool isOpen = true;

	//TEXT SETTINGS
	sf::Font font;
	font.loadFromFile("fonts/hercules_modern.ttf");
	size_t fontSize = window->getSize().x / 32;
	sf::Color textColor(sf::Color::Color(255,255,255,255));

	//MENU ITEMS
	std::vector<std::string> menuItems = {
		"START GAME",
		"LEVEL: ",
		"DIFFICULTY: ",
		"EXIT"
	};
	std::vector<sf::Text> menuItemsObjects;
	sf::Vector2u winSize = window->getSize();
	sf::Vector2u leftTopWindowPos(window->getView().getCenter().x - winSize.x / 2, window->getView().getCenter().y - winSize.y / 2);
	unsigned int menuItemsVerticalMargin = winSize.y / 8;	
	std::vector<sf::IntRect> menuItemsRectList; //Int RECT LSIT
	sf::Vector2f menuPosition(static_cast<float>(winSize.x) * 0.5, winSize.y / 2);	
	for (size_t i = 0; i < menuItems.size(); ++i) {
		menuItemsObjects.push_back(sf::Text(menuItems[i], font, fontSize));
		menuItemsObjects.back().setPosition(menuPosition.x, menuPosition.y + menuItemsVerticalMargin*i);
		menuItemsObjects.back().setFillColor(textColor);
		sf::IntRect tempRect(static_cast<int>(menuItemsObjects.back().getPosition().x), static_cast<int>(menuItemsObjects.back().getPosition().y), 
			menuItemsObjects.back().getLocalBounds().width, menuItemsObjects.back().getLocalBounds().height);
		menuItemsRectList.push_back(tempRect);
	}

	//LEVEL
	std::vector<std::string> levelsList = {
		"West Land",
		"East Land (in dev)",
		"Evil Land (in dev)",
		"Russia Land (in dev)"
	};
	size_t currentLevelItem = 0;
	size_t maxDifficulity = difficulValues.size();

	sf::Text difficultyText("", font, fontSize);
	sf::Color difficultyTextColor(sf::Color::Yellow);
	difficultyText.setFillColor(difficultyTextColor);
	sf::Vector2f textPos(menuItemsObjects[2].getLocalBounds().width, 0.f);
	difficultyText.setPosition(menuItemsObjects[2].getPosition() + textPos);
	sf::IntRect diffTextRect(static_cast<int>(difficultyText.getPosition().x), static_cast<int>(difficultyText.getPosition().y),
		difficultyText.getLocalBounds().width, difficultyText.getLocalBounds().height);



	//DIFFICALTY
	std::vector<std::string> difficulValues = {
		"EASY",
		"MEDIUM",
		"HARD"
	};
	size_t currentDifficulityItem = 0;
	size_t maxDifficulity = difficulValues.size() - 1;
	
	sf::Text difficultyText("",font,fontSize);
	sf::Color difficultyTextColor(sf::Color::Yellow);
	difficultyText.setFillColor(difficultyTextColor);
	sf::Vector2f textPos(menuItemsObjects[2].getLocalBounds().width, 0.f);
	difficultyText.setPosition(menuItemsObjects[2].getPosition() + textPos);
	sf::IntRect diffTextRect(static_cast<int>(difficultyText.getPosition().x), static_cast<int>(difficultyText.getPosition().y),
	difficultyText.getLocalBounds().width, difficultyText.getLocalBounds().height);

	



	sf::Color targetItemColor(sf::Color::Green);
	sf::Event event;

	size_t currentItem = 0;
	while (isOpen) {


		currentItem = 0;
	while (window->pollEvent(event)) {
		for (auto &i : menuItemsObjects) {
			i.setFillColor(textColor);
		}
		difficultyText.setFillColor(difficultyTextColor);
		difficultyText.setString(difficulValues[currentDifficulityItem]);

		if (menuItemsRectList[0].contains(sf::Mouse::getPosition(*window))) {
			menuItemsObjects[0].setFillColor(targetItemColor);
			currentItem = 1;
		}
		if (menuItemsRectList[1].contains(sf::Mouse::getPosition(*window))) {
			menuItemsObjects[1].setFillColor(targetItemColor);
			currentItem = 2;
		}
		if (menuItemsRectList[2].contains(sf::Mouse::getPosition(*window))) {
			menuItemsObjects[2].setFillColor(targetItemColor);
			currentItem = 3;
		}

		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
			switch (currentItem) {
			case 1: {
				return currentDifficulityItem;
			}
			case 2: {
				if (currentDifficulityItem < maxDifficulity) {
					++currentDifficulityItem;
				}
				else {
					currentDifficulityItem = 1;
				}
				break;
			}
			case 3: {
				exit(0);
			}
			}
		}
		window->clear();
		window->draw(bgSprite);
		window->draw(nameSprite);
		for (auto &i : menuItemsObjects) {
			window->draw(i);
		}
		window->draw(difficultyText);
		window->display();
	}
	}
}
