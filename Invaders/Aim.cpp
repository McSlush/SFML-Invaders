#include "Aim.h"


Aim::Aim() {}

Aim::Aim(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	if (!aimTexture.loadFromImage(this->imgMgr.get_image("../img/aim.png"))) {
		cout << "Failed to load Aim img.";
	}
	aimSprite.setTexture(aimTexture);
}


void Aim::update(sf::Vector2f mouseCoordinates) {
	aimSprite.setPosition(mouseCoordinates.x, mouseCoordinates.y);
}

void Aim::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(aimSprite);
}
