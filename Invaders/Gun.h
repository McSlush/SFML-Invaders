#pragma once
#include "Weapon.h"

class Gun :	public Weapon
{
private:
	sf::Texture gunTexture;
	sf::Sprite weaponSprite;
	image_manager imgMgr;

public:
	Gun();
	Gun(image_manager& imgMgr);
	virtual ~Gun();

	void shoot(sf::Vector2f mouseCoordinates, BulletManager& bulMgr);
	int getDmg() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(int xPos, float curTime);
	virtual void initSprite(image_manager& imgMgr);

};

