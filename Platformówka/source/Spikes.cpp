#include "Spikes.h"

Spikes::Spikes(Textures& T, int position)
{
	s_spikes.setTexture(T.spikes);
	int y = position % 22;
	int x = position / 22;
	s_spikes.setPosition(x * 50, y*50 + 20);
	value = position;
}

void Spikes::draw(sf::RenderWindow& window)
{
	window.draw(s_spikes);
}
