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
	sf::Clock bombTimer;
	sf::Clock clock; //timerstart to run after init
	// 0 - main menu , 1 game, 2 options, 3exit
	int windowMode = 0;
	while (window.isOpen()) {
		if (windowMode == 0) {
			menu.draw(window, windowMode);		
		}
		else if (windowMode == 1) {
			map.draw(window, windowMode, bombTimer);
		}

		elapsed = clock.getElapsedTime();
		if (elapsed > spriteRefreshRate) {
			window.display();
			clock.restart();
		}

	}
	return 0;
}