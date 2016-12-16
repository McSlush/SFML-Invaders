#include "Car.h"
#include "Bullet.h"
#include <iostream>

using namespace std;

Car::Car() {}

Car::Car(image_manager& imgMgr) {
	this->yPos = 400;
	this->xPos = 10;
	this->xSpeed = 300;
	this->dmg = 50;
	this->imgMgr = imgMgr;
	initSprite();
}

Car::~Car() {

}

void Car::moveCar(float curTime, int direction) {
	//Move to the right
	if (direction == 1 && this->xPos < 520) {
		this->xPos += xSpeed * curTime;
	}
	//Move to the left
	else if (direction == 2 && this->xPos > 0) {
		this->xPos -= xSpeed * curTime;
	}
}

int Car::getDmg() {
	return this->dmg;
}

void Car::collisionDetection() {
	bottom = carSprite.getPosition().y + carSprite.getGlobalBounds().width;
	left = carSprite.getPosition().x;
	right = carSprite.getPosition().x + carSprite.getGlobalBounds().width;
	top = carSprite.getPosition().y;
}

sf::FloatRect Car::getGlobalBounds() const {
	return carSprite.getGlobalBounds(); 
}

void Car::initSprite() {
	if (!carTexture.loadFromImage(imgMgr.get_image("../img/sonic.png"))) {
		cout << "Failed to load Car image";
	}
	carTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(80, 90);
	carSprite.setTexture(carTexture);
	carSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	carSprite.setScale(1.0f, 1.0f);
	carSprite.setPosition(0, -250);
}

void Car::update(float curTime) {
	carSprite.setPosition(xPos, yPos);
	collisionDetection();
}

void Car::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(carSprite);
}
