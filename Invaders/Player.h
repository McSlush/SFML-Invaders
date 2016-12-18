#pragma once

#include <memory>
#include "image_manager.h"
#include <SFML\Graphics.hpp>
#include "Aim.h"
#include "Car.h"
#include "Weapon.h"
#include "Gun.h"
#include "Shotgun.h"
#include "BulletManager.h"

class Player : public sf::Drawable {
private:
	int health;
	int score;
	float curTime;
	bool doGun;
	image_manager imgMgr;
	Gun* gun;
	Shotgun* shotgun;
	Car* car;
	BulletManager* bulMgr;
	unique_ptr<Aim> aim;

public:
	Player() {}
	Player(image_manager& imgMgr);
	~Player();

	void Player::drawCar(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float curTime, sf::Vector2f mouseCooridinates);
	
	Car* getCar();
	int getDamage();
	void shoot(sf::Vector2f mouseCooridinates);
	int adjustHealth(int adjustHp);
	int adjustScore(int adjustScore);
	void changeWeapon(int weaponChoice);
	void moveCar(int direction);
	
	void removeBullet(int index);
	Bullet* getBullet(int index);
	int getBulletCounter();

	int getHealt() { return health; }
	void setHealth(int health) { this->health = health; }
};