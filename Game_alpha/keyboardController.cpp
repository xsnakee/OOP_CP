#include "keyboardController.h"
#include <iostream>


keyboardController::keyboardController(sf::Clock *_clock)
{
	key = sf::Keyboard::Key::Unknown;
	clock = _clock;
	controllerMode = 0;
	startTime = clock->getElapsedTime().asMilliseconds();
	keysCD = 200;
}


keyboardController::~keyboardController()
{
}

bool keyboardController::checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

//playercontroller 

PlayerController::PlayerController(sf::Clock *_clock, character_t *mainHero) :keyboardController(_clock)
{
	key = sf::Keyboard::Key::Unknown;
	character = mainHero;
	controllerMode = 1;
}


PlayerController::~PlayerController()
{
}

void PlayerController::checkCharacterStateAndChangeDefault() {
	if ((character->getState()->getStateNum() != 3)) {
		character->changeState(new CharacterPlayerControll_t(character));
		std::cout << 3 << std::endl;
	}
}

void PlayerController::eventHandler(sf::Event &event) {

	using namespace sf;



	if (Keyboard::isKeyPressed(Keyboard::W)) {
		character->setdY(-character->getStats().speed);
		checkCharacterStateAndChangeDefault();
	} 
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		character->setdX(-character->getStats().speed);
		checkCharacterStateAndChangeDefault();

	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		character->setdY(character->getStats().speed);
		checkCharacterStateAndChangeDefault();


	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		character->setdX(character->getStats().speed);
		checkCharacterStateAndChangeDefault();
	}

	if (!checkTimer(clock, startTime, keysCD)) {
		startTime = clock->getElapsedTime().asMilliseconds();

		if (Keyboard::isKeyPressed(Keyboard::E)) {

			character->setPosX(1000.0f);
			character->setPosY(1000.0f);
			checkCharacterStateAndChangeDefault();
		}


		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			character->addElement(elements:: WIND);
			checkCharacterStateAndChangeDefault();

		}
		if (Keyboard::isKeyPressed(Keyboard::Num2)) {

			character->addElement(elements::FIRE);
			checkCharacterStateAndChangeDefault();
		}

		if (Keyboard::isKeyPressed(Keyboard::Num3)) {

			character->addElement(elements:: EARTH);
			checkCharacterStateAndChangeDefault();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			character->changeState(new CharacterPlayerCast_t(character));
			std::cout << 4 << std::endl;
			character->getTimers().updateCastCD();
		}
	}
	

	if (Mouse::isButtonPressed(Mouse::Left)) {
		character->attack();
		std::cout << character->getElemStatus() << std::endl;
		checkCharacterStateAndChangeDefault();
	}	
}