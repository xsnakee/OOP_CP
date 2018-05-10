#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <iterator>
#include <memory>
#include "Level_t.h"
#include "InterfaceWindow_t.h"
#include "InterfaceBar.h"
#include "cursor_t.h"

typedef std::unique_ptr<InterfaceBar> bar_t;
typedef std::unique_ptr<InterfaceWindow_t> window_t;

class InterfaceEngine_t
{
	sf::RenderWindow *window;
	Level_t &level;
	//Iterators
	std::list<window_t>::iterator elemIt;
	std::list<window_t>::iterator missionWindowIt;

	std::unique_ptr<cursor_t> cursor;

	void drawCursor();
public:
	//LISTS
	std::list<bar_t> barsList;
	std::list<window_t> windowsList;


	InterfaceEngine_t(sf::RenderWindow *_window, Level_t &_level);
	~InterfaceEngine_t();

	void update();
	void draw();

	void generateHPbars();
	void setObservedBards();
	void createSkillGeneratorIterface();
	void createJournalWindow();
	void createGameStatsWindow();

	void updateGenerator();
	void updateMissionJournal();
};

