#pragma once
#include "Target.h"

class Invader2 : public Target {
//TODO move this?
private:
	float totTime;

public:
	Invader2();
	Invader2(image_manager& imgMgr);
	~Invader2();

	virtual void initSprite();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float curTime);
	virtual sf::FloatRect getGlobalBounds() const { return invaderSprite.getGlobalBounds(); }
	
	void moveTarget();
	
	virtual void collisionDetection();
	virtual bool collisionBullet(Bullet* bullet) const;
	virtual bool collisionCar(Car* c) const;

	void setInvider2Sprite(sf::Sprite invaderSprite) { this->invaderSprite = invaderSprite; }
	sf::Sprite getInvader2Sprite() const { return invaderSprite; }
};

