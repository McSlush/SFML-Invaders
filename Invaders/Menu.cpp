#include "Menu.h"

Menu::Menu()
{
	initSprite();
}

Menu::~Menu()
{
}

//TODO menu click?
void Menu::leftClick(sf::Vector2f mouseCooridinates) {

}

StateChange Menu::update(float curTime, sf::Vector2f mouseCoordinates)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		return StateChange::GAME;
	else
		return StateChange::NO_CHANGE;
}

void Menu::initSprite() {
	if (!menuTexture.loadFromFile("../img/menu.png")) {
		cout << "Failed to load Menu image";
	}
	menuTexture.setSmooth(true);
	sf::Vector2i spriteFrameSize(600, 600);
	menuSprite.setTexture(menuTexture);
	menuSprite.setTextureRect(sf::IntRect(0, 0, spriteFrameSize.x, spriteFrameSize.y));
	//menuSprite.setScale(1.0f, 1.0f);
	menuSprite.setPosition(0, 0);
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(menuSprite, states);
}
