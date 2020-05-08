#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Lands.h"
class Star
{
public:
	sf::Sprite s_star;
	void move(std::vector<Lands>& squares);
	void draw(sf::RenderWindow& window);
	Star(Textures& T, int position);
	int position;
	bool right;
	//int value;
};

