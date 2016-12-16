#pragma once

#include "Bullet.h"

class BulletManager
{
private:
	int cap;
	int bulletCounter;
	Bullet** bullets;
	image_manager imgMgr;

public:
	BulletManager();
	BulletManager(image_manager& imgMgr);
	virtual ~BulletManager();

	int getBulletCounter();
	Bullet* getBullet(int index);
	void addBullet(Bullet* bul);
	void removeBullet(int index);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float curTime, BulletManager* bulMgr);

};

