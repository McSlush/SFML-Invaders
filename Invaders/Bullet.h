#pragma once

#include <SFML/Graphics.hpp>
#include "image_manager.h"
#include <iostream>

using namespace std;

class Bullet :public sf::Drawable {
private:
	int dmg;
	float y, ySpeed;
	float gameTime;

	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	image_manager imgMgr;

public:
	float bottom, top, left, right;

	void collisionDetection();

	Bullet();

	Bullet(image_manager& imgMgr, sf::Vector2f mouseCooridinates);
	~Bullet() {}

	virtual void update(float td);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void initSprite(sf::Vector2f mouseCooridinates);
	sf::FloatRect getGlobalBounds() const { return bulletSprite.getGlobalBounds(); }

	void setBulletSprite(sf::Sprite bulletSprite) { this->bulletSprite = bulletSprite; }
	sf::Sprite getBulletSprite() const { return bulletSprite; }

	void setDmg(int dmg) { this->dmg = dmg; }
	int getDmg() { return dmg; }
};