#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include <stdlib.h> // rand()
#include "SFML\Graphics.hpp"
#include "..\Units\Tile.h"
#include "MapDefines.h"
#include "..\Units\Hero.h"
#include "..\Units\UnitDefines.h"
//ToDo:
//check mapHeigth, mapWidth is correct
//
class Map {
private:
	unsigned int mapWidth;
	unsigned int mapHeigth;
	Size size;
	std::vector<Tile> crates;
	std::vector<Tile> blocks;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	Hero* hero = nullptr; // will change class later, only to check if move correctly and set collisions
	//add enemies
	//add hero
public:
	Map(Size size);
	~Map() { if (hero != nullptr) { delete hero; } }
	void draw(sf::RenderWindow& window, int& windowMode, sf::Clock& clock);
	//~Map(); // if i create dynamical texture should be removed 
};
#endif // !MAP_H_
