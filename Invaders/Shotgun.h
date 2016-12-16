#pragma once
#include "Weapon.h"


class Shotgun :	public Weapon
{
private:
	sf::Texture shotgunTexture;
	sf::Sprite shotgunSprite;
	image_manager imgMgr;

public:
	Shotgun();
	Shotgun(image_manager& imgMgr);
	virtual ~Shotgun();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(int xPos);
	virtual void initSprite(image_manager& imgMgr);
};

