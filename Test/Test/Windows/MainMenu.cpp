#include <iostream>
#include "SFML\Graphics.hpp"
#include "MainMenu.h"
#include "menuDefines.h"

Menu::Menu(const unsigned int& width,const unsigned int& height) {
	if (!font.loadFromFile("../Test/Fonts/arial.ttf")) {
		std::cout << "Failed to load font" << std::endl;
	}
	selectedItemIndex = 0;

	//sprites[0].setTextureRect(sf::IntRect(buttonsX, buttonsY, buttonsWidth, buttonsHeight));
	//sprites[0] = buttonSprite;
	//sprites[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
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

	sf::Texture  buttonTexture;
	if (!buttonTexture.loadFromFile("../Test/Assets/GUI/Windows.png")) {
		std::cout << "Load failed" << std::endl;
	}
	unsigned int width = window.getSize().x;
	unsigned int height = window.getSize().y;
	double spriteWidth;
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		sf::Sprite buttonSprite;
		buttonSprite.setTexture(buttonTexture);
		buttonSprite.setTextureRect(sf::IntRect(buttonsX, buttonsY, buttonsWidth, buttonsHeight));
		buttonSprite.setScale(0.5, 0.4);
		spriteWidth = buttonTexture.getSize().x * buttonSprite.getScale().x;
		buttonSprite.setPosition(sf::Vector2f((width / 2 ), height / (MAX_NUMBER_OF_ITEMS + 1) *(i + 1)));
		window.draw(buttonSprite);

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