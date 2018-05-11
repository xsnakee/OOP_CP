#include "keyboardController.h"
#include <iostream>


keyboardController::keyboardController()
{
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
	character = mainHero;
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
	else if (event.type == Event::KeyReleased){

		switch (event.key.code) {
		case Keyboard::Space: {
			character->getTimer().updateCastCD();
			character->changeState(new CharacterPlayerCast_t(character));
			break;
		}
		case Keyboard::E : {
			character->setPosX(3000.0f);
			character->setPosY(200.0f);
			checkCharacterStateAndChangeDefault();
			break;
		}
		case Keyboard::Num1: {
			character->addElement(elements::WIND);
			checkCharacterStateAndChangeDefault();
			break;
		}
		case Keyboard::Num2: {
			character->addElement(elements::FIRE);
			checkCharacterStateAndChangeDefault();
			break;
		}
		case Keyboard::Num3 : {
			character->addElement(elements::EARTH);
			checkCharacterStateAndChangeDefault();
			break;
		}
		}
	}
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

		



}