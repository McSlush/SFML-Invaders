#include "Invader.h"

Invader::Invader() {
	this->health = 10;
	this->dmg = 5;
	this->xSpeed = 7;
	this->imgMgr = imgMgr;
}

Invader::Invader(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->health = 10;
	this->dmg = 5;
	this->ySpeed = 7;
	initSprite();
}

Invader::~Invader() {}

void Invader::update(float td) {
	gameTime = td;
	invaderSprite.move(0, ySpeed);
	collisionDetection();
}

void Invader::collisionDetection() {
	bottom = invaderSprite.getPosition().y + invaderSprite.getGlobalBounds().width;
	left = invaderSprite.getPosition().x;
	right = invaderSprite.getPosition().x + invaderSprite.getGlobalBounds().width;
	top = invaderSprite.getPosition().y;
}

bool Invader::collision(shared_ptr<Bullet> b) const {
	if (right < b->left || left > b->right ||
		top > b->bottom || bottom < b->top) {
		return false;
	}
	//hit!
	return true;
}

void Invader::initSprite() {
	float rands = (float)(rand() % 400 + 1);
	if (!invaderTexture.loadFromImage(imgMgr.get_image("../img/invaders.png"))) {
		cout << "Failed to load Invader image";
	}
	invaderTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(90, 90);
	invaderSprite.setTexture(invaderTexture);
	invaderSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	invaderSprite.setScale(0.5f, 0.5f);
	invaderSprite.setPosition(rands, -10);
}

void Invader::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(invaderSprite);
}