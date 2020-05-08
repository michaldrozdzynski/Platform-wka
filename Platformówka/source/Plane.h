#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Lands.h"

class Plane
{
public:
	sf::Sprite s_plane;
	sf::Sprite s_bomb;
	int stage;
	Plane(Textures& T, int position);
	void draw(sf::RenderWindow& window);
	void move(std::vector<Lands>& squares);
	int position;
	bool right;
};

