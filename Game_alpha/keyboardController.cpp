#include "keyboardController.h"
#include <iostream>


keyboardController::keyboardController(sf::Clock *_clock)
{
	key = sf::Keyboard::Key::Unknown;
	clock = _clock;
	controllerMode = 0;
}


keyboardController::~keyboardController()
{
}

void keyboardController::takeKey(sf::Event &event) {
	if (event.type == sf::Event::EventType::KeyPressed) {
		key = event.key.code;
	}
	else if (event.type == sf::Event::EventType::MouseButtonPressed) {
		key = 55;
	}
	else {
		key = sf::Keyboard::Key::Unknown;
	}
}



//*playercontroller 

PlayerController::PlayerController(sf::Clock *_clock, character_t *mainHero) :keyboardController(_clock)
{
	key = sf::Keyboard::Key::Unknown;
	character = mainHero;
	controllerMode = 1;
}


PlayerController::~PlayerController()
{
}

void PlayerController::setDefaultCharacterState() {
	character->changeState(new CharacterPlayerControll_t(character));
}

void PlayerController::eventHandler() {

	using namespace sf;

	switch (key) {
		default: {
			if ((character->getState()->getStateNum() == 4) && character->checkSkillGenerator() && (character->getTimers().castReady())) {
				character->generateSkillAndClearElemList();
			}
			break;
		}
		case Keyboard::W:{
			character->setdY(-character->getStats().speed);
			setDefaultCharacterState();
			break;
		}
		case Keyboard::A: {
			setDefaultCharacterState();
			character->setdX(-character->getStats().speed);
			break;
		}
		case Keyboard::S: {
			setDefaultCharacterState();
			character->setdY(character->getStats().speed);
			break;
		}
		case Keyboard::D: {
			setDefaultCharacterState();
			character->setdX(character->getStats().speed);
			break;
		}
		case Keyboard::E: {
			setDefaultCharacterState();
			character->setPosX(1000.0f);
			character->setPosY(1000.0f);
			break;
		}
		case Keyboard::Num1 : {
			setDefaultCharacterState();
			character->addElement(elements::FIRE);
			std::cout << 1 << std::endl;
			break;
		}
		case Keyboard::Num2: {
			setDefaultCharacterState();
			character->addElement(elements::EARTH);
			std::cout << 2 << std::endl;
			break;
		}
		case Keyboard::Num3: {
			setDefaultCharacterState();
			character->addElement(elements::WIND);
			std::cout << 3 << std::endl;
			break;
		}
		case Keyboard::Space: {
			setDefaultCharacterState();
			character->changeState(new CharacterPlayerCast_t(character));
			character->getTimers().updateCastCD();
			break;
		}
		//ATACK CONTROLLER
		case 55:{ //Mouse click
		//bulletsList.push_back(std::unique_ptr <bullet_t>(new bullet_t(clock.get(), character.get(), cursor->getPosition())));
		setDefaultCharacterState();
		character->attack();
		break;

		}
	}
	
}