#include "Map.h"

Map::Map(Size size) {
	int numberOfBlocks;
	int numberOfCrates;
	int rows;
	if (size == Size::Small) {
		numberOfBlocks = 20;
		numberOfCrates = 150;
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

	//Logic behind this BS
	//iterate through each row and every position where a block can be set
	//if its on  the row where there are blocks dont allow to be placed at that spot
	//or otherwise said x = blockSize + 2 * j*blockSize 
	int numberOfCratesPositions = 0;
	for (int i = 0; i < rows*2 - 1; ++i) {
		y = i*blockSize;

		if (i % 2 == 0) {
			numberOfCratesPositions = numberOfBlocks;
		}
		else {
			numberOfCratesPositions = numberOfBlocks*2 - 1;
		}

		for (int j = 0; j < numberOfCratesPositions; ++j) {
			if (numberOfCrates == 0) {
				break;
			}
			if (rand() % 4 == 0 ) {
				--numberOfCrates;
				if (i % 2 == 0) {
					x = blockSize + 2 * j*blockSize;
				}
				else {
					x = j*blockSize;
				}
				crates.push_back(Tile(true, false, false));
				crates[crates.size() - 1].moveSprite(x, y);
			}
		}
		if (numberOfCrates == 0) {
			break;
		}
	}

	mapWidth = numberOfBlocks * 2 * blockSize;// -blockSize; ??
	mapHeigth = rows * 2 * blockSize;// -blockSize; ??
}

void Map::draw(sf::RenderWindow& window) {
	for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].draw(window);
	}

	for (int i = 0; i < crates.size(); ++i) {
		crates[i].draw(window);
	}
}
