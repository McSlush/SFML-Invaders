#include "Game.h"

using namespace std;

Game::Game() {
	srand((unsigned int)time(NULL));
	sf::Vector2i mouseCoordinates;

	player = new Player(imgMgr);

	int playerHp = player->getHealt();
	gameField = new GameField(imgMgr, playerHp);

	invMgr = new InvaderManager(imgMgr);

	bulMgr = new BulletManager(imgMgr);
}

Game::~Game() {
	delete gameField;
	delete player;
	delete invMgr;
	delete bulMgr;
}

void Game::changeWeapon(int weaponChoice) {
	player->changeWeapon(weaponChoice);
}

void Game::collisionDetection() {
	Target* inv = nullptr;
	Bullet* b = nullptr;
	Car* c = nullptr;
	
	//check all bullets
	for (int k = 0; k < player->getBulletCounter(); k++) {

		b = player->getBullet(k);
		//check each invader
		for (int i = 0; i < invMgr->getTargetCounter(); i++)
		{			
			if (dynamic_cast<Invader*>(invMgr->getInvader(i))) {
				inv = (Invader*)invMgr->getInvader(i);
			}
			else if (dynamic_cast<Invader2*>(invMgr->getInvader(i))) {
				inv = (Invader2*)invMgr->getInvader(i);
			}

			//if invader gets hit by bullet
			if (inv->collisionBullet(b)) {
				inv->hit(player->getDamage());
				player->removeBullet(k);
			}
		}
	}

	//If enemy hits car/sonic
	for (int i = 0; i < invMgr->getTargetCounter(); i++) {
		inv = invMgr->getInvader(i);
		Car* car = player->getCar();
		if (inv->collisionCar(car)) {
			//loose points equal to half invaders dmg
			int score = player->adjustScore(inv->getDmg() / 2);
			inv->hit(car->getDmg());
			gameField->setTextScore(score);
			invMgr->removeInvader(i);
		}
	}
}

void Game::moveCar(int direction) {
	player->moveCar(direction);
}

void Game::update(float curTime, sf::Vector2i mouseCoordinates) {
	this->curTime = curTime;

	//DEBUG autoshoot
	//shoot((sf::Vector2f)mouseCooridinates);

	collisionDetection();
	player->update(curTime, mouseCoordinates);
	updateInvaders();
}

void Game::updateInvaders() {
	sf::FloatRect invBoundingBox;
	Target* inv = nullptr;
	this->totTime += curTime;

	//TODO improve spawn rate
	if ((totTime > 1 && totTime < 1.03)  || (totTime > 0.5 && totTime < 0.53)) {
		invMgr->addInvader(new Invader(imgMgr));
	}
	else if (totTime > 1.5) {
		invMgr->addInvader(new Invader2(imgMgr));
		totTime = 0;
	}

	//kill enemy if...
	for (int i = 0; i < invMgr->getTargetCounter(); i++)
	{
		if (dynamic_cast<Invader*>(invMgr->getInvader(i))) {
			inv = (Invader*)invMgr->getInvader(i);
		}
		else if (dynamic_cast<Invader2*>(invMgr->getInvader(i))) {
			inv = (Invader2*)invMgr->getInvader(i);
		}

		invBoundingBox = inv->getGlobalBounds();
		//kill invader if 0 hp
		if (inv->getHealth() <= 0) {
			int score = player->adjustScore(inv->getDmg());
			gameField->setTextScore(score);
			invMgr->removeInvader(i);
		}

		//kill enemies that hits the ground
		else if (invBoundingBox.intersects(gameField->getGlobalBounds())) {
			//do damage to user.
			int hp = player->adjustHealth(-inv->getDmg());
			gameField->setTextHp(hp);
			int score = player->adjustScore(-inv->getDmg());
			gameField->setTextScore(score);
			//kill invader on ground hit
			invMgr->removeInvader(i);
		}
	}
	
	invMgr->update(curTime);
}

void Game::shoot(sf::Vector2f mouseCoordinates) {
	player->shoot(mouseCoordinates);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	gameField->drawBackground(target, states);
	
	invMgr->draw(target, states);

	gameField->draw(target, states);

	player->drawCar(target, states);
	
	player->draw(target, states);
}
