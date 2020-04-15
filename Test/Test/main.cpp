#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows\MainMenu.h"
#include "Windows\menuDefines.h"
#include "Units\Unit.h"
#include "Windows\Map.h"
#include "Windows\MapDefines.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bomberman");

	//menu
	Menu menu(window.getSize().x, window.getSize().y);
	
	//map
	Map map(Size::Small);

	//timers
	sf::Time spriteRefreshRate = sf::milliseconds(50);
	sf::Time elapsed;
	sf::Clock clock; //timerstart to run after init
	// 0 - main menu , 1 game, 2 options, 3exit
	int windowMode = 0;
	while (window.isOpen()) {
		/*sf::Event event;
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
							windowMode = menu.getPressedItem() + 1;
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

		window.clear();*/
		if (windowMode == 0) {
			menu.draw(window, windowMode);		
		}
		else if (windowMode == 1) {
			map.draw(window, windowMode);
		}

		elapsed = clock.getElapsedTime();
		if (elapsed > spriteRefreshRate) {
			window.display();
			clock.restart();
		}

	}
	return 0;
}