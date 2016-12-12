#pragma once

#include <vector>

using namespace std;

class SpriteNames {
private:
	vector<string> spriteNames;
	string imgDir;

public:
	SpriteNames() {
		imgDir = "../img/";
		spriteNames.push_back(imgDir + "invaders.png");
		spriteNames.push_back(imgDir + "aim.png");
		spriteNames.push_back(imgDir + "grass.png");
		spriteNames.push_back(imgDir + "weapons.png");
	}

	vector<string> getSpriteNames() {
		return spriteNames;
	}
};