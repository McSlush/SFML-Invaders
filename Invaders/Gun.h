#pragma once
#include "Weapon.h"

class Gun :	public Weapon
{
private:
	sf::Texture gunTexture;
	sf::Sprite gunSprite;
	image_manager imgMgr;

public:
	Gun();
	Gun(image_manager& imgMgr);
	virtual ~Gun();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(int xPos);
	virtual void initSprite(image_manager& imgMgr);

};

