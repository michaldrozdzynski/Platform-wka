#include "listOfFunction.h"
#include "cannon.h"
#include <iostream>
void buildObstacles(Textures& T, std::vector<Cannon>& cannon, 
	sf::RenderWindow& window, int type, std::vector<Spikes>& spikes,std::vector<Star>& star,  std::vector<Plane>& plane)
{
	//std::cout << "duda to super prezydent" << std::endl;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);
		sf::Vector2f coord_pos = window.mapPixelToCoords(position);
		int x = coord_pos.x / 50;
		int y = coord_pos.y / 50;
		int value = 22 * x + y;
		switch (type)
		{
		case 10:
		{
			cannon.push_back(Cannon(T, value));
		}
		break;
		case 11:
		{
			spikes.push_back(Spikes(T, value));
		}
		break;
		case 12:
		{
			star.push_back(Star(T, value));
		}
		break;
		case 13:
		{
			plane.push_back(Plane(T, value));
		}
		break;
		}
	}

}