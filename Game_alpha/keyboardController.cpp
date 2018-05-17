#include "keyboardController.h"


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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				character->attack();
				checkCharacterStateAndChangeDefault();
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Escape) {
					checkCharacterStateAndChangeDefault();
					game->interfaceEngine->pause();
					if (game->interfaceEngine->pausedMenuIt->get()->getDisplayState()) {
						game->setGameStatus(game::PAUSED);

					}
					else {
						game->setGameStatus(game::PLAY);
					}				
			}
			if (game->getStatus() != game::PAUSED) {
				switch (event.key.code) {
				case Keyboard::E: {
					game->setGameStatus(game::WIN);
					checkCharacterStateAndChangeDefault();
					break;
				}
				case Keyboard::Num1: {
					character->addElement(elements::EARTH);
					checkCharacterStateAndChangeDefault();
					break;
				}
				case Keyboard::Num2: {
					character->addElement(elements::FIRE);
					checkCharacterStateAndChangeDefault();
					break;
				}
				case Keyboard::Num3: {
					character->addElement(elements::WIND);
					checkCharacterStateAndChangeDefault();
					break;
				}
				case Keyboard::J: {
					game->interfaceEngine->buttonsMap[buttons::JOURNAL_KEY_NAME]->get()->action();
					break;
				}
				case Keyboard::T: {
					game->interfaceEngine->buttonsMap[buttons::GAME_STATS_KEY_NAME]->get()->action();
					break;
				}
				case Keyboard::M: {
					game->interfaceEngine->buttonsMap[buttons::MAP_KEY_NAME]->get()->action();
					break;
				}
				case Keyboard::K: {
					game->interfaceEngine->buttonsMap[buttons::SKILL_KEY_NAME]->get()->action();
					break;
				}

				}
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (character->getState()->getStateNum() != 4) {

				character->getTimer().updateCastCD();
				character->changeState(new CharacterPlayerCast_t(*character));
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


//GET

	character_t * keyboardController::getPlayerCharPtr()const {
		return character;
	}
