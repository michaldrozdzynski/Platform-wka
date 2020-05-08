#include "listOfFunction.h"
#include <iostream>



bool canHeroGoRight(std::vector<Lands>& squares, Hero& player)
{
	sf::RectangleShape rectangle(sf::Vector2f(1, 100));
	rectangle.setPosition(player.s_hero.getPosition().x + 66, player.s_hero.getPosition().y);
	int x, y;
	x = rectangle.getPosition().x / 50;
	y = rectangle.getPosition().y / 50;
	int value = 22 * x + y;

	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
	value = value + 1;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{

		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}

	value = value + 1;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
		

	return true;
}

bool canHeroGoLeft(std::vector<Lands>& squares, Hero& player)
{
	if (player.s_hero.getPosition().x < 50) return false;
	sf::RectangleShape rectangle(sf::Vector2f(1, 100));
	rectangle.setPosition(player.s_hero.getPosition().x -1, player.s_hero.getPosition().y);
	int x, y;
	x = rectangle.getPosition().x / 50;
	y = rectangle.getPosition().y / 50;
	int value = 22 * x + y;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
	value = value + 1;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
	
	value = value + 1;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
	

	return true;
}

bool canHeroJump(std::vector<Lands>& squares, Hero& player)
{
	

	sf::RectangleShape rectangle(sf::Vector2f(40, 1));
	rectangle.setPosition(player.s_hero.getPosition().x + 13, player.s_hero.getPosition().y - 1);
	int x, y;
	x = rectangle.getPosition().x / 50;
	y = rectangle.getPosition().y / 50;
	int value = 22 * x + y;
	//value--;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}
	value += 22;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return false;
	}

	return true;
}

bool canHeroStay(std::vector<Lands>& squares, Hero& player)
{
	sf::RectangleShape rectangle(sf::Vector2f(40, 1));
	rectangle.setPosition(player.s_hero.getPosition().x + 13, player.s_hero.getPosition().y+100);
	int x, y;
	x = rectangle.getPosition().x / 50;
	y = rectangle.getPosition().y / 50;
	int value = 22 * x + y;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return true;
	}
	value += 22;
	if (value >= 0 and value < squares.size() and squares[value].type != 5)
	{
		//squares[value].changeSprite(0);
		if (squares[value].s_land.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
			return true;
	}

	return false;
}