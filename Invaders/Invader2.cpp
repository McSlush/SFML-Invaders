#include "Invader2.h"

Invader2::Invader2() {
	this->imgMgr = imgMgr;
	this->health = 20;
	this->dmg = 7;
	this->ySpeed = 150;
	this->xSpeed = 200;
	this->totTime = 0;
}

Invader2::Invader2(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->health = 20;
	this->dmg = 7;
	this->ySpeed = 150;
	this->xSpeed = 200;
	this->totTime = 0;
	initSprite();
}

Invader2::~Invader2() { }

void Invader2::update(float curTime) {
	//this->xSpeed = rand() % 500 + (-250);
	this->curTime = curTime;
	//invaderSprite.move(xSpeed * curTime, ySpeed * curTime);
	//moveTarget(curTime);
	//this->xPos = xSpeed * curTime;
	//this->yPos = ySpeed * curTime;
	moveTarget();
	collisionDetection();
}

void Invader2::collisionDetection() {
	bottom = invaderSprite.getPosition().y + invaderSprite.getGlobalBounds().width;
	left = invaderSprite.getPosition().x;
	right = invaderSprite.getPosition().x + invaderSprite.getGlobalBounds().width;
	top = invaderSprite.getPosition().y;
}

bool Invader2::collisionBullet(Bullet* b) const {
	//check when and how bullets are removed on collision
	if (right < b->left || left > b->right ||
		top > b->bottom || bottom < b->top) {
		return false;
	}
	//hit!
	return true;
}

bool Invader2::collisionCar(Car* c) const {
	if (right < c->left || left > c->right ||
		top > c->bottom || bottom < c->top) {
		return false;
	}
	//hit!
	return true;
}

void Invader2::moveTarget() {
	totTime += curTime;
	//move right for 1 sec
	if (totTime < 1)
		invaderSprite.move(xSpeed * this->curTime, ySpeed * curTime);
	//move left for once sec
	else if (totTime < 2)
		invaderSprite.move(-xSpeed * this->curTime, ySpeed * curTime);
	else
		totTime = 0;
}

void Invader2::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(invaderSprite);
}

void Invader2::initSprite() {
	int rands = rand() % 400 + 1;
	if (!invaderTexture.loadFromImage(imgMgr.get_image("../img/invaders.png"))) {
		cout << "Failed to load Invader2 image";
	}
	invaderTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(120, 90);
	invaderSprite.setTexture(invaderTexture);
	invaderSprite.setTextureRect(sf::IntRect(125, 0, spriteFrameSize.x, spriteFrameSize.y));
	invaderSprite.setScale(0.5f, 0.5f);
	invaderSprite.setPosition((float)rands, 0);
}
