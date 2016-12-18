#pragma once

#include <SFML/Graphics.hpp>
#include "image_manager.h"
#include <vector>
#include "BulletManager.h"

using namespace std;

class Weapon : public sf::Drawable {
protected:
	float x, y;
	int dmg;
	float curTime;
	image_manager imgMgr;
	sf::Sprite weaponSprite;
	Bullet::BulletType bulletType;

public:
	Weapon();
	Weapon(image_manager imgMgr);
	virtual ~Weapon();

	virtual void shoot(sf::Vector2f mouseCoordinates, BulletManager& bulMgr) = 0;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void update(int xPos, float curTime) = 0;

	void setDmg(int dmg) { this->dmg = dmg; }
	virtual int getDmg() const { return this->dmg; }

	void setGameTime(float curTime) { this->curTime = curTime; }
	float getGameTime() const { return curTime; }

	void setX(float x) { this->x = x; }
	float getX() const { return x; }
};