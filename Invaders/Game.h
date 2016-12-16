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

class Game : public sf::Drawable {
private:
	float curTime, totTime;
	image_manager imgMgr;
	InvaderManager* invMgr;
	BulletManager* bulMgr;
	GameField* gameField;
	Player* player;

	void collisionDetection();
	//TODO needed?
	void updateBullets();
	void updateInvaders();

public:
	Game();
	~Game();

	virtual void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void shoot(sf::Vector2f mouseCooridinates); 
	void changeWeapon(int weaponChoice);
	void moveCar(int direction);

	void Game::update(float curTime, sf::Vector2i mouseCoordinates);
};