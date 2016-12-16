#pragma once

#include <SFML\Graphics.hpp>
#include "image_manager.h"

class Car : public sf::Drawable
{
private:
	sf::Texture carTexture;
	sf::Sprite carSprite;
	image_manager imgMgr;
	float xSpeed;

public:
	int dmg;
	float yPos, xPos;
	float bottom, top, left, right;

	Car();
	Car(image_manager& imgMgr);
	virtual ~Car();

	virtual void initSprite();
	void update(float curTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int getDmg();
	void moveCar(float gameTime, int direction);
	void collisionDetection();
	sf::FloatRect getGlobalBounds() const;

	sf::Sprite getCarSprite() const { return carSprite; }
	sf::Sprite setCarSprite(sf::Sprite carSprite) { this->carSprite = carSprite; }

};

