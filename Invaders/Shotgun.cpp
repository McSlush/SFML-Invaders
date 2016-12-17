#include "Shotgun.h"

Shotgun::Shotgun() { }

Shotgun::Shotgun(image_manager& imgMgr) 
{
	this->imgMgr = imgMgr;
	this->dmg = 7;
	this->y = 485;
	this->bulletType = Bullet::BulletType::SHOTGUN;
	initSprite(imgMgr);
}

Shotgun::~Shotgun()
{
}

void Shotgun::shoot(sf::Vector2f mouseCoordinates, BulletManager& bulMgr) {
	
	if (bulMgr.getShotgunBullets() + 4<= 12) {
		bulMgr.addShotgunBullet();
		bulMgr.addBullet(new Bullet(imgMgr, mouseCoordinates.x + 10, bulletType));
		bulMgr.addShotgunBullet();
		bulMgr.addBullet(new Bullet(imgMgr, mouseCoordinates.x + 0, bulletType));
		bulMgr.addShotgunBullet();
		bulMgr.addBullet(new Bullet(imgMgr, mouseCoordinates.x - 15, bulletType));
		bulMgr.addShotgunBullet();
		bulMgr.addBullet(new Bullet(imgMgr, mouseCoordinates.x - 30, bulletType));
	}
}

void Shotgun::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(weaponSprite);
}

void Shotgun::update(int xPos, float curTime) {
	this->x = xPos - weaponSprite.getGlobalBounds().width / 2;
	weaponSprite.setPosition(x, y);
}

void Shotgun::initSprite(image_manager& imgMgr) {
	if (!shotgunTexture.loadFromImage(imgMgr.get_image("../img/weapons.png"))) {
		cout << "Failed to load Shotgun image";
	}

	shotgunTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(57, 70);
	weaponSprite.setTexture(shotgunTexture);
	weaponSprite.setTextureRect(sf::IntRect(567, 285, spriteFrameSize.x, spriteFrameSize.y));
	weaponSprite.setScale(2.0, 2.0);
	weaponSprite.setPosition(0.0f, y);
}

int Shotgun::getDmg() const { return this->dmg; }
