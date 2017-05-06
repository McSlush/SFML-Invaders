#pragma once
#include "SFML\Graphics.hpp"
#include "Menu.h"

#define WIDTH 600
#define HEIGHT 600

class GameLoop
{
public:
	GameLoop();
	~GameLoop();
	void run();

private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
	sf::Vector2i mouseCooridinates;
	sf::Clock clock;
	sf::Event event;
	State* curState;
	float lastTime = 0;
	float curTime = 0;
};