#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#include "image_manager.h"
#include "InvaderManager.h"
#include "GameField.h"
#include "Player.h"
#include "Image.h"
#include "BulletManager.h"
#include "State.h"

class Game : public State {
private:
	float curTime, totTime;
	image_manager imgMgr;
	InvaderManager* invMgr;
	BulletManager* bulMgr;
	GameField* gameField;
	Player* player;

	void collisionDetection();
	void updateInvaders();

public:
	Game();
	~Game();

	virtual void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void leftClick(sf::Vector2f mouseCooridinates);
	void changeWeapon(int weaponChoice);
	void moveCar(int direction);

	StateChange update(float curTime, sf::Vector2f mouseCoordinates);
};