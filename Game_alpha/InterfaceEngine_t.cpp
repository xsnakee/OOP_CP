#include "InterfaceEngine_t.h"

InterfaceEngine_t::InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level) :level(_level)
{

	window = _window;

	view.swap(std::unique_ptr <sf::View>(new sf::View));
	view->reset(sf::FloatRect(0, 0, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	generateHPbars();
	setObservedBards();
	createSkillGeneratorIterface(); 
	createJournalWindow();
	createGameStatsWindow();
	createDescriptionMenu();
	createMapWindow();
	createPausedMenu();

	createInterfaceButtons();


	cursor.swap(std::unique_ptr<cursor_t>(new cursor_t("img/cursor_aim.png", 20, 20, window)));

}
InterfaceEngine_t::~InterfaceEngine_t()
{
	window->setView(window->getDefaultView());
	window->setMouseCursorVisible(true);
}


void InterfaceEngine_t::drawCursor() {
	window->draw(cursor->getSprite());
}

void InterfaceEngine_t::update() {

	setCamera();//set Camera
	window->setView(*view); // Set camera

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

	for (auto &i = barsList.begin(); i != barsList.end(); ++i) {
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

	windowsList.push_back(window_t(new InterfaceWindow_t(window, windowPosition, windowSize)));
	missionWindowIt = windowsList.end();
	--missionWindowIt;
	windowsList.back()->setTitle("MISSION JOURNAL");
	windowsList.back()->setDisplay(false);
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
	//sf::Vector2f statusMassagePos(windowSize.x / 2.13f, statusMassageSize.y);

	pausedMenuIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "PAUSE", windowPosition, statusMassagePos)));
	pausedMenuIt->get()->contentList.back()->setFontSize(40);
	pausedMenuIt->get()->contentList.back()->setFontColor(sf::Color::White);

	sf::Vector2f restartButtonsSize(windowSize.x / 2.f, windowSize.y / 7.f);
	sf::Vector2f restartButtonPos(windowPosition.x + windowSize.x / 2.f - restartButtonsSize.x / 2.f, windowPosition.y + statusMassageSize.y + restartButtonsSize.y * 3.f);
	buttonList.push_back(button(new InterfaceRestartButton(*pausedMenuIt->get(), restartButtonPos)));
	restartButton = buttonList.end();
	--restartButton;

	restartButton->get()->setSizes(restartButtonsSize);
	sf::Vector2f restartButtonContentCorrectionPos(restartButtonsSize.x / 2.f - restartButtonsSize.x / 3.f, 0.f);
	//sf::Vector2f restartButtonContentCorrectionPos(restartButtonsSize.x / 2.24f,0.f);
	restartButton->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "RESTART", restartButtonPos, restartButtonContentCorrectionPos)));
	restartButton->get()->contentList.back()->setFontSize(28);
	restartButton->get()->contentList.back()->setFontColor(sf::Color::White);


	sf::Vector2f backToMainMenuButtonsSize(windowSize.x / 2.f, windowSize.y / 7.f);
	sf::Vector2f backToMainMenuButtonPos(windowPosition.x + windowSize.x / 2.f - backToMainMenuButtonsSize.x / 2.f, restartButtonPos.y + backToMainMenuButtonsSize.y);
	buttonList.push_back(button(new IntefaceExitButton(*pausedMenuIt->get(), backToMainMenuButtonPos)));
	backTomainMenuButton = buttonList.end();
	--backTomainMenuButton;
	
	backTomainMenuButton->get()->setSizes(backToMainMenuButtonsSize);

	//sf::Vector2f  backToMainMenuButtonButtonContentCorrectionPos(backToMainMenuButtonsSize.x / 4.f, 0.f);
	sf::Vector2f  backToMainMenuButtonButtonContentCorrectionPos(-10.f, 0.f);
	backTomainMenuButton->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "BACK TO MAIN MENU", backToMainMenuButtonPos, backToMainMenuButtonButtonContentCorrectionPos)));
	backTomainMenuButton->get()->contentList.back()->setFontSize(28);
	backTomainMenuButton->get()->contentList.back()->setFontColor(sf::Color::White);
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
	buttonList.push_back(button(new IntefaceToggleButton(*mapIt->get(), buttonPosition + buttonMargin * 2.f)));
	sf::Texture *temp3 = new sf::Texture;
	temp3->loadFromFile(icon::ICON_BUTTON_MAP);
	buttonList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp3, buttonList.back()->getPos())));

	//SKILL BUTTON
	buttonPosition.y = buttonPosition.y + buttonList.back()->getSizes().y ;
	buttonList.push_back(button(new IntefaceToggleButton(*skillDescriptionWindowIt->get(), buttonPosition + buttonMargin * 3.f)));
	sf::Texture *temp4 = new sf::Texture;
	temp4->loadFromFile(icon::ICON_BUTTON_SKILLS);
	buttonList.back().get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, temp4, buttonList.back()->getPos())));
}


void InterfaceEngine_t::setCamera() {

	float _x = level.mainHero->get()->getPosOfCenter().x;
	float _y = level.mainHero->get()->getPosOfCenter().y;


	//EDIT THIS FOR CAMERA CONTROLL
	float leftBorder = static_cast<float>(window->getSize().x) / 2;
	float topBorder = static_cast<float>(window->getSize().y) / 2;

	float rightBorder = level.map.getSize().x - (static_cast<float>(window->getSize().x) / 2);
	float bottomBorder = level.map.getSize().y - (static_cast<float>(window->getSize().y) / 2);

	float error = 5.0f;

	if (_x < leftBorder) {
		_x = leftBorder;
	}
	else if (_x > rightBorder) {
		_x = rightBorder;
	}

	if (_y > bottomBorder) {
		_y = bottomBorder;
	}
	else if (_y < topBorder) {
		_y = topBorder;
	}

	view->setCenter(_x, _y);
}

//SKILL DESCRIPTION INTERFACE
void InterfaceEngine_t::createDescriptionMenu() {
	size_t skillsAmount = 10;
	sf::Vector2f windowPosition(STD_BUTTON_SIZE.x + interface::STD_WINDOW_MARGIN_SIZE.x, window->getSize().y / 2.f);
	sf::Vector2f windowSize((icon::ICON_DESC_WIDTH + interface::STD_BORDER_SIZE.x) * 9.f, (skillsAmount + 1) * (icon::ICON_DESC_HEIGHT + interface::STD_BORDER_SIZE.y * 2));

	windowsList.push_back(window_t(new InterfaceWindow_t(window,windowPosition,windowSize)));
	skillDescriptionWindowIt = windowsList.end();
	--skillDescriptionWindowIt;

	skillDescriptionWindowIt->get()->setTitle("SKILL DESCRIPTION");
	skillDescriptionWindowIt->get()->setBgColor(sf::Color::Color(50, 50, 50, 120));
	skillDescriptionWindowIt->get()->setBorderColor(sf::Color::Color(238, 238, 238, 120));
	sf::Vector2f contentPos(0.f, 0.f);
	contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;

	using namespace icon;
	int i = 1; //content string number
	contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT/2) + interface::STD_BORDER_SIZE.x;

	sf::Texture *EARTH_ICON = new sf::Texture; EARTH_ICON->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
	sf::Texture *FIRE_ICON = new sf::Texture; FIRE_ICON->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);
	sf::Texture *WIND_ICON= new sf::Texture; WIND_ICON->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);
	
	contentPos.x += DESC_ICON_ELEMENT_SIZE*2;
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON, skillDescriptionWindowIt->get()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window,"Num1" , windowsList.back()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

	contentPos.x += DESC_ICON_ELEMENT_SIZE*2;
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON, skillDescriptionWindowIt->get()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "Num2", windowsList.back()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

	contentPos.x += DESC_ICON_ELEMENT_SIZE *2;
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON, skillDescriptionWindowIt->get()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "Num3", windowsList.back()->getPos(), contentPos)));
	skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);


		//111
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *HEAL = new sf::Texture;
		HEAL->loadFromFile(ICON_HEAL_111);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, HEAL, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		
		sf::Texture *EARTH_ICON1 = new sf::Texture; EARTH_ICON1->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON1, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x3", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//112
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *BANG_BALL= new sf::Texture;
		BANG_BALL->loadFromFile(ICON_BANG_112);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, BANG_BALL, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		
		sf::Texture *EARTH_ICON2 = new sf::Texture; EARTH_ICON2->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *FIRE_ICON2 = new sf::Texture; FIRE_ICON2->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);
		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON2, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);
		
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON2, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//113
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *STONE= new sf::Texture;
		STONE->loadFromFile(ICON_STONE_113);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, STONE, skillDescriptionWindowIt->get()->getPos(), contentPos)));


		sf::Texture *EARTH_ICON3 = new sf::Texture; EARTH_ICON3->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *WIND_ICON3 = new sf::Texture; WIND_ICON3->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);
		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON3, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON3, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);
		//123
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *COMBO = new sf::Texture;
		COMBO->loadFromFile(ICON_COMBO_123);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, COMBO, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *EARTH_ICON4 = new sf::Texture; EARTH_ICON4->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *FIRE_ICON4 = new sf::Texture; FIRE_ICON4->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);
		sf::Texture *WIND_ICON4 = new sf::Texture; WIND_ICON4->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON4, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON4, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON4, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//221
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *FIRE_BREATH = new sf::Texture;
		FIRE_BREATH->loadFromFile(ICON_FIRE_BREATH_221);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_BREATH, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *EARTH_ICON5 = new sf::Texture; EARTH_ICON5->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *FIRE_ICON5= new sf::Texture; FIRE_ICON5->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE*2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON5, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON5, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

	

		//222
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *POWER_BUFF = new sf::Texture;
		POWER_BUFF->loadFromFile(ICON_POWER_BUFF_222);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, POWER_BUFF, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *FIRE_ICON6 = new sf::Texture; FIRE_ICON6->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON6, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x3", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//223
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *FIRE_BALL = new sf::Texture;
		FIRE_BALL->loadFromFile(ICON_FIRE_BALL_223);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_BALL, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *FIRE_ICON7 = new sf::Texture; FIRE_ICON7->loadFromFile(DESC_ICON_ELEMENT_FIRE_FILE);
		sf::Texture *WIND_ICON7 = new sf::Texture; WIND_ICON7->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON7, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON7, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//331
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *SMALL_EARTH_BALL = new sf::Texture;
		SMALL_EARTH_BALL->loadFromFile(ICON_SMALL_EARTH_BALLS_331);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, SMALL_EARTH_BALL, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *EARTH_ICON8 = new sf::Texture; EARTH_ICON8->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *WIND_ICON8 = new sf::Texture; WIND_ICON8->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON8, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, EARTH_ICON8, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);


		//332
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *FIRE_LIGHTING = new sf::Texture;
		FIRE_LIGHTING->loadFromFile(ICON_FIRE_LIGHTING_332);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_LIGHTING, skillDescriptionWindowIt->get()->getPos(), contentPos)));

		sf::Texture *FIRE_ICON9 = new sf::Texture; FIRE_ICON9->loadFromFile(DESC_ICON_ELEMENT_EARTH_FILE);
		sf::Texture *WIND_ICON9 = new sf::Texture; WIND_ICON9->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON9, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x2", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, FIRE_ICON9, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x1", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);

		//333
		contentPos.x = textSettings::STD_FONT_SIZE + interface::STD_BORDER_SIZE.x;
		sf::Texture *SPEED_BUFF = new sf::Texture;
		SPEED_BUFF->loadFromFile(ICON_SPEED_BUFF_333);
		++i;
		contentPos.y = static_cast<float>((i) * ICON_DESC_HEIGHT) + interface::STD_BORDER_SIZE.x;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, SPEED_BUFF, skillDescriptionWindowIt->get()->getPos(), contentPos)));


		sf::Texture *WIND_ICON10 = new sf::Texture; WIND_ICON10->loadFromFile(DESC_ICON_ELEMENT_WIND_FILE);

		contentPos.x += DESC_ICON_ELEMENT_SIZE * 2;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceSpriteContent_t(window, WIND_ICON10, skillDescriptionWindowIt->get()->getPos(), contentPos)));
		contentPos.x += DESC_ICON_ELEMENT_SIZE;
		skillDescriptionWindowIt->get()->contentList.push_back(content(new InterfaceTextContent_t(window, "x3", windowsList.back()->getPos(), contentPos)));
		skillDescriptionWindowIt->get()->contentList.back()->setFontSize(18);
	
}
