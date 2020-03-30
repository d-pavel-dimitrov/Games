#include "MainMenu.h"

Menu::Menu(const unsigned int& width,const unsigned int& height) {
	if (!font.loadFromFile("../Test/Fonts/arial.ttf")) {
		// hadnle error
	}
	selectedItemIndex = 0;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		menu[i].setFont(font);
		if (selectedItemIndex == i) {
			menu[i].setFillColor(sf::Color::Red);
		}
		else {
			menu[i].setFillColor(sf::Color::White);
		}
		menu[i].setString(menuArray[i]);
		menu[i].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));
	}
	
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		window.draw(menu[i]);
	}
}

//navigate through the menu with up and down arrow keys 
void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}