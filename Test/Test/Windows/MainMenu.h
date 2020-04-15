#ifndef MainMenu_H_
#define MainMenu_H_
#include <string>
#include <vector>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "menuDefines.h"
#include "..\Units\Unit.h"
#include "..\Units\UnitDefines.h"

#define MAX_NUMBER_OF_ITEMS 4

class Menu {
private:
	int selectedItemIndex;
	Unit unit = Unit("../Test/Assets/Characters/Jack", 0.12, sf::Vector2f(windowWidth / 2 - buttonsWidth*0.4 / 2 - 80, windowHeight / (MAX_NUMBER_OF_ITEMS + 1) - buttonsY*0.4 / 5 - 20), 25);
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture buttonTexture;
	sf::Texture logoTexture;
	std::vector<sf::Sprite> menuSprites;
	std::string menuArray[MAX_NUMBER_OF_ITEMS] = {
		"Play",
		"Options",
		"Highscore",
		"Exit"
	};

public:
	Menu(const unsigned int& width, const unsigned int& height);
	~Menu();

	void draw(sf::RenderWindow &window, int& windowMode);
	//navigate through the menu with up and down arrow keys 
	void MoveUp();
	void MoveDown();
	int getPressedItem() { return selectedItemIndex; }
};

#endif // !MainMenu_H_H
