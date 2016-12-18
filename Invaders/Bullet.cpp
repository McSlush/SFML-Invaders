#include "Bullet.h"

Bullet::Bullet() {};

Bullet::Bullet(image_manager& imgMgr, float xPos, BulletType bulletType) {
	this->imgMgr = imgMgr;
	this->dmg = 10;
	this->yPos = 525;
	//this->xPos = xPos;
	this->ySpeed = -8;
	this->bulletType = bulletType;
	initSprite(xPos);
}

Bullet::Bullet(const Bullet& orig){
	this->dmg = orig.dmg;
	this->yPos = orig.yPos;
	this->ySpeed = orig.ySpeed;
	this->curTime = orig.curTime;
	this->bulletSprite = orig.bulletSprite;
	this->bulletTexture = orig.bulletTexture;
	this->imgMgr = orig.imgMgr;
	this->bulletType = orig.bulletType;
}

void Bullet::update(float curTime) {
	this->curTime = curTime;
	bulletSprite.move(0, ySpeed);
	collisionDetection();
}

void Bullet::collisionDetection() {
	bottom = bulletSprite.getPosition().y + bulletSprite.getGlobalBounds().width;
	left = bulletSprite.getPosition().x;
	right = bulletSprite.getPosition().x + bulletSprite.getGlobalBounds().width;
	top = bulletSprite.getPosition().y;
}

void Bullet::initSprite(float xPos) {
	if (!bulletTexture.loadFromImage(this->imgMgr.get_image("../img/bullet.png"))) {
		cout << "Failed to load Bullet img.";
	}
	bulletTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(100, 357);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	bulletSprite.setScale(0.15f, 0.15f);
	bulletSprite.setPosition(xPos, yPos);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bulletSprite);
}