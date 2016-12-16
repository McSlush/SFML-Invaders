#pragma once

#include <SFML\Graphics.hpp>
#include "image_manager.h"


class GameField : public sf::Drawable {
private:
	int playerHp, score;
	image_manager imgMgr;
	sf::Texture backTexture;
	sf::Sprite backSprite;
	sf::Texture grassTexture;
	sf::Sprite grassSprite;
	sf::Font font;
	sf::Text textHp;
	sf::Text textScore;

	void loadFont();

public:
	GameField() {}
	GameField(image_manager& imgMgr, int playerHp);
	sf::Sprite getGrassSprite() const { return grassSprite; };
	
	sf::FloatRect getGlobalBounds() { return grassSprite.getGlobalBounds(); }
	void initSprite();
	void setTextHp(int hp);
	void setTextScore(int score);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void GameField::drawBackground(sf::RenderTarget& target, sf::RenderStates states) const;
};