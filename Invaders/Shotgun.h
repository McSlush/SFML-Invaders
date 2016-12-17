#pragma once
#include "Weapon.h"


class Shotgun :	public Weapon
{
private:
	sf::Texture shotgunTexture;
	sf::Sprite weaponSprite;
	image_manager imgMgr;

public:
	Shotgun();
	Shotgun(image_manager& imgMgr);
	virtual ~Shotgun();

	void Shotgun::shoot(sf::Vector2f mouseCoordinates, BulletManager& bulMgr);

	int getDmg() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(int xPos, float curTime);
	virtual void initSprite(image_manager& imgMgr);
};

