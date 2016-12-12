#include "Shotgun.h"

Shotgun::Shotgun()
{
}

Shotgun::Shotgun(image_manager& imgMgr) {
	this->dmg = 15;
	this->y = 485;
	initSprite(imgMgr);
}

Shotgun::~Shotgun()
{
}

void Shotgun::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shotgunSprite);
}

void Shotgun::update(sf::Vector2i mouseCoordinates) {
	this->x = mouseCoordinates.x - shotgunSprite.getGlobalBounds().width / 2;
	shotgunSprite.setPosition(x, y);
}

void Shotgun::initSprite(image_manager& imgMgr) {
	if (!shotgunTexture.loadFromImage(imgMgr.get_image("../img/weapons.png"))) {
		cout << "Failed to load Shutgun image";
	}

	shotgunTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(57, 70);
	shotgunSprite.setTexture(shotgunTexture);
	shotgunSprite.setTextureRect(sf::IntRect(567, 285, spriteFrameSize.x, spriteFrameSize.y));
	shotgunSprite.setScale(2.0, 2.0);
	shotgunSprite.setPosition(0.0f, y);
}