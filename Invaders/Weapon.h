#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include "image_manager.h"
#include <vector>

using namespace std;

//TODO: This is copied from Target. go through it...
class Weapon : public sf::Drawable {
	
protected:
	float x, y;
	int dmg;
	float curTime;
	//Bullet bullet;

public:
	Weapon();
	virtual ~Weapon();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void update(int xPos) = 0;

	void setDmg(int dmg) { this->dmg = dmg; }
	int getDmg() const { return this->dmg; }

	void setGameTime(float curTime) { this->curTime = curTime; }
	float getGameTime() const { return curTime; }

	void setX(float x) { this->x = x; }
	float getX() const { return x; }
};