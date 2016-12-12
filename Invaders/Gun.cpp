#include "Gun.h"

Gun::Gun() { }

Gun::Gun(image_manager& imgMgr)
{
	this->dmg = 10;
	this->y = 460;
	initSprite(imgMgr);
}

Gun::~Gun() { }

void Gun::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(gunSprite);
}

void Gun::update(sf::Vector2i mouseCoordinates) {
	this->x =  mouseCoordinates.x - gunSprite.getGlobalBounds().width / 2;
	gunSprite.setPosition(x, y);
}

void Gun::initSprite(image_manager& imgMgr) {
	if (!gunTexture.loadFromImage(imgMgr.get_image("../img/weapons.png"))) {
		cout << "Failed to load Gun image";
	}

	gunTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(50, 200);
	gunSprite.setTexture(gunTexture);
	gunSprite.setTextureRect(sf::IntRect(320, 120, spriteFrameSize.x, spriteFrameSize.y));
	gunSprite.setScale(2.0, 2.0);
	gunSprite.setPosition(0, y);
}