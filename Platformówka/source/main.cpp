#include "listOfFunction.h"
#include "Textures.h"
#include <iostream>

int main()
{
	sf::VideoMode ekran = sf::VideoMode::getDesktopMode();

	sf::RenderWindow window(sf::VideoMode(ekran.width,ekran.height), "");
	sf::RectangleShape rectangle(sf::Vector2f(1920, 1080));
	rectangle.setFillColor(sf::Color(41, 202, 255));
	rectangle.setPosition(0, 0);

	sf::View view = window.getView() , currentview = window.getView();
	view.setSize(1920,1080);
	view.setCenter(960, 540);
	window.setView(view);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Textures T;
	T.loadTexture();

	sf::Sprite start;
	start.setTexture(T.START);
	start.setPosition(660, 300);

	sf::Sprite koniec;
	koniec.setTexture(T.KONIEC);
	koniec.setPosition(660, 600);

	sf::Sprite wygranko;
	wygranko.setTexture(T.win);
	wygranko.setPosition(660, 400);

	sf::Sprite przegranko;
	przegranko.setTexture(T.lose);
	przegranko.setPosition(660, 400);

	bool win = false;
	bool lose = false;

	sf::Event event;
	while (window.isOpen())
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (not win and not lose)
			{
				if (start.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)))
				{
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							int x = game(window, view, T);
							if (x == 1) win = true;
							else if (x == 2) lose = true;
							window.setView(window.getDefaultView());
							view = window.getView(),
							view.setCenter(960, 540);
							view.setSize(1920, 1080);
							window.setView(view);
						}
					}

				}
				if (koniec.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)))
				{
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							window.close();
						}
					}

				}
			}
			else if (win)
			{
				if (wygranko.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)))
				{
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							win = false;
						}
					}

				}
			}
			else if (lose)
		    {
				if (przegranko.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)))
				{
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							lose = false;
						}
					}

				}
			}

		}
		window.clear();
		window.draw(rectangle);
		if (win) window.draw(wygranko);
		else if (lose) window.draw(przegranko);
		else
		{
			window.draw(start);
			window.draw(koniec);
		}
		window.display();
	}
	return 0;
}  