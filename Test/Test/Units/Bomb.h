#ifndef BOMB_H_
#define BOMB_H_
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
class Bomb {
private:
	std::vector<sf::Texture> textures; // 0 for bomb 1 for explosion effect
	sf::Sprite bombSprite;
	std::vector<sf::Sprite> explosions;
	bool allowMovingThough;
	int explosionSize = 1;
	int spriteCounterX = 0;
	int spriteCounterY = 0;
	float explosionHeight = 130;
	float explosionWidth = 130;
public:
	Bomb(const sf::Vector2f& unitPosition);
	void draw(sf::RenderWindow& window);
	void explode(sf::RenderWindow& window);
	sf::Vector2f getPosition() const { return bombSprite.getPosition(); }
	void setPosition(const sf::Vector2f position) { bombSprite.setPosition(position); }
};
#endif // !BOMB_H_
