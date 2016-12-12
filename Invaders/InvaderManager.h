#pragma once
#include "Target.h"
#include "Invader.h"
#include "Invader2.h"

class InvaderManager {
private:
	Target* target;
	vector<Target*> targets;
	image_manager imgMgr;
	vector<string>spriteNames;

public:
	InvaderManager();
	InvaderManager(image_manager& imgMgr, std::vector<std::string>& spriteNames);
	~InvaderManager();

	virtual void initSprite(image_manager& imgMgr, std::vector<std::string>& spriteNames);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float td);

	//void addInvader() { targets.push_back(new Invader()); }
	//void addInvader2() { targets.push_back(new Invader2(spriteNames)); }

	vector<Target*> getInvaders() { return targets; }
	void setInvaders(vector<Target*> invaders) { this->targets = invaders; }

};