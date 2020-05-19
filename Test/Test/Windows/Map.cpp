#include "Map.h"
float milisecTillExplosion = -1;
bool isBombTriggered = false;
float milisecExposion = 2000;
Map::Map(Size size) {
	int numberOfBlocks; // number of blocks to generate
	int numberOfCrates; // number of crates to generate
	int rows; // number of rows on the map that have blocks
	int y = 0; //y pos of block/crate
	int x = 0; // x pos of block/crate
	int blockSize = 45; // get size of block to calculate map size etc

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

	hero = new Hero("../Test/Assets/Characters/Jack", 0.05f, sf::Vector2f(blockSize + 10, 0), 0.6f);

}

void Map::draw(sf::RenderWindow& window, int& windowMode, sf::Clock& clock) {
	sf::Event event;
	Actions heroAction = Idle;
	sf::View view = window.getView();

	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		heroAction = RunTop;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		heroAction = RunBottom;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		heroAction = RunRight;
		float viewWidth = window.getView().getSize().x;
		float heroPosX = hero->getPosition().x;
		float moveView = 100;
		if (heroPosX + moveView > mapWidth) {
			moveView = (heroPosX + moveView) - mapWidth;
		}
		else if (mapWidth == viewWidth) {
			moveView = 0;
		}

 		if (hero->getPosition().x > viewWidth) {

			view.move(1, .0f);
			window.setView(view);
		}
		
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		heroAction = RunLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (hero->getNumberOfBombs() > 0) {
			milisecTillExplosion = clock.getElapsedTime().asMilliseconds() + 3000;
			isBombTriggered = true;
			hero->setNumberOfBombs(0);
		}
	}
	else {
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

	if (milisecTillExplosion > 0) {
		Bomb* bomb = hero->getBomb();
		if (isBombTriggered) {
			bomb->setPosition(hero->getPosition());
		}

		if (clock.getElapsedTime().asMilliseconds() < milisecTillExplosion) {
			bomb->draw(window);
			isBombTriggered = false;
		}
		else if (clock.getElapsedTime().asMilliseconds() > milisecTillExplosion && clock.getElapsedTime().asMilliseconds() < milisecTillExplosion + milisecExposion) {
			hero->getBomb()->explode(window);
		}
		else {
			hero->getBomb()->isExplosionColidingWithCrates(crates);
			hero->setNumberOfBombs(1);
		}
	}
	hero->draw(window, heroAction, blocks, crates);
}
