#include "Star.h"
#include <iostream>

void Star::move(std::vector<Lands>& squares)
{
	int x, y;
	x = s_star.getPosition().x / 50;
	y = s_star.getPosition().y / 50;
	int value = 22 * x + y;
	value = value + 22;
	if (right)
	{
		s_star.move(7, 0);
		s_star.rotate(10);
		if (value >= 0 and value < squares.size() and squares[value].type != 5)
		{
			if (squares[value].s_land.getGlobalBounds().intersects(s_star.getGlobalBounds()))
				right = false;
			
		}
	}
	else
	{
		value = value - 44;
		s_star.rotate(-10);
		s_star.move(-7, 0);
		if (value >= 0 and value < squares.size() and squares[value].type != 5)
		{
			//squares[value].changeSprite(0);
			if (squares[value].s_land.getGlobalBounds().intersects(s_star.getGlobalBounds()))
				right = true;
		}
	}
}

void Star::draw(sf::RenderWindow& window)
{
	window.draw(s_star);
}

Star::Star(Textures& T, int value)
{
	s_star.setTexture(T.star);      
	int y = value % 22;
	int x = value / 22;
	s_star.setPosition(x * 50 +20, y * 50+20);
	s_star.setOrigin(28, 28);
	position = value;
	right = true;
}
