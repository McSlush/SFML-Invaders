#include "InvaderManager.h"
#include "Invader.h"

InvaderManager::InvaderManager() {
}

InvaderManager::InvaderManager(image_manager& imgMgr, std::vector<std::string>& spriteNames) {
	this->imgMgr = imgMgr;
	this->spriteNames = spriteNames;
}

InvaderManager::~InvaderManager() {
	for (Target* inv : targets) {
		delete inv;
	}
	delete target;
}

void InvaderManager::update(float td) {
	for (Target* inv : targets) {
		inv->update(td);
	}
}

void InvaderManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Target* inv : targets) {
		inv->draw(target, states);
	}
	
}

//TODO for each sprite names add invader
void InvaderManager::initSprite(image_manager& imgMgr, std::vector<std::string>& spriteNames) {
	//Invader inv;
	//inv.initSprite();
}
