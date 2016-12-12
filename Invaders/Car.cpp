#include "Car.h"
#include "Bullet.h"
#include <iostream>

using namespace std;

Car::Car() {}

Car::Car(image_manager& imgMgr) {
	this->y = 400;
	this->x = 50;
	this->xSpeed = 1000;
	this->imgMgr = imgMgr;
	initSprite(imgMgr);
}

Car::~Car() {

}

void Car::moveCar(int direction) {
	carSprite.move(xSpeed, 0);
}


void Car::initSprite(image_manager& imgMgr) {
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

//TODO fix collision
void collisionDetection() {

}

bool collision(Bullet& bullet) {
	return true;
}

void Car::update() {
	carSprite.setPosition(x, y);
}

void Car::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(carSprite);
}
