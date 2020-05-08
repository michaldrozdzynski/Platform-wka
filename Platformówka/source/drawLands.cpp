#include "listOfFunction.h"

void drawLands(std::vector<Lands>& squares, sf::RenderWindow& window)
{
	for (std::vector<Lands>::iterator itr = squares.begin(), koniec = squares.end(); itr != koniec; ++itr)
	{
		window.draw(itr->s_land);
	}
}