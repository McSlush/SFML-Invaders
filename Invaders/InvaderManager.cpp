#include "InvaderManager.h"

InvaderManager::InvaderManager() {
}

InvaderManager::InvaderManager(image_manager& imgMgr) {
	this->imgMgr = imgMgr;
	this->cap = 100;
	this->targetCounter = 0;
	this->targets = new Target*[cap];
}

InvaderManager::~InvaderManager() {
	for (int i = 0; i < targetCounter; i++) {
		delete targets[i];
	}
	delete targets;
}

int InvaderManager::getTargetCounter() {
	return this->targetCounter;
}

Target* InvaderManager::getInvader(int index) {
	return targets[index];
}

void InvaderManager::addInvader(Target* inv) {
	this->targets[targetCounter++] = inv;
}

void InvaderManager::removeInvader(int index) {
		delete targets[index];
		targets[index] = targets[targetCounter - 1];
		targetCounter--;
}

void InvaderManager::update(float curTime) {
	for (int i = 0; i < targetCounter; i++) {
		targets[i]->update(curTime);
	}
}

void InvaderManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < targetCounter; i++) {
		targets[i]->draw(target, states);
	}
}
