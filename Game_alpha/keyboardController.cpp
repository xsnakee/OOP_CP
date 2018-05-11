#include "keyboardController.h"
#include <iostream>


keyboardController::keyboardController()
{
	key = sf::Keyboard::Key::Unknown;
}


keyboardController::~keyboardController()
{
}

bool keyboardController::checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

//playercontroller 

PlayerController::PlayerController(character_t *mainHero) :keyboardController()
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
	}
}

void PlayerController::eventHandler(sf::Event &event) {

	using namespace sf;
	if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) {
		character->attack();
		checkCharacterStateAndChangeDefault();
	}
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space) {

		character->getTimer().updateCastCD();
		character->changeState(new CharacterPlayerCast_t(character));
	}
	else
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

		if (event.key.code == (Keyboard::E)) {

			character->setPosX(800.0f);
			character->setPosY(800.0f);
			checkCharacterStateAndChangeDefault();
		}


		if (event.key.code == (Keyboard::Num1)) {
			character->addElement(elements::WIND);
			checkCharacterStateAndChangeDefault();

		}
		if (event.key.code == (Keyboard::Num2)) {

			character->addElement(elements::FIRE);
			checkCharacterStateAndChangeDefault();
		}

		if (event.key.code == (Keyboard::Num3)) {

			character->addElement(elements::EARTH);
			checkCharacterStateAndChangeDefault();
		}


		event.key.code = Keyboard::Unknown;

}