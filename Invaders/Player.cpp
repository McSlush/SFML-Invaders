#include "Player.h"

//TODO: gun, bullet ... here


Player::Player(image_manager& imgMgr, sf::Vector2i mouseCoordinates) {
	this->imgMgr = imgMgr;
	this->health = 10;
	aim = make_unique<Aim>(imgMgr);
	this->car = new Car(imgMgr);
	weapon = make_unique<Gun>(imgMgr);
}

Player::~Player() {
	delete car;
}

void Player::moveCar(int direction) {
	//TODO make carclass handle this
	//Move to the right
	if (direction == 1 && car->x < 520) {
		car->x += 3;
	}
	//Move to the left
	else if (direction == 2 && car->x > 0) {
		car->x -= 3;
	}
}

void Player::changeWeapon(int weaponChoice)
{
	switch (weaponChoice)
	{
	case 1:
		weapon = make_unique<Gun>(imgMgr);
		break;
	case 2:
		weapon = make_unique<Shotgun>(imgMgr);
		break;
	default:
		break;
	}
}

void Player::update(float td, sf::Vector2i mouseCoordinates) {
	//gameTime = td;
	aim->update(mouseCoordinates);
	car->update();
	weapon->update(mouseCoordinates);
}

int Player::adjustHealth(int adjustHp) { 
	this->health += adjustHp; 
	return health;
}

void Player::drawCar(sf::RenderTarget& target, sf::RenderStates states) const {
	car->draw(target, states);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//TODO: draw  gun, health, bullet ... here
	//car->draw(target, states);
	aim->draw(target, states);
	weapon->draw(target, states);
}

