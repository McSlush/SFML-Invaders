#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

enum StateChange {
	NO_CHANGE,
	MENU,
	GAME,
	GAME_OVER
};

class State : public sf::Drawable {
public:
	State() {};
	virtual ~State() {};
	virtual void leftClick(sf::Vector2f mouseCooridinates) = 0;
	virtual StateChange update(float curTime, sf::Vector2f mouseCoordinates) = 0;
};