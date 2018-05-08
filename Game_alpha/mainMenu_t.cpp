#include "mainMenu_t.h"



mainMenu_t::mainMenu_t(sf::RenderWindow *_window, std::string &_levelName, size_t &_difficulty):levelName(_levelName),difficulty(_difficulty)
{
	window = _window;

	//TEXTURE  PREFERENCES
	bgTexture = std::move(texture(new sf::Texture));
	nameTexture = std::move(texture(new sf::Texture));
	bgTexture->loadFromFile(MENU_BG_TEXTURE_FILE);
	nameTexture->loadFromFile(NAME_TEXTURE_FILE);

	//SPRITES PREFERENCES
	bgSprite.setTexture(*bgTexture.get());
	nameSprite.setTexture(*nameTexture.get());

	//TEXT PREFERENCES
	textFont.loadFromFile("fonts/hercules_modern.ttf");
	fontSize = window->getSize().x / 32;
	itemsMainColor = sf::Color::Color(255, 255, 255, 255);
	variativeItemsColor = sf::Color::Yellow;
	variativeItemsColor = sf::Color::Green;


	menuItems = {
		"START GAME",
		"LEVEL: ",
		"DIFFICULTY: ",
		"EXIT"
	};
	levelNamesList = {
		"West Land",
		"East Land (in dev)",
		"Evil Land (in dev)",
		"Russia Land (in dev)"
	};
	difficulValuesList = {
		"EASY",
		"MEDIUM",
		"HARD"
	};

	levelNameText.setFont(textFont);
	levelNameText.setCharacterSize(fontSize);
	levelNameText.setFillColor(variativeItemsColor);

	difficultyText.setFont(textFont);
	difficultyText.setCharacterSize(fontSize);
	difficultyText.setFillColor(variativeItemsColor);

	active = true;
}


mainMenu_t::~mainMenu_t()
{
}

void mainMenu_t::makeMenu() {
	sf::Vector2u winSize = window->getSize();//CALCULATE WINDOW SIZE

	float  kX = (static_cast<float>(window->getSize().x) / static_cast<float>(bgTexture->getSize().x));
	float  kY = (static_cast<float>(window->getSize().y) / static_cast<float>(bgTexture->getSize().y));
	bgSprite.setScale(kX, kY);

	float  kX1 = (static_cast<float>(window->getSize().x) / static_cast<float>(nameTexture->getSize().x));
	float  kY1 = (static_cast<float>(window->getSize().y) / static_cast<float>(nameTexture->getSize().y));
	nameSprite.setScale(kX1, kY1);
	nameSprite.setOrigin(nameTexture->getSize().x / 2, nameTexture->getSize().y / 2);//Поменять координаты!!!!!!!!!!!!
	nameSprite.setPosition(winSize.x / 2, nameTexture->getSize().y / 2);

	//MAKE MENU ITEMS TEXT
	int menuItemsVerticalMargin = winSize.y / 10;
	float itemskX = 0.5f;
	float itemskY = 0.45f;
	sf::Vector2f menuPosition(static_cast<float>(winSize.x) * itemskX, static_cast<float>(winSize.y) * itemskY);//ITEMS POSITION

	for (size_t i = 0; i < menuItems.size(); ++i) {
		menuItemsText.push_back(sf::Text(menuItems[i], textFont, fontSize));
		menuItemsText.back().setPosition(menuPosition.x, menuPosition.y + menuItemsVerticalMargin * i);
		menuItemsText.back().setFillColor(itemsMainColor);
		sf::IntRect tempRect(static_cast<int>(menuItemsText.back().getPosition().x), static_cast<int>(menuItemsText.back().getPosition().y),
			menuItemsText.back().getLocalBounds().width, menuItemsText.back().getLocalBounds().height);
		menuItemsRectList.push_back(tempRect);
	}

	//LEVEL NAME POSITION
	sf::Vector2f levelTextPos(menuItemsText[1].getLocalBounds().width, 0.f);
	levelNameText.setPosition(menuItemsText[1].getPosition() + levelTextPos);
	sf::IntRect levelNameRect(static_cast<int>(levelNameText.getPosition().x), static_cast<int>(levelNameText.getPosition().y),
		levelNameText.getLocalBounds().width, levelNameText.getLocalBounds().height);


	//DIFFICULITY VALUE POSITION
	sf::Vector2f diffTextPos(menuItemsText[2].getLocalBounds().width, 0.f);
	difficultyText.setPosition(menuItemsText[2].getPosition() + diffTextPos);
	sf::IntRect diffTextRect(static_cast<int>(difficultyText.getPosition().x), static_cast<int>(difficultyText.getPosition().y),
		difficultyText.getLocalBounds().width, difficultyText.getLocalBounds().height);


}

void mainMenu_t::draw() {

	window->clear();
	window->draw(bgSprite);
	window->draw(nameSprite);
	for (auto &i : menuItemsText) {
		window->draw(i);
	}
	window->draw(difficultyText);
	window->draw(levelNameText);
	window->display();
}

void mainMenu_t::action() {


	//Int RECT LSIT
	//LEVEL
	size_t currentLevelItem = 0;
	size_t levelAmount = levelNamesList.size() - 1;

	//DIFFICALTY
	size_t currentDifficulityItem = 0;
	size_t maxDifficulity = difficulValuesList.size() - 1;

	sf::Event event;

	int currentItem = -1;
	while (active) {
		while (window->pollEvent(event)) {
			//COLOR TO DEFAULT
			for (auto &i : menuItemsText) {
				i.setFillColor(itemsMainColor);
			}
			difficultyText.setFillColor(variativeItemsColor);
			levelNameText.setFillColor(variativeItemsColor);
			//SET LEVEL & DIFFICULTY
			difficultyText.setString(difficulValuesList[currentDifficulityItem]);
			levelNameText.setString(levelNamesList[currentLevelItem]);

			currentItem = itemChoice();

			//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
				switch (currentItem) {
				case 0: {
					levelName = levelNamesList[currentLevelItem];
					difficulty = currentDifficulityItem + 1;
					active = false;
				}
				case 1: {
					if (currentLevelItem < levelAmount) {
						++currentLevelItem;
					}
					else {
						currentLevelItem = 0;
					}
					break;
				}
				case 2: {
					if (currentDifficulityItem < maxDifficulity) {
						++currentDifficulityItem;
					}
					else {
						currentDifficulityItem = 0;
					}
					break;
				}
				case 3: {
					exit(0);
				}
				}
			}
		}
		draw();
	}
}

int mainMenu_t::itemChoice() {
	int currentItem = -1;

	if (menuItemsRectList[0].contains(sf::Mouse::getPosition(*window))) {
		menuItemsText[0].setFillColor(targetItemColor);
		currentItem = 0;
	}
	if (menuItemsRectList[1].contains(sf::Mouse::getPosition(*window))) {
		menuItemsText[1].setFillColor(targetItemColor);
		currentItem = 1;
	}
	if (menuItemsRectList[2].contains(sf::Mouse::getPosition(*window))) {
		menuItemsText[2].setFillColor(targetItemColor);
		currentItem = 2;
	}
	if (menuItemsRectList[3].contains(sf::Mouse::getPosition(*window))) {
		menuItemsText[3].setFillColor(targetItemColor);
		currentItem = 3;
	}
	return currentItem;
}