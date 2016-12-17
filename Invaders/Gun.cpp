#include "Gun.h"

Gun::Gun() { }

Gun::Gun(image_manager& imgMgr)
{
	this->imgMgr = imgMgr;
	this->dmg = 10;
	this->y = 460;
	this->bulletType = Bullet::BulletType::GUN;
	initSprite(imgMgr);
}

Gun::~Gun() {
}

int Gun::getDmg() const {
	return this->dmg;
}

void Gun::shoot(sf::Vector2f mouseCoordinates, BulletManager& bulMgr) {
	if (bulMgr.getGunBullets() < 7) {
		bulMgr.addGunBullet();
		bulMgr.addBullet(new Bullet(imgMgr, mouseCoordinates.x, bulletType));
	}
}




void Gun::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(weaponSprite);
}

void Gun::update(int xPos, float curTime) {
	this->x = xPos - weaponSprite.getGlobalBounds().width / 2;
	weaponSprite.setPosition(x, y);
}

void Gun::initSprite(image_manager& imgMgr) {
	if (!gunTexture.loadFromImage(imgMgr.get_image("../img/weapons.png"))) {
		cout << "Failed to load Gun image";
	}

	gunTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(50, 200);
	weaponSprite.setTexture(gunTexture);
	weaponSprite.setTextureRect(sf::IntRect(320, 120, spriteFrameSize.x, spriteFrameSize.y));
	weaponSprite.setScale(2.0, 2.0);
	weaponSprite.setPosition(0, y);
}