 #include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

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
	sf::Clock dt;
	Game game;
	
	while (window.isOpen())
	{
		sf::Event event;
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
					game.shoot((sf::Vector2f) mouseCooridinates);
				}
			}
			//change weapon
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				game.changeWeapon(1);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				game.changeWeapon(2);
			}
		}
		//Move the car
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			 game.moveCar(1);
		 }
		 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			 game.moveCar(2);
		 }

		game.update(dt.restart().asSeconds(), mouseCooridinates);
		
		window.clear();
		window.draw(game);
		
		window.display();
	}

	return 0;
}
