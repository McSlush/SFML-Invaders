#pragma once
#include "Image.h"
#include <iostream>
#include <map>

//downloaded from:
//https://github.com/SFML/SFML/wiki/Tutorial:-Image-Manager

class image_manager
{
private:
	image_manager(const image_manager&);
	std::map< std::string, sf::Image > images_;
	

public:
	image_manager();
	~image_manager();
	const sf::Image& get_image(const std::string& filename);
	void image_manager::delete_image(const sf::Image& image);
	void image_manager::delete_image(const std::string& filename);
	image_manager& operator =(const image_manager&);

};
