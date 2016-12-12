#pragma once

#include "SFML\Graphics.hpp"

class FontInvader {
private:
	sf::Font font;


public:
	FontInvader();
	FontInvader(sf::Font font);

	// select the font
	text.setFont(font); // font is a sf::Font

						// set the string to display
	text.setString("Hello world");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

							   // set the color
	text.setColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

};