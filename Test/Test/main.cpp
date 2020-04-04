#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows\MainMenu.h"
#include "Windows\menuDefines.h"
#include "Units\Unit.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bomberman");
	sf::Time animationTime;
	int frameTime = 50;
	Menu menu(window.getSize().x, window.getSize().y);
	Unit unit("../Test/Assets/Characters/Jack", 0.12, sf::Vector2f(windowWidth / 2 - buttonsWidth*0.4 / 2 - 80, windowHeight / (MAX_NUMBER_OF_ITEMS + 1) - buttonsY*0.4 / 5 - 20), 25);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.MoveUp();
							unit.movePosition(0,-165);
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							unit.movePosition(0, 165);
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

		//look clock and see to slow down animation
		unit.draw(window, Actions::Idle);
		window.display();
	}
	return 0;
}