#include "Bomb.h"
//ToDo
//Change scales and texture rect for explosion and bomb
Bomb::Bomb(const sf::Vector2f& unitPosition) {
	textures.push_back(sf::Texture());
	textures.push_back(sf::Texture());
	if (!textures[0].loadFromFile("../Test/Assets/Objects/Bombs/bomb.png")) {
		std::cout << "Didnt load png for bomb (bomb.png)." << std::endl;
	}
	bombSprite.setTexture(textures[0]);
	bombSprite.setScale(0.5, 0.5); //change scale later to match
	bombSprite.setPosition(unitPosition);

	if (!textures[1].loadFromFile("../Test/Assets/Objects/Bombs/explosion.png")) {
		std::cout << "Didnt load pgn for bomb (bomb.png)." << std::endl;
	}
	
	for (int i = 0; i < explosionSize * 4; ++i) {
		explosions.push_back(sf::Sprite());
		explosions[i].setTexture(textures[1]);
		explosions[i].setPosition(unitPosition); // set position to middle
	}
}

void Bomb::draw(sf::RenderWindow& window) {
	window.draw(bombSprite);
}

void Bomb::explode(sf::RenderWindow& window) {

	sf::Vector2f position = bombSprite.getPosition();
	float width = bombSprite.getGlobalBounds().width;
	float heigth = bombSprite.getGlobalBounds().height;
	for (int i = 0; i < explosions.size(); i++) {
		explosions[i].setPosition(bombSprite.getPosition());
		explosions[i].setTextureRect(sf::IntRect(spriteCounterX*explosionWidth, spriteCounterX*explosionHeight, explosionWidth, explosionHeight)); // see from png pixels for each  animaton
		explosions[i].setScale(0.4, 0.4);  // change scale to match

	}
	explosions[0].move(sf::Vector2f(-(width + 15), 0));
	explosions[1].move(sf::Vector2f(width - 15, 0));
	explosions[2].move(sf::Vector2f(-15, -heigth));
	explosions[3].move(sf::Vector2f(-15, heigth));

	for (int i = 0; i < explosions.size(); i++) {
		window.draw(explosions[i]);
	}
	if (spriteCounterX > 6) {
		spriteCounterX = 0;
		spriteCounterY++;
		if (spriteCounterY > 6) {
			spriteCounterY = 0;
		}
	}
	spriteCounterX++;
}

void Bomb::isExplosionColidingWithCrates(std::vector<Tile>& crates) {
	sf::FloatRect crate;
	for (int i = 0; i < explosions.size(); ++i) {
		std::vector<Tile>::iterator itr = crates.begin();
		while (itr != crates.end())
		{
			crate = itr->getBounds();
			crate.width = crate.width - 15;
			crate.height = crate.height - 15;
			if (explosions[i].getGlobalBounds().intersects(crate)) {
				crates.erase(itr);
				//--itr??
				break;
			}
			++itr;
		}
	}
}
