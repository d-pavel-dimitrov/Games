#include "Tile.h"

Tile::Tile() : canDestroy(false), hasKey(false), hasGate(false) {
	texture = new sf::Texture;
	if (!(*texture).loadFromFile("../Test/Assets/Objects/Tiles/StoneBlock.png")) {
		std::cout << "Didn't load texture for TILE stoneBlock.png" << std::endl;
	}
	sprite.setTexture((*texture));
	sprite.setPosition(0, 0);
	sprite.setScale(0.4, 0.4);
}

Tile::Tile(bool canDestroy, bool hasKey, bool hasGate) 
	: canDestroy(canDestroy), hasKey(hasKey), hasGate(hasGate) {
	texture = new sf::Texture;
	if (canDestroy) {
		if (!(*texture).loadFromFile("../Test/Assets/Objects/Tiles/StoneBlock.png")) {
			std::cout << "Didn't load texture for TILE stoneBlock.png" << std::endl;
		}
	} else {
		if (!(*texture).loadFromFile("../Test/Assets/Objects/Tiles/Crate.png")) {
			std::cout << "Didn't load texture for TILE Crate.png" << std::endl;
		}
	}
	sprite.setTexture((*texture));
	sprite.setPosition(0, 0);
	sprite.setScale(0.4, 0.4);
}