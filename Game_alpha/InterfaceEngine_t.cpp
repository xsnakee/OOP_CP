#include "InterfaceEngine_t.h"

InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level) :level(_level)
{

	window = _window;

	generateHPbars();
	setObservedBards();
	createSkillGeneratorIterface(); 
	createJournalWindow();
	createGameStatsWindow();
	createMapWindow();
	createPausedMenu();

	createInterfaceButtons();


	cursor = std::move(std::unique_ptr<cursor_t>(new cursor_t("img/cursor_aim.png", 20, 20, window)));

}
InterfaceEngine_t::~InterfaceEngine_t()
{
}


void InterfaceEngine_t::drawCursor() {
	window->draw(cursor->getSprite());
}

void InterfaceEngine_t::update() {
	updateMissionJournal();
	updateGenerator();
	if (missionWindowIt->get()->getDisplayState()) {
		updateMissionJournal();
	}
	if (gameStatsWindowIt->get()->getDisplayState()) {
		updateGameStats();
	}
	if (mapIt->get()->getDisplayState()) {
		updateMapWindow();
	}

	level.mainHero->get()->setTargetPos(cursor->getPosition());

	for (auto i = barsList.begin(); i != barsList.end(); ++i) {
		if (i->get()->getDisplay()) {
			i->get()->update();
		}
		else {
			barsList.erase(i);
		}
	}

	for (auto &i : windowsList) {
		i->update();
	}
	for (auto &i : buttonList) {
		i->update();
	}
	cursor->setCursorPosition();

}

void InterfaceEngine_t::draw() {
	for (auto &i : barsList) {
		i->draw();
	}
	for (auto &i : windowsList) {
		i->draw();
	}
	for (auto &i : buttonList) {
		i->draw();
	}
	drawCursor();
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

	barsList.push_back(bar_t(new progressBar(window, tempMargin, level.charactersList.begin()->get()->getStats().HP, level.charactersList.begin()->get()->getStats().stdHP)));

	++tempBarCounter;
	tempMargin.y += interface::STD_BAR_SIZE.y;
	barsList.push_back(bar_t(new progressBar(window, tempMargin, level.charactersList.begin()->get()->getStats().MP, level.charactersList.begin()->get()->getStats().stdMP)));
	barsList.back()->setInnerRectColor(sf::Color::Blue);
}

//SKILL GENERATOR INTERFACE
void InterfaceEngine_t::createSkillGeneratorIterface() {

	//SKILL GENERATOR ELEMENTS STATUS ICONS
	sf::Vector2f tempPos(interface::getScreenCoords(window));
	size_t elemWindowAmount = elements::SKILL_ELEMENT_AMOUNT;
	float betweenCorection = 7.f;

	float rightWindowPadding = 60.f;
	float bottomWindowPadding = 10.f;

	while (elemWindowAmount-- > 0) {
		float multipleCorection = static_cast<float>(elemWindowAmount);

		float positionCorrectionX = (window->getSize().x - multipleCorection * interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.x - multipleCorection * betweenCorection - rightWindowPadding);
		float positionCorrectionY = (window->getSize().y - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.y - bottomWindowPadding);

		sf::Vector2f coordCorection(positionCorrectionX, positionCorrectionY);

		windowsList.push_back(window_t(new InterfaceWindow_t(window, (tempPos + coordCorection), interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE)));
		auto &i = windowsList.back();
		i->setBgColor(sf::Color::Color(50, 50, 50, 150));
		i->setBorderColor(sf::Color::Color(238, 238, 238, 150));
	}
	elemIt = windowsList.end();

	for (size_t i = 0; i < elements::SKILL_ELEMENT_AMOUNT; ++i) {
		--elemIt;
	}

	//SKILL ICON WINDOW
	rightWindowPadding = 75.f;
	bottomWindowPadding = 80.f;
	float positionCorrectionX = (window->getSize().x - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.x - rightWindowPadding);
	float positionCorrectionY = (window->getSize().y - interface::STD_ELEMENT_GENERATOR_WINDOW_SIZE.y - bottomWindowPadding);
	sf::Vector2f coordCorection(positionCorrectionX, positionCorrectionY);

	windowsList.push_back(window_t(new InterfaceWindow_t(window, (tempPos + coordCorection), interface::STD_SKILL_WINDOW_SIZE)));
	sf::Texture *temp = new sf::Texture;

	windowsList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp, windowsList.back()->getPos(), sf::Vector2f(0.f, 0.f))));
	windowsList.back().get()->setBgColor(sf::Color::Color(50, 50, 50, 150));
	windowsList.back().get()->setBorderColor(sf::Color::Color(238, 238, 238, 150));

}

void InterfaceEngine_t::updateGenerator() {
	std::list<elements::element> &ElemsArr = level.mainHero->get()->getElements();
	std::list<window_t>::iterator tempElemIt = elemIt;

	for (auto &i : ElemsArr) {
		using namespace elements;
		switch (i) {
		case FIRE: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(icon::ICON_ELEMENT_FIRE_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case WIND: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(icon::ICON_ELEMENT_WIND_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case EARTH: {
			tempElemIt->get()->contentList.clear();
			sf::Texture *newTempTexture = new sf::Texture;
			newTempTexture->loadFromFile(icon::ICON_ELEMENT_EARTH_FILE);
			tempElemIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, newTempTexture, tempElemIt->get()->getPos(), sf::Vector2f(0.f, 0.f))));
			break;
		}
		case NONE: {
			tempElemIt->get()->contentList.clear();
			break;
		}

		}
		++tempElemIt;
	}

	
	//*
	switch (level.mainHero->get()->getElemStatus()) {
	case 3: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_RUSH_FILE);
		break;
	}
	case 6: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_POWER_UP_FILE);
		break;
	}
	case 24: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_HEAL_BALL_FILE);
		break;
	}
	case 1: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_sWORD_ATTACK_FILE);
		break; }
	case 4: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_SMALL_FIRE_BALLS_FILE);
		break; }
	case 10: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_SMALL_EARTH_BALLS_FILE);
		break; }
	case 5: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_FIRE_BALL_FILE);
		break; }
	case 17: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_EARTH_BALL_FILE);
		break; }
	case 12: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_LAVA_POOL_FILE);
		break; }
	case 18: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_BANG_BALL_FILE);
		break; }
	case 11: {
		tempElemIt->get()->contentList.begin()->get()->swapContent(icon::ICON_SKILL_COMBO_BALL_FILE);
		break;
	}
	default: {
		tempElemIt->get()->contentList.begin()->get()->resetContent();
		break;
	}
	}
	//*/
}


//MISSION JOURNAL INTERFACE
void InterfaceEngine_t::createJournalWindow() {
	size_t contentStringsAmount = level.getMission().missionsContent.size();
	//MAIN MISSION WINDOW
	sf::Vector2f windowPosition(STD_BUTTON_SIZE.x + interface::STD_WINDOW_MARGIN_SIZE.x, window->getSize().y / 4.f);
	sf::Vector2f windowSize(findBigestLength(level.getMission().missionsContent) * textSettings::STD_FONT_SIZE / 1.5f + interface::STD_BORDER_SIZE.x, (contentStringsAmount + 1) * (textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.y));

	windowsList.push_back(window_t(new InterfaceWindow_t(window,windowPosition,windowSize)));
	missionWindowIt = windowsList.end();
	--missionWindowIt;
	windowsList.back()->setTitle("MISSION JOURNAL");
	missionWindowIt->get()->setBgColor(sf::Color::Color(50, 50, 50, 80));
	missionWindowIt->get()->setBorderColor(sf::Color::Color(238, 238, 238, 80));
	sf::Vector2f contentPos(0.f, 0.f);
	contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;

	//MISSIONS LIST
	for (size_t i = 0; i < contentStringsAmount; ++i) {
		contentPos.y = static_cast<float>((i + 1) * textSettings::STD_FONT_SIZE) + interface::STD_BORDER_SIZE.x;
		windowsList.back()->contentList.push_back(content(new InterfaceTextContent_t(window, level.getMission().missionsContent[i], windowsList.back()->getPos(), contentPos)));
	}
}

void InterfaceEngine_t::updateMissionJournal() {
	std::vector<content>::iterator tempIt = missionWindowIt->get()->contentList.begin();
	for (size_t i = 0; i < missionWindowIt->get()->contentList.size(); ++i) {
		if (level.getMission().missionsCompleteStatus[i]) {
			tempIt->get()->swapContent();
		}
		++tempIt;
	}
}

//MISSION STATISTIC INTERFACE
void InterfaceEngine_t::createGameStatsWindow() {
	size_t contentStringsAmount = level.getMission().gameStats.statFields.size();
	//MAIN MISSION WINDOW
	sf::Vector2f windowPosition(STD_BUTTON_SIZE.x, windowsList.back()->getPos().y + windowsList.back()->getSizes().y);
	sf::Vector2f windowSize(findBigestLength(level.getMission().gameStats.statFields) * textSettings::STD_FONT_SIZE / 1.2f + interface::STD_BORDER_SIZE.x, (contentStringsAmount + 1) * (textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.y));
	windowPosition += interface::STD_WINDOW_MARGIN_SIZE;
	windowsList.push_back(window_t(new InterfaceWindow_t(window, windowPosition, windowSize)));
	gameStatsWindowIt = windowsList.end();
	--gameStatsWindowIt;
	windowsList.back()->setDisplay(false);
	windowsList.back()->setTitle("STATISTIC");
	gameStatsWindowIt->get()->setBgColor(sf::Color::Color(50, 50, 50, 80));
	gameStatsWindowIt->get()->setBorderColor(sf::Color::Color(238, 238, 238, 80));
	sf::Vector2f contentPos(0.f, 0.f);
	contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;

	//STATS LIST
	for (size_t i = 0; i < contentStringsAmount; ++i) {
		contentPos.y = static_cast<float>((i + 1) * textSettings::STD_FONT_SIZE) + interface::STD_BORDER_SIZE.x;
		std::string tempStr = (level.getMission().gameStats.statFields[i] + level.getMission().gameStats.statStrValues[i]);
		windowsList.back()->contentList.push_back(content(new InterfaceTextContent_t(window, tempStr, windowsList.back()->getPos(), contentPos)));
	}
}

void InterfaceEngine_t::updateGameStats() {
	level.getMission().gameStats.fillStrStats();
	for (size_t i = 0; i < level.getMission().gameStats.statFields.size(); ++i) {
		std::string tempStr = (level.getMission().gameStats.statFields[i] + level.getMission().gameStats.statStrValues[i]);
		gameStatsWindowIt->get()->contentList[i]->setText(tempStr);
	}
}

void InterfaceEngine_t::createMapWindow() {

	sf::Texture *miniMapTexure(new sf::Texture);
	std::string mapFileName = "img/maps/" + level.map.getLvlName() + ".png";
	miniMapTexure->loadFromFile(mapFileName);

	sf::Vector2f mapSize(miniMapTexure->getSize());
	sf::Vector2f mapPosition(window->getSize().x/2 - mapSize.x /2 , window->getSize().y / 2 - mapSize.y / 2);
	windowsList.push_back(window_t(new InterfaceWindow_t(window, mapPosition, mapSize)));
	
	mapIt = windowsList.end();
	--mapIt;

	mapIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window,miniMapTexure,mapIt->get()->getPos())));
	mapIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, ".", mapIt->get()->getPos())));
	unsigned int characterSize = 80;
	mapIt->get()->contentList.back()->setFontSize(characterSize);
	mapIt->get()->toggleDisplay();
}

void InterfaceEngine_t::updateMapWindow() {

	sf::Vector2f mapk;
	mapk.x = mapIt->get()->getSizes().x / level.map.getFloatSize().x;
	mapk.y = mapIt->get()->getSizes().y / level.map.getFloatSize().y;

	sf::Vector2f posCharOnMap (level.mainHero->get()->getPos().x * mapk.x, level.mainHero->get()->getPos().y * mapk.y);
	float k = static_cast<float>(mapIt->get()->contentList.back()->getFontSize());
	sf::Vector2f posCorrection(k/4.f, k);
	mapIt->get()->contentList.back()->setRelativePos(posCharOnMap - posCorrection);
}



void InterfaceEngine_t::createPausedMenu() {
	sf::Vector2f windowSize(static_cast<float>(window->getSize().x / 2), static_cast<float>(window->getSize().y / 2));
	sf::Vector2f windowPosition(static_cast<float>(window->getSize().x / 2) - windowSize.x / 2.f, static_cast<float>(window->getSize().y / 2) - windowSize.y / 2.f);

	windowsList.push_back(window_t(new InterfaceWindow_t(window, windowPosition, windowSize)));
	pausedMenuIt = windowsList.end();
	--pausedMenuIt;
	pausedMenuIt->get()->setBgColor(sf::Color::Color(50, 50, 50, 150));
	pausedMenuIt->get()->setBorderColor(sf::Color::Color(238, 238, 238, 150));
	pausedMenuIt->get()->setDisplay(false);

	sf::Vector2f statusMassageSize(windowSize.x / 2.f, windowSize.y / 7.f);
	sf::Vector2f statusMassagePos(windowSize.x / 2.f - statusMassageSize.x / 4.f, statusMassageSize.y);

	pausedMenuIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "PAUSE", windowPosition, statusMassagePos)));
	pausedMenuIt->get()->contentList.back()->setFontSize(40);
	pausedMenuIt->get()->contentList.back()->setFontColor(sf::Color::White);



	sf::Vector2f restartButtonsSize(windowSize.x / 2.f, windowSize.y / 7.f);
	sf::Vector2f restartButtonPos(windowPosition.x + windowSize.x / 2.f - restartButtonsSize.x / 4.1f, windowPosition.y + statusMassageSize.y + restartButtonsSize.y * 3.f);
	buttonList.push_back(button(new InterfaceRestartButton(*pausedMenuIt->get(), restartButtonPos)));
	buttonList.back()->setTitle("RESTART");
	buttonList.back()->setTextFontSize(28);
	buttonList.back()->setTextColor(sf::Color::White);
	resumeButton = buttonList.end();
	--resumeButton;

	sf::Vector2f backToMainMenuButtonsSize(windowSize.x / 2.f, windowSize.y / 7.f);
	sf::Vector2f backToMainMenuButtonPos(windowPosition.x + windowSize.x / 2.f - backToMainMenuButtonsSize.x / 2.f, restartButtonPos.y + backToMainMenuButtonsSize.y);
	buttonList.push_back(button(new IntefaceExitButton(*pausedMenuIt->get(), backToMainMenuButtonPos)));
	buttonList.back()->setTitle("BACK TO MAIN MENU");
	buttonList.back()->setTextFontSize(28);
	buttonList.back()->setTextColor(sf::Color::White);
	backTomainMenuButton = buttonList.end();
	--backTomainMenuButton;
}

bool InterfaceEngine_t::toggleMenu() {
	return pausedMenuIt->get()->toggleDisplay();
}


//BUTTONS

void InterfaceEngine_t::createInterfaceButtons() {
	sf::Vector2f buttonPosition(interface::STD_MARGIN_SIZE.x, window->getSize().y / 4.f);
	sf::Vector2f buttonMargin(0.f, interface::STD_MARGIN_SIZE.y);
	//JOURNAL BUTTON
	buttonList.push_back(button(new IntefaceToggleButton(*missionWindowIt->get(), buttonPosition)));
	sf::Texture *temp = new sf::Texture;
	temp->loadFromFile(icon::ICON_BUTTON_JOURNAL);
	buttonList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp, buttonList.back()->getPos())));

	//GAME STATISTIC BUTTON
	buttonPosition.y = buttonPosition.y + buttonList.back()->getSizes().y;
	buttonList.push_back(button(new IntefaceToggleButton(*gameStatsWindowIt->get(), buttonPosition + buttonMargin)));
	sf::Texture *temp2 = new sf::Texture;
	temp2->loadFromFile(icon::ICON_BUTTON_GAME_STATISTIC);
	buttonList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp2, buttonList.back()->getPos())));

	//MAP BUTTON
	buttonPosition.y = buttonPosition.y + buttonList.back()->getSizes().y;
	buttonList.push_back(button(new IntefaceToggleButton(*mapIt->get(), buttonPosition + buttonMargin + buttonMargin)));
	sf::Texture *temp3 = new sf::Texture;
	temp3->loadFromFile(icon::ICON_BUTTON_MAP);
	buttonList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp3, buttonList.back()->getPos())));


}