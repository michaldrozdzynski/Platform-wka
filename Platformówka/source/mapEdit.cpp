#include "listOfFunction.h"

int mapEdit(sf::RenderWindow& toolsWindow, Textures& T)
{
	static int toReturn = 0;
	std::vector<Lands> tools;
	tools.push_back(Lands(T, 2, 2, 1));
	tools.push_back(Lands(T, 4, 2, 2));
	tools.push_back(Lands(T, 2, 4, 3));
	tools.push_back(Lands(T, 4, 4, 4));
	sf::Event event;
	while (toolsWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			toolsWindow.close();
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{
				if (tools[i].position.contains(sf::Vector2f((sf::Mouse::getPosition(toolsWindow)))))
					toReturn = i + 1;
				break;
			}
		}
	}//while
		toolsWindow.clear();
		toolsWindow.draw(tools[0].s_land);
		toolsWindow.draw(tools[1].s_land);
		toolsWindow.draw(tools[2].s_land);
		toolsWindow.draw(tools[3].s_land);
		toolsWindow.display();

	return toReturn;
}