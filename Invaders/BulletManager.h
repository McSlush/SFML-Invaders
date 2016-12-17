#pragma once

#include "Bullet.h"

class BulletManager
{
private:
	int cap;
	int bulletCounter;
	Bullet** bullets;
	image_manager imgMgr;
	int gunBullets, shotgunBullets;

public:
	BulletManager();
	BulletManager(image_manager& imgMgr);
	BulletManager(const BulletManager & orig);
	virtual ~BulletManager();

	int getBulletCounter();
	Bullet* getBullet(int index);
	void addBullet(Bullet* bul);
	void removeBullet(int index);
	
	int getGunBullets() { return gunBullets; }
	void addGunBullet() { gunBullets++; }

	int getShotgunBullets() { return shotgunBullets; }
	void addShotgunBullet() { shotgunBullets++; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float curTime, BulletManager* bulMgr);

};

