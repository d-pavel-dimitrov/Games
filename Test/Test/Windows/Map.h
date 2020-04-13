#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include <stdlib.h> // rand()
#include "SFML\Graphics.hpp"
#include "..\Units\Tile.h"
#include "MapDefines.h"
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
	//add enemies
	//add hero
public:
	Map(Size size);
	void draw(sf::RenderWindow& window);
	//~Map(); // if i create dynamical texture should be removed 
};
#endif // !MAP_H_
