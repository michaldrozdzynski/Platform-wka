#include "Lands.h"
#include <iostream>

Lands::Lands(Textures& T, int x, int y, int t)
{
	s_land.setTexture(T.lands);
	type = t;
	changeSprite(type);

	int X = (x - 1) * 50;
	int Y = (y - 1) * 50;

	s_land.setPosition(X, Y);
	position = s_land.getGlobalBounds();
}

void Lands::changeSprite(int t)
{
	type = t;
	switch (type)
	{
	case 0: s_land.setTextureRect(sf::IntRect(200, 0, 50, 50));
		break;
	case 1:	s_land.setTextureRect(sf::IntRect(0, 0, 50, 50));
		break;
	case 2:	s_land.setTextureRect(sf::IntRect(50, 0, 50, 50));
		break;
	case 3:	s_land.setTextureRect(sf::IntRect(100, 0, 50, 50));
		break;
	case 4:	s_land.setTextureRect(sf::IntRect(150, 0, 50, 50));
		break;
	case 5: s_land.setTextureRect(sf::IntRect(250, 0, 50, 50));
	}
}