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
	int y, x;

	Car();
	Car(image_manager& imgMgr);
	virtual ~Car();

	virtual void initSprite(image_manager& imgMgr);
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void moveCar(int direction);

	//TODO implement this
	//virtual sf::FloatRect getGlobalBounds() const { return invaderSprite.getGlobalBounds(); }

	//virtual void collisionDetection();
	//virtual bool collision(Bullet& bullet) const;

	sf::Sprite getCarSprite() const { return carSprite; }
	sf::Sprite setCarSprite(sf::Sprite carSprite) { this->carSprite = carSprite; }

};

