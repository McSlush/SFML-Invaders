#include "Bullet.h"

Bullet::Bullet() {};

Bullet::Bullet(image_manager& imgMgr, sf::Vector2f mouseCooridinates) {
	this->imgMgr = imgMgr;
	this->dmg = 10;
	this->y = 525;
	this->ySpeed = -6;
	initSprite(mouseCooridinates);
}

void Bullet::update(float td) {
	gameTime = td;
	bulletSprite.move(0, ySpeed);
	collisionDetection();
}



void Bullet::collisionDetection() {
	bottom = bulletSprite.getPosition().y + bulletSprite.getGlobalBounds().width;
	left = bulletSprite.getPosition().x;
	right = bulletSprite.getPosition().x + bulletSprite.getGlobalBounds().width;
	top = bulletSprite.getPosition().y;
}

void Bullet::initSprite(sf::Vector2f mouseCooridinates) {
	if (!bulletTexture.loadFromImage(this->imgMgr.get_image("../img/bullet.png"))) {
		cout << "Failed to load Bullet img.";
	}
	bulletTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(100, 357);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	bulletSprite.setScale(0.15f, 0.15f);
	bulletSprite.setPosition(mouseCooridinates.x, y);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bulletSprite);
}