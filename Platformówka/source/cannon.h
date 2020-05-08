#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Lands.h"


class Cannon
{
public:
	sf::Sprite s_cannon;
	sf::Sprite s_bullet;
	int position;
	Cannon(Textures& T, int value);
	void move(std::vector<Lands>& squares);
	void draw(sf::RenderWindow& window);
};

