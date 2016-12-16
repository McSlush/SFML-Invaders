#pragma once

#include <SFML/Graphics.hpp>
#include "image_manager.h"
#include <iostream>

using namespace std;

class Bullet :public sf::Drawable {
private:
	int dmg;
	float y, ySpeed;
	float curTime;

	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	image_manager imgMgr;

public:
	float bottom, top, left, right;


	Bullet();

	Bullet(image_manager& imgMgr, float xPos);
	~Bullet() {}

	virtual void update(float curTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void initSprite(float xPos);
	sf::FloatRect getGlobalBounds() const { return bulletSprite.getGlobalBounds(); }

	void collisionDetection();

	void setBulletSprite(sf::Sprite bulletSprite) { this->bulletSprite = bulletSprite; }
	sf::Sprite getBulletSprite() const { return bulletSprite; }

	void setDmg(int dmg) { this->dmg = dmg; }
	int getDmg() { return dmg; }
};