#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
#include "..\Units\Tile.h"
#include "MapDefines.h"

class Map {
private:
	unsigned int mapWIdth;
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
