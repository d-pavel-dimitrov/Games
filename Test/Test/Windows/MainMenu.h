#ifndef MainMenu_H_
#define MainMenu_H_
#include <string>
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 4

class Menu {
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	std::string menuArray[MAX_NUMBER_OF_ITEMS] = {
		"Play",
		"Options",
		"Highscore",
		"Exit"
	};
public:
	Menu(const unsigned int& width, const unsigned int& height);
	~Menu();

	void draw(sf::RenderWindow &window);

	//navigate through the menu with up and down arrow keys 
	void MoveUp();
	void MoveDown(); 
};

#endif // !MainMenu_H_H
