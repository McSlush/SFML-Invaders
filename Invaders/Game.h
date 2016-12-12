#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#include "image_manager.h"
#include "InvaderManager.h"
#include "Invader.h"
#include "SpriteNames.h"
#include "GameField.h"
#include "Player.h"
#include "Bullet.h"
#include "Image.h"

class Game : public sf::Drawable {
private:
	float gameTime;
	//GameField* gameField;
	image_manager imgMgr;
	SpriteNames spriteNames;
	vector<string> names;
	//InvaderManager* invMgr;
	unique_ptr<Player> player;
	vector<shared_ptr<Bullet>> bullets;
	//unique_ptr<Bullet> bullet;
	vector<shared_ptr<Invader>> invaders;
	unique_ptr<GameField> gameField;
	//unique_ptr<Invader> invader;

	void collisionDetection();
	void updateBullets(float td);
	void updateInvaders(float td);

public:
	Game();
	~Game();

	virtual void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void shoot(sf::Vector2f mouseCooridinates); 
	void changeWeapon(int weaponChoice);
	void moveCar(int direction);

	//vector<Bullet*> getBullets() { return bullets; }
	void Game::update(float td, sf::Vector2i mouseCoordinates);
};