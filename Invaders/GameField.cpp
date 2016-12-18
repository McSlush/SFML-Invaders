#include "GameField.h"
#include <iostream>
#include <sstream>

using namespace std;

GameField::GameField(image_manager& imgMgr, int playerHp) {
	this->imgMgr = imgMgr;
	this->playerHp = playerHp;
	this->score = 0;
	initSprite();
	loadFont();
}

void GameField::initSprite() {
	if (!grassTexture.loadFromImage(this->imgMgr.get_image("../img/floor.png"))) {
		cout << "Failed to load Floor img.";
	}
	grassTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(850, 300);
	grassSprite.setTexture(grassTexture);
	grassSprite.setTextureRect(sf::IntRect(0, 100, spriteFrameSize.x, spriteFrameSize.y));
	grassSprite.setPosition(0, 450);

	if (!backTexture.loadFromImage(this->imgMgr.get_image("../img/background.jpg"))) {
		cout << "Failed to load Background img.";
	}
	backTexture.setSmooth(true);
	sf::Vector2i sprite2FrameSize(850, 800);
	backSprite.setTexture(backTexture);
	backSprite.setTextureRect(sf::IntRect(740, 525, sprite2FrameSize.x, sprite2FrameSize.y));
	backSprite.setPosition(0, 0);
}

void GameField::loadFont() {
	if (!font.loadFromFile("../fonts/thunderstrike.ttf")) {
		cout << "Could not load thunderstrike.ttf";
	}
	textHp.setFont(font);
	textHp.setString("HP: " + to_string(playerHp));
	textHp.setCharacterSize(24);
	textHp.setFillColor(sf::Color::Yellow);
	textHp.setPosition(0, 550);

	textScore.setFont(font);
	textScore.setString("Score: " + to_string(score));
	textScore.setCharacterSize(24);
	textScore.setFillColor(sf::Color::Yellow);
	textScore.setPosition(0, 500);
}

void GameField::setTextScore(int score) {
	textScore.setString("Score: " + to_string(score));
}

void GameField::setTextHp(int hp) {
	this->textHp.setString("HP: " + to_string(hp));
}

void GameField::drawBackground(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(backSprite);
}

void GameField::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(grassSprite);
	target.draw(textHp);
	target.draw(textScore);
}
