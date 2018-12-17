#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512),"SFML Tutorial" , sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Magenta);
	player.setOrigin(50.0f, 50.0f);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("Height = %i , Width = %i\n", evnt.size.height, evnt.size.width);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode<128)
				{
					printf("%c", evnt.text.unicode);
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.0f, -0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0.0f, 0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(0.5f, 0.0f);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}