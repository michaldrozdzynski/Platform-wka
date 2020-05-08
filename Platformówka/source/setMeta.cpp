#include "listOfFunction.h"

void setMeta(sf::Sprite& s_META, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);
		sf::Vector2f coord_pos = window.mapPixelToCoords(position);
		int x = coord_pos.x / 50;
		int y = coord_pos.y / 50;
		s_META.setPosition(x*50, y*50);
	}
}