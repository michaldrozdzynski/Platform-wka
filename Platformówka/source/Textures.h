#pragma once
#include <SFML/Graphics.hpp>

class Textures
{
public:
	sf::Texture hero;
	sf::Texture lands;
	sf::Texture border;
	sf::Texture cannon;
	sf::Texture bullet;
	sf::Texture spikes;
	sf::Texture star;
	sf::Texture lift;
	sf::Texture plane;
	sf::Texture bomb;
	sf::Texture META;
	sf::Texture START;
	sf::Texture KONIEC;
	sf::Texture win;
	sf::Texture lose;
	void loadTexture();
};

