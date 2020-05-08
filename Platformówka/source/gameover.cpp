#include "listOfFunction.h"
#include <iostream>

bool gameover(std::vector<Cannon>& cannon, std::vector<Spikes>& spikes, std::vector<Star>& star, std::vector<Plane>& plane, Hero& player)
{
	sf::FloatRect pozycja = player.s_hero.getGlobalBounds();
	for (std::vector<Cannon>::iterator itr = cannon.begin(), koniec = cannon.end(); itr != koniec; ++itr)
	{
		if (itr->s_bullet.getGlobalBounds().intersects(pozycja))
		{
			itr->s_bullet.setPosition(itr->s_cannon.getPosition().x, itr->s_cannon.getPosition().y + 17);
			return true;
		}
		if (itr->s_cannon.getGlobalBounds().intersects(pozycja))
			return true;
	}
	for (std::vector<Spikes>::iterator itr = spikes.begin(), koniec = spikes.end(); itr != koniec; ++itr)
	{
		if (itr->s_spikes.getGlobalBounds().intersects(pozycja))
			return true;
	}
	for (std::vector<Star>::iterator itr = star.begin(), koniec = star.end(); itr != koniec; ++itr)
	{
		int x = itr->s_star.getPosition().y - player.s_hero.getPosition().y;
		
		if (itr->s_star.getPosition().y - player.s_hero.getPosition().y < 110 and itr->s_star.getGlobalBounds().intersects(pozycja))
		{
			std::cout << x;
			return true;
		}
	}
	for (std::vector<Plane>::iterator itr = plane.begin(), koniec = plane.end(); itr != koniec; ++itr)
	{
		if (itr->s_bomb.getGlobalBounds().intersects(pozycja))
		{
			itr->s_bomb.setPosition(itr->s_plane.getPosition().x + 50, itr->s_plane.getPosition().y + 20);
			return true;
		}
		if (itr->s_plane.getGlobalBounds().intersects(pozycja))
			return true;
	}
	return false;
}