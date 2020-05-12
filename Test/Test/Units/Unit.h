#ifndef UNIT_H_
#define UNIT_H_
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "UnitDefines.h"
#include "Tile.h"
#include "Bomb.h"

class Unit {
private:
	bool isDead = false;
	bool isDiplayed = false;
	int numberOfBombs = 1;
	float speed;
	Actions currentAction = Actions::Idle;
	unsigned int textureToLoad;
	std::vector<sf::Texture> idleTextures;
	std::vector<sf::Texture> runTextures;
	std::vector<sf::Texture> dieTextures;
	sf::Sprite sprite;
	void drawSpriteAction(std::vector<sf::Texture>& texture, Actions& action);
	bool isColliding(std::vector<Tile>& objects);
	Bomb* bomb;
public:
	Unit(const std::string& path, const float& opacity, sf::Vector2f startingPosition, float speed);
	//think about other way, prob getting all blocks and crates into 1vector
	void draw(sf::RenderWindow& window, Actions action, std::vector<Tile>& blocks = std::vector<Tile>(), std::vector<Tile>& crates = std::vector<Tile>());
	void movePosition(int x, int y);
	Bomb* getBomb() { return bomb; }
	bool getIsDead() const { return isDead; }
	bool getNumberOfBombs() const { return numberOfBombs; }
	sf::Vector2f getPosition() const { return sprite.getPosition(); }

	void setTextureToLoad(unsigned int pos) { this->textureToLoad = pos; }
	void setIsDead(const bool isDead) { this->isDead = isDead; }
	void setNumberOfBombs(const int numberOfBombs) { this->numberOfBombs = numberOfBombs; }
};
#endif // !UNIT_H_
