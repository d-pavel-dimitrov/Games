#ifndef Tile_H_
#define Tile_H_
#include <iostream>
#include "SFML\Graphics.hpp"
//ToDo:
//see how it renders and change tile scale
//
//
class Tile {
private:
	//make variable same for all future creations
	sf::Texture* texture = nullptr;
	sf::Sprite sprite;
	bool canDestroy;
	bool hasKey;
	bool hasGate;
public:
	Tile();
	Tile(bool canDestroy, bool hasKey, bool hasGate);
	//~Tile() { if (texture != nullptr) { delete texture; } }
	void setKey(bool hasKey) { this->hasKey = hasKey; }
	void setGate(bool hasGate) { this->hasGate = hasGate; }
	//when declared the position of the tile is set to 0,0
	void moveSprite(int x, int y) { sprite.move(x, y); }

	bool getKey() const { return hasKey; }
	bool getGate() const { return hasGate; }
	bool destroy() const { return canDestroy; }
	//getBlockSize return size of tile (usually all tiles should have the same width height and scale)
	int getBlockSize() const { return (*texture).getSize().x*sprite.getScale().x; }

	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};

#endif // !Tile_H_
