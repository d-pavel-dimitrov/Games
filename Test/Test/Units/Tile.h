#ifndef Tile_H_
#define Tile_H_
#include <iostream>
#include "SFML\Graphics.hpp"
 
class Tile {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	bool canDestroy;
	bool hasKey;
	bool hasGate;
public:
	Tile(bool canDestroy, bool hasKey, bool hasGate);
	void setKey(bool hasKey) { this->hasKey = hasKey; }
	void setGate(bool hasGate) { this->hasGate = hasGate; }
	void moveSprite(int x, int y) { sprite.move(x, y); }

	bool getKey() const { return hasKey; }
	bool getGate() const { return hasGate; }
	bool destroy() const { return canDestroy; }

	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};

#endif // !Tile_H_
