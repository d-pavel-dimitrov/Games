#include "MainMenu.h"

Menu::Menu(const unsigned int& width,const unsigned int& height) {
	if (!font.loadFromFile("../Test/Fonts/arial.ttf")) {
		std::cout << "Failed to load font" << std::endl;
	}
	selectedItemIndex = 0;
	if (!buttonTexture.loadFromFile("../Test/Assets/GUI/Windows.png") || !logoTexture.loadFromFile("../Test/Assets/GUI/logo.png")) {
		std::cout << "Didn't load textures" << std::endl;
	}
	double buttonOpacity = 0.4;
	sf::Sprite sprite;
	sprite.setTexture(logoTexture);
	sprite.setScale(0.15, 0.15);
	sprite.setPosition(sf::Vector2f(windowWidth - logoTexture.getSize().x*0.17 ,0));
	menuSprites.push_back(sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		menu[i].setFont(font);
		if (selectedItemIndex == i) {
			menu[i].setFillColor(sf::Color::Red);
		}
		else {
			menu[i].setFillColor(sf::Color::White);
		}
		menu[i].setString(menuArray[i]);
		menu[i].setPosition(sf::Vector2f(width / 2 - menu[i].getLocalBounds().width / 2, (height) / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));

		sprite.setTexture(buttonTexture);
		sprite.setTextureRect(sf::IntRect(buttonsX, buttonsY, buttonsWidth, buttonsHeight));
		sprite.setScale(buttonOpacity, buttonOpacity);
		sprite.setPosition(sf::Vector2f(windowWidth / 2 - buttonsWidth*buttonOpacity / 2,
			((height) / (MAX_NUMBER_OF_ITEMS + 1) *(i + 1)) - buttonsY*buttonOpacity / 5));
		menuSprites.push_back(sprite);
	}

}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window, int& windowMode) {

	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->MoveUp();
				unit.movePosition(0, -165);
				break;
			case sf::Keyboard::Down:
				this->MoveDown();
				unit.movePosition(0, 165);
				break;
			case sf::Keyboard::Return:
				//press event for every button
				windowMode = this->getPressedItem() + 1;
				switch (this->getPressedItem()) {
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
	sf::Sprite buttonSprite;
	//first element is the logo
	window.draw(menuSprites[0]);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		window.draw(menuSprites[i+1]);
		window.draw(menu[i]);
	}

	unit.draw(window, Actions::Idle);
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