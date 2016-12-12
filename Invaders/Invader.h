#pragma once

#include "Target.h"

class Invader : public Target {
public:
	Invader();
	Invader(image_manager& imgMgr);
	~Invader();

	virtual void initSprite();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float td);
	virtual sf::FloatRect getGlobalBounds() const { return invaderSprite.getGlobalBounds(); }

	virtual void collisionDetection();
	virtual bool collision(shared_ptr<Bullet> b) const;

	void setInviderSprite(sf::Sprite invaderSprite) { this->invaderSprite = invaderSprite; }
	sf::Sprite getInvaderSprite() const { return invaderSprite; }
};