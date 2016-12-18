#include "GameOver.h"

GameOver::GameOver()
{
	initSprite();
}

GameOver::~GameOver()
{
}

//TODO click?
void GameOver::leftClick(sf::Vector2f mouseCooridinates) {

}

StateChange GameOver::update(float curTime, sf::Vector2f mouseCoordinates)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		return StateChange::GAME;
	else
		return StateChange::NO_CHANGE;
}

void GameOver::initSprite() {
	if (!gameOverTexture.loadFromFile("../img/gameover.png")) {
		cout << "Failed to load Menu image";
	}
	gameOverTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(1200, 800);
	gameOverSprite.setTexture(gameOverTexture);
	gameOverSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	//gameOverSprite.setScale(1.0f, 1.0f);
	gameOverSprite.setPosition(-340, -60);
}

void GameOver::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(gameOverSprite, states);
}
