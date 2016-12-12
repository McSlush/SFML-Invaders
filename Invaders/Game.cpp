#include "Game.h"

using namespace std;

Game::Game() {
	srand((unsigned int)time(NULL));
	sf::Vector2i mouseCoordinates;

	for (size_t i = 0; i < names.size(); i++)
	{
		imgMgr.get_image(names.at(i));
	}
	names = spriteNames.getSpriteNames();

	player = make_unique<Player>(imgMgr, mouseCoordinates);

	//TODO set up the background and such
	int playerHp = player->getHealt();
	gameField = make_unique<GameField>(imgMgr, playerHp);

}

Game::~Game() {}

void Game::changeWeapon(int weaponChoice) {
	//player->changeWeapon(weaponChoice);
}

void Game::collisionDetection() {
	//invaders.push_back(move(make_unique<Invader>(imgMgr)));
	bool removeBullet = false;
	//bullets
	for (size_t k = 0; k < bullets.size(); k++) {

		for (size_t i = 0; i < invaders.size(); i++)
		{			
			shared_ptr<Bullet> b(bullets.at(k));

			//if invader gets hit by bullet
			if (invaders.at(i)->collision(b)) {
				//TODO set dmg from gun
				cout << "hit";
				invaders.at(i)->hit(10);
				removeBullet = true;
			}
		}
		if (removeBullet) {

			bullets.erase(bullets.begin() + k);
		}
	}
}

void Game::moveCar(int direction) {
	player->moveCar(direction);
}

void Game::update(float td, sf::Vector2i mouseCooridinates) {
	gameTime += td;

	//DEBUG autoshoot
	//shoot((sf::Vector2f)mouseCooridinates);

	collisionDetection();
	player->update(td, mouseCooridinates);
	updateBullets(td);
	updateInvaders(td);
}


void Game::updateBullets(float td) {
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets.at(i)->update(td);
	}
	//remove the bullet when it's of screen
	for (size_t i = 0; i < bullets.size(); i++) {
		sf::Vector2f bulletPos = bullets.at(i)->getBulletSprite().getPosition();
		if (bulletPos.y < -20) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Game::updateInvaders(float td) {
	sf::FloatRect invBoundingBox;

	//prepere to spawn
	int spawnRate = rand() % 100 + 1;
	if (remainder(gameTime, 3) > 1) {
		//random spawn
		if (spawnRate > 1 && spawnRate < 10) {
			invaders.push_back(move(make_unique<Invader>(imgMgr)));
		}
		if (spawnRate > 11 && spawnRate < 21) {
			//invMgr->addInvader2();
		}
	}

	//kill enemy if...
	for (size_t i = 0; i < invaders.size(); i++)
	{
		invBoundingBox = invaders.at(i)->getGlobalBounds();
		//kill invader if 0 hp
		if (invaders.at(i)->getHealth() <= 0) {
			invaders.erase(invaders.begin() + i);
		}

		//kill enemies that hits the ground
		else if (invBoundingBox.intersects(gameField->getGlobalBounds())) {
			//do damage to user.
			int hp = player->adjustHealth(- invaders.at(i)->getDmg());
			gameField->setTextHp(hp);
			//kill invader on ground hit
			invaders.erase(invaders.begin() + i);
		}
	}
	
	//for (size_t i = 0; i < invaders.size(); i++) {
	for(shared_ptr<Invader> invader : invaders) {
		invader->update(td);
	}
}

void Game::shoot(sf::Vector2f mouseCoordinates) {
	//only 10 bullets on screen at a time
	//TODO change size on weapon. Move to weapon?
	if (bullets.size() < 10) {
		bullets.push_back(make_unique<Bullet>(imgMgr, mouseCoordinates));
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	gameField->drawBackground(target, states);
	
	for (size_t i = 0; i < invaders.size(); i++) {
		invaders.at(i)->draw(target, states);
	}

	gameField->draw(target, states);

	player->drawCar(target, states);
	
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets.at(i)->draw(target, states);
	}

	player->draw(target, states);
	
	
}
