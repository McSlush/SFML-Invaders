#include "GameLoop.h"
#include "Game.h"
#include "GameOver.h"



GameLoop::GameLoop() : window(sf::VideoMode(WIDTH, HEIGHT), "invaders")
{
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
}


GameLoop::~GameLoop()
{
	delete curState;
}

void GameLoop::run() {

	curState = new Menu();
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}

}


void GameLoop::processEvents() {
	mouseCooridinates = sf::Mouse::getPosition(window);
	while (window.pollEvent(event))
	{
		//Close window
		if (event.type == sf::Event::Closed ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		//shoot if right click
		else if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				curState->leftClick((sf::Vector2f) mouseCooridinates);
			}
		}
	}
}

void GameLoop::update() {

	curTime = clock.restart().asSeconds();
	StateChange status = curState->update(curTime, (sf::Vector2f)mouseCooridinates);

	//Change game status from menu, game, game over.
	if (status == StateChange::MENU) {
		delete curState;
		curState = new Menu();
	}
	else if (status == StateChange::GAME) {
		delete curState;
		curState = new Game();
	}
	else if (status == StateChange::GAME_OVER) {
		delete curState;
		curState = new GameOver();
	}
}

void GameLoop::render() {
	window.clear();
	window.draw(*curState);
	window.display();
}