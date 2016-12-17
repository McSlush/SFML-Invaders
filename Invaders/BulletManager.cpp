#include "BulletManager.h"

BulletManager::BulletManager() {
	this->cap = 100;
	this->bulletCounter = 0;
	this->bullets = new Bullet*[cap];
	this->gunBullets = 0;
	this->shotgunBullets = 0;
}

BulletManager::BulletManager(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->cap = 100;
	this->bulletCounter = 0;
	this->bullets = new Bullet*[cap];
	this->gunBullets = 0;
	this->shotgunBullets = 0;
	for (int i = 0; i < cap; i++) {
		bullets[i] = nullptr;
	}
}

BulletManager::BulletManager(const BulletManager& orig) {
	this->imgMgr = orig.imgMgr;
	this->cap = orig.cap;
	this->bulletCounter = orig.bulletCounter;
	this->bullets = new Bullet*[this->cap];
	this->gunBullets = orig.gunBullets;
	this->shotgunBullets = orig.shotgunBullets;

	for (int i = 0; i < this->bulletCounter; i++) {
		this->bullets[i] = orig.bullets[i];
	}
}

BulletManager::~BulletManager()
{
	for (int i = 0; i < bulletCounter; i++)
	{
		delete bullets[i];
	}
	delete[] bullets;
}

int BulletManager::getBulletCounter() {
	return bulletCounter;
}

Bullet* BulletManager::getBullet(int index) {
	return bullets[index];
}

void BulletManager::addBullet(Bullet* bul) {
	this->bullets[bulletCounter++] = bul;
}

void BulletManager::removeBullet(int index) {
	if(bullets[index]->bulletType == Bullet::BulletType::GUN) {
		gunBullets--;
	}
	else if (bullets[index]->bulletType == Bullet::BulletType::SHOTGUN) {
		shotgunBullets--;
	}
	delete bullets[index];
	bullets[index] = bullets[bulletCounter - 1];
	bulletCounter--;
}

void BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < bulletCounter; i++) {
		bullets[i]->draw(target, states);
	}
}

void BulletManager::update(float curTime, BulletManager* bulMgr) {
	//remove the bullet when it's of screen
	for (int i = 0; i < bulMgr->getBulletCounter(); i++) {
		sf::Vector2f bulletPos = bulMgr->getBullet(i)->getBulletSprite().getPosition();
		if (bulletPos.y < -10) {
			bulMgr->removeBullet(i);
		}
	}
	
	for (int i = 0; i < bulletCounter; i++) {
		bullets[i]->update(curTime);
	}
}
