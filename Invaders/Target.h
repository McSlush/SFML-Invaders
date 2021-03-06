#pragma once

#include <SFML/Graphics.hpp>
#include "image_manager.h"
#include "Bullet.h"
#include "Car.h"

using namespace std;

class Target : public sf::Drawable {
	
protected:
	float xSpeed, ySpeed;
	float xPos, yPos;
	float curTime;
	float bottom, top, left, right;
	int health, dmg;

	sf::Texture invaderTexture;
	sf::Sprite invaderSprite;
	image_manager imgMgr;
public:

	Target();
	virtual ~Target();

	virtual void initSprite() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void update(float curTime) = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;

	virtual void collisionDetection() = 0;
	virtual bool collisionBullet(Bullet* b) const = 0;
	virtual bool collisionCar(Car* c) const = 0;

	virtual void moveTarget() = 0;

	void setInviderSprite(sf::Sprite invaderSprite) { this->invaderSprite = invaderSprite; }
	sf::Sprite getInvaderSprite() const { return invaderSprite; }

	void hit(int dmg) { this->health -= dmg; }
	int getDmg() { return this->dmg; }	

	void setHealth(int health) { this->health = health; }
	int getHealth() const { return health; }

	void setDmg(int dmg) { this->dmg = dmg; }
	int getDmg() const { return dmg; }

	void setXSpeed(float xSpeed) { this->xSpeed = xSpeed; };
	float getXSpeed() const { return xSpeed; };

	void setYSpeed(float ySpeed) { this->ySpeed = ySpeed; };
	float getYSpeed() const { return ySpeed; };

	void setGameTime(float curTime) { this->curTime = curTime; }
	float getGameTime() const { return curTime; }

	void setX(float xPos) { this->xPos = xPos; }
	float getX() const { return xPos; }

	void setY(float yPos) { this->yPos = yPos; }
	float getY() const { return yPos; }
};