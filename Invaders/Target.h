#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "image_manager.h"
#include "Bullet.h"

using namespace std;

class Target : public sf::Drawable {
	
protected:
	float xSpeed, ySpeed;
	int x, y, health, dmg;
	float gameTime;
	float bottom, top, left, right;

	sf::Texture invaderTexture;
	sf::Sprite invaderSprite;
	image_manager imgMgr;
public:

	Target();
	virtual ~Target();

	virtual void initSprite() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void update(float td) = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;

	virtual void collisionDetection() = 0;
	virtual bool collision(shared_ptr<Bullet> b) const = 0;



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

	void setGameTime(float td) { gameTime = td; }
	float getGameTime() const { return gameTime; }

	void setX(int x) { this->x = x; }
	int getX() const { return x; }

	void setY(int y) { this->y = y; }
	int getY() const { return y; }
};