#include "game_t.h"



game_t::game_t(sf::RenderWindow *_window):level("level0"),game(_window, level),interface(_window, level)
{
	window = _window;
}


game_t::~game_t()
{
}


void game_t::start() {
	using namespace sf;

	while (window->isOpen()) {
		Event event;
		float timer = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		game.setSpeed(timer);

		while (window->pollEvent(event)) {

			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) {
				window->close();
			}
		}

		game.keyController(event);

		game.update();
		interface.update();
		window->clear();
		game.draw();
		interface.draw();

		window->display();
	}
}