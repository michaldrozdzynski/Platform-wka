#include "Plane.h"
#include "Lands.h"

Plane::Plane(Textures& T, int value)
{
	s_plane.setTexture(T.plane);
	s_plane.setTextureRect(sf::IntRect(0, 0, 80, 44));
	s_bomb.setTexture(T.bomb);
	position = value;
	int y = value % 22;
	int x = value / 22;
	s_plane.setPosition(x * 50, y * 50);
	s_bomb.setPosition(x * 50 + 50, y * 50 + 20);
	right = true;
	stage = 0;
}

void Plane::draw(sf::RenderWindow& window)
{
	window.draw(s_bomb);
	window.draw(s_plane);
}

void Plane::move(std::vector<Lands>& squares)
{
	int x, y;
	x = s_bomb.getPosition().x / 50;
	y = s_bomb.getPosition().y / 50;
	int value = 22 * x + y;
	value = value + 1;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(s_bomb.getGlobalBounds()))
			s_bomb.setPosition(s_plane.getPosition().x + 50, s_plane.getPosition().y + 20);
	}
	s_bomb.move(0, 10);
	if (right) s_plane.move(8, 0);
	else s_plane.move(-8, 0);
	stage++;
	if (stage >= 100)
	{
		if (right)
		{
			right = false;
			s_plane.setTextureRect(sf::IntRect(80, 0, 80, 44));
		}
		else
		{
			right = true;
			s_plane.setTextureRect(sf::IntRect(0, 0, 80, 44));
		}
		stage = 0;
	}
}
