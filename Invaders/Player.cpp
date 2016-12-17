#include "Player.h"

Player::Player(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->health = 10;
	this->score = 0;
	this->aim = make_unique<Aim>(imgMgr);
	this->car = new Car(imgMgr);
	this->gun = new Gun(imgMgr);
	this->shotgun = new Shotgun(imgMgr);
	this->bulMgr = new BulletManager(imgMgr);
	this->doGun = true;
}

Player::~Player() {
	delete car;
	delete gun;
	delete shotgun;
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
		doGun = true;
		break;
	case 2:
		doGun = false;
		break;
	default:
		break;
	}
}

int Player::getDamage() {
	if (doGun) {
		return gun->getDmg();
	}
	else {
		return shotgun->getDmg();
	}
}


void Player::shoot(sf::Vector2f mouseCoordinates) {

	if (doGun) {
		gun->shoot(mouseCoordinates, *bulMgr);
	}
	else {
		shotgun->shoot(mouseCoordinates, *bulMgr);
	}
}

int Player::getBulletCounter() {
	return bulMgr->getBulletCounter();
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
	car->update(curTime);
	bulMgr->update(curTime, bulMgr);
	if (doGun)
		gun->update(mouseCoordinates.x, curTime);
	else
		shotgun->update(mouseCoordinates.x, curTime);
}

void Player::drawCar(sf::RenderTarget& target, sf::RenderStates states) const {
	car->draw(target, states);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	aim->draw(target, states);
	bulMgr->draw(target, states);

	if (doGun)
		gun->draw(target, states);
	else
		shotgun->draw(target, states);
}

