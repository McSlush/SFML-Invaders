#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "image_manager.h"
#include <memory>

using namespace std;

class Aim : public sf::Drawable {
private:
	sf::Texture aimTexture;
	sf::Sprite aimSprite;
	image_manager imgMgr;

public:
	Aim();
	Aim(image_manager& imgMgr);
	void update(sf::Vector2i mouseCoordinates);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite getAimSprite() const { return aimSprite; }
	sf::Sprite setAimSprite(sf::Sprite aimSprite) { this->aimSprite = aimSprite; }
};