#include "Player.h"

//TODO: gun, bullet ... here


Player::Player(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->health = 10;
	this->score = 0;
	this->aim = make_unique<Aim>(imgMgr);
	this->car = new Car(imgMgr);
	this->weapon = new Gun(imgMgr);
	this->bulMgr = new BulletManager(imgMgr);
}

Player::~Player() {
	delete car;
	delete weapon;
	delete bulMgr;
}

Car* Player::getCar() {
	return this->car;
}

void Player::moveCar(int direction) {
	car->moveCar(curTime, direction);
}

void Player::changeWeapon(int weaponChoice)
{
	switch (weaponChoice)
	{
	case 1:
		delete weapon;
		this->weapon = new Gun(imgMgr);
		break;
	case 2:
		delete weapon;
		this->weapon = new Shotgun(imgMgr);
		break;
	default:
		break;
	}
}

int Player::getDamage() {
	return this->weapon->getDmg();
}

void Player::shoot(sf::Vector2f mouseCoordinates) {
	if (this->weapon == dynamic_cast<Gun*>(this->weapon)) {
		if (bulMgr->getBulletCounter() < 7) {
			bulMgr->addBullet(new Bullet(imgMgr, mouseCoordinates.x));
		}
	}
	else if (this->weapon == dynamic_cast<Shotgun*>(this->weapon)) {
		if (bulMgr->getBulletCounter() < 8) {
			bulMgr->addBullet(new Bullet(imgMgr, mouseCoordinates.x + 10));
			bulMgr->addBullet(new Bullet(imgMgr, mouseCoordinates.x + 0));
			bulMgr->addBullet(new Bullet(imgMgr, mouseCoordinates.x - 15));
			bulMgr->addBullet(new Bullet(imgMgr, mouseCoordinates.x - 30));
		}
	}
}

int Player::adjustHealth(int adjustHp) { 
	health += adjustHp; 
	return health;
}

int Player::adjustScore(int adjustScore) {
	score += adjustScore;
	return score;
}

void Player::removeBullet(int index) {
	bulMgr->removeBullet(index);
}

Bullet* Player::getBullet(int index) {
	return bulMgr->getBullet(index);
}

void Player::update(float curTime, sf::Vector2i mouseCoordinates) {
	this->curTime = curTime;
	aim->update(mouseCoordinates);
	car->update(this->curTime);
	weapon->update(mouseCoordinates.x);
	bulMgr->update(this->curTime, bulMgr);
}

void Player::drawCar(sf::RenderTarget& target, sf::RenderStates states) const {
	car->draw(target, states);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	aim->draw(target, states);
	bulMgr->draw(target, states);
	weapon->draw(target, states);
}

