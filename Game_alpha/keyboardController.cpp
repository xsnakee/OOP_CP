#include "keyboardController.h"
#include <iostream>


//keyboardController

keyboardController::keyboardController(character_t *mainHero, game_t *_game) 
{
	character = mainHero;
	game = _game;
}


keyboardController::~keyboardController()
{
}

void keyboardController::checkCharacterStateAndChangeDefault() {
	if ((character->getState()->getStateNum() != 3)) {
		character->changeState(new CharacterPlayerControll_t(*character));
	}
}

void keyboardController::eventHandler(sf::Event &event) {

		using namespace sf;
		if (game->getStatus() != game::PAUSED) {
			//if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				character->attack();
				checkCharacterStateAndChangeDefault();
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Escape) {
					checkCharacterStateAndChangeDefault();
					if (game->interfaceEngine->toggleMenu()) {
						game->setGameStatus(game::PAUSED);
					}
					else {
						game->setGameStatus(game::PLAY);
					}				
			}
			if (game->getStatus() != game::PAUSED) {
				switch (event.key.code) {
				case Keyboard::Space: {
					character->getTimer().updateCastCD();
					character->changeState(new CharacterPlayerCast_t(*character));
					break;
				}
				case Keyboard::E: {
					character->setPosX(3000.0f);
					character->setPosY(200.0f);
					character->setAlive(false);
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
				case Keyboard::Num3: {
					character->addElement(elements::EARTH);
					checkCharacterStateAndChangeDefault();
					break;
				}

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