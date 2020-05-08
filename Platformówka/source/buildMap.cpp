#include "listOfFunction.h"
#include <iostream>

void buildMap(int type, sf::Event& event, sf::RenderWindow& window, std::vector<Lands>& squares)
{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i position = sf::Mouse::getPosition(window);
			sf::Vector2f coord_pos = window.mapPixelToCoords(position);
			int x = coord_pos.x/50;
			int y = coord_pos.y/50;
			int value = 22 * x + y;
			squares[value].changeSprite(type);
		}
}