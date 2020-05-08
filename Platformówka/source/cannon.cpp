#include "cannon.h"
#include <iostream>

Cannon::Cannon(Textures& T, int value)
{
	s_cannon.setTexture(T.cannon);
	s_bullet.setTexture(T.bullet);
	int y = value % 22;
	int x = value / 22;
	s_cannon.setPosition(x*50, y*50 + 5);
	s_bullet.setPosition(x * 50, y*50 + 22);
	position = value;
	//std::cout << "duda to super prezydent" << std::endl;
}
void Cannon::move(std::vector<Lands>& squares)
{
	int x, y;
	x = s_bullet.getPosition().x / 50;
	y = s_bullet.getPosition().y / 50;
	int value = 22 * x + y;
	value = value + 22;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(s_bullet.getGlobalBounds()))
			s_bullet.setPosition(s_cannon.getPosition().x,s_cannon.getPosition().y + 17);
	}
	s_bullet.move(7, 0);
}
void Cannon::draw(sf::RenderWindow& window)
{
	//move();
	window.draw(s_bullet);
	window.draw(s_cannon);
}
