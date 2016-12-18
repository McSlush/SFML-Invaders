 #include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "GameOver.h"

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>  
#include <crtdbg.h> 


/* Nice links
Smart pointers
http://stackoverflow.com/questions/16894400/how-to-declare-stdunique-ptr-and-what-is-the-use-of-it
Image manager
https://github.com/SFML/SFML/wiki/Tutorial:-Image-Manager
*/

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(600, 600), "Invaders");// , sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);

	sf::Vector2i mouseCooridinates;
	sf::Clock clock;
	sf::Event event;

	State* curState = new Menu();

	float lastTime = 0;
	float curTime = 0;
	float fps = 0;

	//Game game;
	
	while (window.isOpen())
	{
		mouseCooridinates = sf::Mouse::getPosition(window);
		StateChange status = curState->update(curTime, (sf::Vector2f)mouseCooridinates);
		curTime = clock.restart().asSeconds();
		lastTime = curTime;
		fps = 1 / curTime;

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

		window.clear();
		window.draw(*curState);
		window.display();
	}

	delete curState;
	return 0;
}
