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
	this->leftBound = false;
	this->rightBound = false;
	initSprite();
}

Invader2::~Invader2() { }

void Invader2::update(float curTime) {
	this->curTime = curTime;
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
	//TODO check the value up. get it from main somehow... base on window size
	float xBoundLeft = 20;
	float xBoundRight = 520;
	float spriteX = invaderSprite.getPosition().x;
	float spriteY = invaderSprite.getPosition().y;

	//if target is to far left of the screen
	if (spriteX < xBoundLeft) {
		leftBound = true;
	}
	//if target is to far left of the screen
	else if (spriteX > xBoundRight) {
		rightBound = true;
	}

	////if target is to far to one side of the screen
	if (rightBound) {
		invaderSprite.move(-xSpeed * this->curTime, ySpeed * curTime);
		//Make the target move the other way, once it manages to jump out of x == 460
		if (spriteX < 460) {
			rightBound = false;
		}
	}
	else if (leftBound) {
		invaderSprite.move(xSpeed * this->curTime, ySpeed * curTime);
		//Make the target move the other way, once it manages to jump out of x == 60
		if (spriteX > 60) {
			leftBound = false;
		}
	}

	if (!rightBound && !leftBound) {
		//move right 
		if (totTime < 1)
			invaderSprite.move(-xSpeed * this->curTime, ySpeed * curTime);
		//move left 
		else if (totTime < 2)
			invaderSprite.move(xSpeed * this->curTime, ySpeed * curTime);
		else
			totTime = 0;
	}
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
