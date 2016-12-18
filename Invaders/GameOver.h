#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "State.h"
#include "image_manager.h"
#include <iostream>

using namespace std;

class GameOver : public State {
private:
	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;

public:
	GameOver();
	~GameOver();

	virtual void initSprite();
	void leftClick(sf::Vector2f mouseCooridinates);
	virtual StateChange update(float curTime, sf::Vector2f mouseCoordinates);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};