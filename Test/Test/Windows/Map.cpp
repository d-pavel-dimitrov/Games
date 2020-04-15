#include "Map.h"

Map::Map(Size size) {
	int numberOfBlocks; // number of blocks to generate
	int numberOfCrates; // number of crates to generate
	int rows; // number of rows on the map that have blocks
	int y = 0; //y pos of block/crate
	int x = 0; // x pos of block/crate
	Tile tile;
	int blockSize = tile.getBlockSize(); // get size of block to calculate map size etc

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
			if ((i == 1 && j < 3) || (i == 0 && j <2)) {
				continue;
			}
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
	int keyCrate = rand() % crates.size() - 1;
	int gateCrate;

	//generate key and gate 
	//while loop is used so there wont be gate and key in one crate
	crates[keyCrate].setKey(true);
	bool success = false;
	while (!success) {
		gateCrate = rand() % crates.size() - 1;
		if (keyCrate != gateCrate) {
			success = true;
			crates[gateCrate].setGate(true);
			break;
		}
	}

	mapWidth = numberOfBlocks * 2 * blockSize;// -blockSize; ??
	mapHeigth = rows * 2 * blockSize;// -blockSize; ??
	backgroundSprite.setTexture(backgroundTexture);
	float ScaleX = (float)mapWidth / backgroundTexture.getSize().x;
	float ScaleY = (float)mapHeigth / backgroundTexture.getSize().y;
	backgroundSprite.setScale(ScaleX, ScaleY);

	hero = new Unit("../Test/Assets/Characters/Jack", 0.05, sf::Vector2f(blockSize, 0), 0.6);
}

void Map::draw(sf::RenderWindow& window, int& windowMode) {
	sf::Event event;
	Actions heroAction = Idle;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			heroAction = RunTop;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			heroAction = RunBottom;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			heroAction = RunRight;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			heroAction = RunLeft;
		}	else {
			heroAction = Idle;
		}

		window.clear();
		window.draw(backgroundSprite);
		for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].draw(window);
		}

		for (int i = 0; i < crates.size(); ++i) {
		crates[i].draw(window);
		}
		hero->draw(window, heroAction);
}
