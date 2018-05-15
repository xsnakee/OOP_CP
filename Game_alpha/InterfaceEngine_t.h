#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <map>
#include <iterator>
#include <memory>
#include "Level_t.h"
#include "InterfaceWindow_t.h"
#include "InterfaceButton.h"
#include "InterfaceBar.h"
#include "cursor_t.h"

typedef std::unique_ptr<InterfaceBar> bar_t;
typedef std::unique_ptr<InterfaceWindow_t> window_t;
typedef std::unique_ptr<InterfaceButton> button;

class InterfaceEngine_t
{
	sf::RenderWindow *window;
	Level_t &level;
	std::unique_ptr<sf::View> view;
	//Iterators
	std::list<window_t>::iterator elemIt;
	std::list<window_t>::iterator missionWindowIt;
	std::list<window_t>::iterator gameStatsWindowIt;
	std::list<window_t>::iterator mapIt;
	std::list<window_t>::iterator skillDescriptionWindowIt;


	void drawCursor();
	void setCamera();
public:

	std::map<std::string, std::list<button>::iterator> buttonsMap;

	std::list<button>::iterator restartButton;
	std::list<button>::iterator backTomainMenuButton;
	std::list<window_t>::iterator pausedMenuIt;

	std::unique_ptr<cursor_t> cursor;
	//LISTS
	std::list<bar_t> barsList;
	std::list<window_t> windowsList;
	std::list<button> buttonList;


	InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~InterfaceEngine_t();

	void update();
	void draw();

	void generateHPbars();
	void setObservedBards();
	void createSkillGeneratorIterface();
	void createJournalWindow();
	void createGameStatsWindow();
	void createMapWindow();
	void createInterfaceButtons();
	void createPausedMenu();
	void createDescriptionMenu();
	
	void updateGenerator();
	void updateMissionJournal();
	void updateGameStats();
	void updateMapWindow();


	bool toggleMenu();
};

