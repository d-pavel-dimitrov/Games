#include "Map.h"

Map::Map(Size size) {
	int numberOfBlocks;
	int rows;
	if (size == Size::Small) {
		numberOfBlocks = 20;
		rows = 10;
		if (!backgroundTexture.loadFromFile("../Test/Assets/Objects/Textures/concrete368.png")) {
			std::cout << "Didn't load texture for background image concrete368.png" << std::endl;
		}
	}
	/*else if (size == Size::Medium) {
		numberOfBlocks = 9;
		rows = 7;
	}
	else {
		numberOfBlocks = 9;
		rows = 9;
	}*/
	
	int y = 0;
	int x = 0;
	Tile tile;
	int blockSize = tile.getBlockSize();

	for (int i = 0; i < rows; ++i) {
		y = 2*i*blockSize;
		for (int j = 0; j < numberOfBlocks; ++j) {
			x = 2*j*blockSize;
			blocks.push_back(Tile());
			blocks[blocks.size() - 1].moveSprite(x, y);
		}
	}
}

void Map::draw(sf::RenderWindow& window) {
	for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].draw(window);
	}
}
