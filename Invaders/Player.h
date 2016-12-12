#pragma once

#include <memory>
#include "image_manager.h"
#include <SFML\Graphics.hpp>
#include "Aim.h"
#include "Car.h"
#include "Weapon.h"
#include "Gun.h"
#include "Shotgun.h"

class Player : public sf::Drawable {
private:
	int health;
	image_manager imgMgr;
	Car* car;
	unique_ptr<Aim> aim;
	unique_ptr<Weapon> weapon;

public:
	Player() {}
	Player(image_manager& imgMgr, sf::Vector2i mouseCoordinates);
	~Player();

	void Player::drawCar(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float td, sf::Vector2i mouseCooridinates);

	int adjustHealth(int adjustHp);
	void changeWeapon(int weaponChoice);
	void moveCar(int direction);
	
	int getHealt() { return health; }
	void setHealth(int health) { this->health = health; }
};