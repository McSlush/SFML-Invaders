#pragma once

#include <SFML/Graphics.hpp>

class WeaponManager
{
public:
	WeaponManager();
	~WeaponManager();

	void shoot(sf::Vector2f mouseCooridinates);
};

