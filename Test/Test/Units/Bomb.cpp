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
	sf::Sprite sprite;
	for (int i = 0; i < explosionSize * 4; ++i) {
		sprite.setTexture(textures[1]);
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0)); // see from png pixels for each  animaton
		//sprite.setScale(0.5, 0.5);  // change scale to match
		sprite.setPosition(unitPosition); // set position to middle
		explosions.push_back(sprite);
	}
}

void Bomb::draw(sf::RenderWindow& window) {
	window.draw(bombSprite);
	sf::Time explodeTime = sf::seconds(3);
	//sf::Clock clock;
	//while(clock.getElapsedTime() < explodeTime) { } // very dirty method to draw  find other way
	sf::Vector2f position = bombSprite.getPosition();
	float width = bombSprite.getGlobalBounds().width;
	float heigth = bombSprite.getGlobalBounds().height;
	for (int i = 0; i < explosionSize; i++) {
		for (int j = 0; j < explosions.size() / explosionSize; j++) {
			explosions[j + explosionSize*i].move(sf::Vector2f(-width*(i+1), 0));
			explosions[j + explosionSize*i].move(sf::Vector2f(width*(i + 1), 0));
			explosions[j + explosionSize*i].move(sf::Vector2f(0, -heigth*(i + 1)));
			explosions[j + explosionSize*i].move(sf::Vector2f(0, heigth*(i + 1)));
			std::cout << explosions[j + explosionSize*i].getPosition().x << std::endl;
		}
	}


}

void Bomb::explode(sf::RenderWindow& window) {
	for (int i = 0; i < explosions.size(); i++) {
		window.draw(explosions[i]);
	}
}