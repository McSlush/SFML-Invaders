#pragma once
#include "Target.h"
class Invader2 : public Target {

public:
	Invader2();
	Invader2(image_manager& imgMgr, std::vector<std::string>& spriteNames);
	~Invader2();

	virtual void initSprite();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float td);
	virtual sf::FloatRect getGlobalBounds() const { return invaderSprite.getGlobalBounds(); }

	virtual void collisionDetection();
	virtual bool collision(Bullet& bullet) const;

	void setInvider2Sprite(sf::Sprite invaderSprite) { this->invaderSprite = invaderSprite; }
	sf::Sprite getInvader2Sprite() const { return invaderSprite; }
};

