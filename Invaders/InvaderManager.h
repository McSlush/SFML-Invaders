#pragma once
#include "Target.h"
#include "Invader.h"
#include "Invader2.h"

class InvaderManager {
private:
	int cap;
	int targetCounter;
	Target** targets;
	image_manager imgMgr;

public:
	InvaderManager();
	InvaderManager(image_manager& imgMgr);
	~InvaderManager();

	int getTargetCounter();
	Target* getInvader(int index);
	void addInvader(Target* inv);
	void removeInvader(int index);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float curTime);


};