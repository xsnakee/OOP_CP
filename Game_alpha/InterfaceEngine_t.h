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
	std::list<window_t>::iterator winWindowIt;

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
	void createWinScreen();
	
	void updateGenerator();
	void updateMissionJournal();
	void updateGameStats();
	void updateMapWindow();


	bool pause();
	bool hideButtons();
};

namespace icon {
	//ICONS
	//const std::string ICON_ELEMENT__FILE = "img/icons/.png";
	const std::string ICON_ELEMENT_FIRE_FILE = "img/icons/icon_element_fire.png";
	const std::string ICON_ELEMENT_WIND_FILE = "img/icons/icon_element_wind.png";
	const std::string ICON_ELEMENT_EARTH_FILE = "img/icons/icon_element_earth.png";
	//SKILLS ICONS
	const std::string ICON_SKILL_BANG_BALL_FILE = "img/icons/icon_skill_bang_ball.png";
	const std::string ICON_SKILL_COMBO_BALL_FILE = "img/icons/icon_skill_combo_ball.png";
	const std::string ICON_SKILL_sWORD_ATTACK_FILE = "img/icons/icon_skill_common_attack.png";
	const std::string ICON_SKILL_EARTH_BALL_FILE = "img/icons/icon_skill_earth_ball.png";
	const std::string ICON_SKILL_FIRE_BALL_FILE = "img/icons/icon_skill_fire_ball.png";
	const std::string ICON_SKILL_HEAL_BALL_FILE = "img/icons/icon_skill_heal_ball.png";
	const std::string ICON_SKILL_LAVA_POOL_FILE = "img/icons/icon_skill_lava_pool.png";
	const std::string ICON_SKILL_POWER_UP_FILE = "img/icons/icon_skill_powerUp.png";
	const std::string ICON_SKILL_RUSH_FILE = "img/icons/icon_skill_rush.png";
	const std::string ICON_SKILL_SMALL_EARTH_BALLS_FILE = "img/icons/icon_skill_small_earth_balls.png";
	const std::string ICON_SKILL_SMALL_FIRE_BALLS_FILE = "img/icons/icon_skill_small_fire_balls.png";
	const std::string ICON_SKILL__FILE = "img/icons/.png";

	//BUTTONS ICONS
	const std::string ICON_BUTTON_JOURNAL = "img/icons/icon_button_journal.png";
	const std::string ICON_BUTTON_GAME_STATISTIC = "img/icons/icon_button_game_statistic.png";
	const std::string ICON_BUTTON_SKILLS = "img/icons/icon_button_skills.png";
	const std::string ICON_BUTTON_MAP = "img/icons/icon_button_map.png";

	//SKILL DESCRIPTION ICONS
	const int ICON_DESC_HEIGHT = 32;
	const int ICON_DESC_WIDTH = 32;

	const std::string DESC_ICON_ELEMENT_FIRE_FILE = "img/icons/description_icons/icon_element_fire.png";
	const std::string DESC_ICON_ELEMENT_WIND_FILE = "img/icons/description_icons/icon_element_wind.png";
	const std::string DESC_ICON_ELEMENT_EARTH_FILE = "img/icons/description_icons/icon_element_earth.png";
	const int DESC_ICON_ELEMENT_SIZE = 32;

	const std::string ICON_HEAL_111 = "img/icons/description_icons/111.png";
	const std::string ICON_BANG_112 = "img/icons/description_icons/112.png";
	const std::string ICON_STONE_113 = "img/icons/description_icons/113.png";
	const std::string ICON_COMBO_123 = "img/icons/description_icons/123.png";
	const std::string ICON_FIRE_BREATH_221 = "img/icons/description_icons/221.png";
	const std::string ICON_POWER_BUFF_222 = "img/icons/description_icons/222.png";
	const std::string ICON_FIRE_BALL_223 = "img/icons/description_icons/223.png";
	const std::string ICON_SMALL_EARTH_BALLS_331 = "img/icons/description_icons/331.png";
	const std::string ICON_FIRE_LIGHTING_332 = "img/icons/description_icons/332.png";
	const std::string ICON_SPEED_BUFF_333 = "img/icons/description_icons/333.png";
}

