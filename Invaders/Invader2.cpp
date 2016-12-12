#include "Invader2.h"

Invader2::Invader2() {
	this->health = 0;
	this->dmg = 0;
}

Invader2::Invader2(image_manager& imgMgr, std::vector<std::string>& spriteNames) {
	this->health = 20;
	this->dmg = 7;
	this->xSpeed = 3;
	this->imgMgr = imgMgr;
	initSprite();
}

Invader2::~Invader2() {

}

void Invader2::update(float td) {
	gameTime = td;
	invaderSprite.move(0, xSpeed);
	collisionDetection();
}

void Invader2::collisionDetection() {
	bottom = invaderSprite.getPosition().y + invaderSprite.getGlobalBounds().width;
	left = invaderSprite.getPosition().x;
	right = invaderSprite.getPosition().x + invaderSprite.getGlobalBounds().width;
	top = invaderSprite.getPosition().y;
}

bool Invader2::collision(Bullet& b) const {

	//TODO unable to read b property sometimes. 
	//check when and how bullets are removed on collision
	if (right < b.left || left > b.right ||
		top > b.bottom || bottom < b.top) {
		return false;
	}
	//hit!
	return true;
}

void Invader2::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(invaderSprite);
}

void Invader2::initSprite() {
	//TODO if all spriteName, load each invaders.png
	int rands = rand() % 400 + 1;
	if (!invaderTexture.loadFromImage(imgMgr.get_image("../img/invaders.png"))) {
		cout << "Failed to load Invader image";
	}
	invaderTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(120, 90);
	invaderSprite.setTexture(invaderTexture);
	invaderSprite.setTextureRect(sf::IntRect(125, 0, spriteFrameSize.x, spriteFrameSize.y));
	invaderSprite.setScale(0.5f, 0.5f);
	invaderSprite.setPosition((float)rands, 0);
}
