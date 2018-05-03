#include "keyboardController.h"



keyboardController::keyboardController(sf::Clock *_clock)
{
	key = sf::Keyboard::Key::Unknown;
	clock = _clock;
}


keyboardController::~keyboardController()
{
}

void keyboardController::takeKey(sf::Event &event) {
	if (event.type == sf::Event::EventType::KeyPressed) {
		key = event.key.code;
	}
	else {
		key = sf::Keyboard::Key::Unknown;
	}
}



//*playercontroller 

PlayerController::PlayerController(sf::Clock *_clock, player_t *mainHero):keyboardController(_clock)
{
	key = sf::Keyboard::Key::Unknown;
	character = mainHero;
}


PlayerController::~PlayerController()
{
}