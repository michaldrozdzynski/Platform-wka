	#pragma once
#include "Textures.h"

class Lands
{
public:
	int type;
	sf::FloatRect position;
	sf::Sprite s_land;
	Lands(Textures &T, int x, int y, int t);
	void changeSprite(int t);
};

