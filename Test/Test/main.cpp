#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows\MainMenu.h"
#include "Windows\menuDefines.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bomberman");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Return:
							//press event for every button
							switch (menu.getPressedItem()) {
							case 0:
								break;
							}
							break;
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
		}

		window.clear();
		menu.draw(window);
		window.display();
	}
	return 0;
}