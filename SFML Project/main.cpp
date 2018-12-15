#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512),"SFML Tutorial" , sf::Style::Close | sf::Style::Resize);

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
	}


	return 0;
}