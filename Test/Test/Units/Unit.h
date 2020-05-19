#ifndef UNIT_H_
#define UNIT_H_
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "UnitDefines.h"
#include "Tile.h"
#include "Bomb.h"

class Unit {
protected:
	Actions currentAction = Actions::Idle;
	bool isDead = false;
	bool isDiplayed = false;
	unsigned int textureToLoad;
	float speed;
	sf::Sprite sprite;
	std::vector<sf::Texture> idleTextures;
	std::vector<sf::Texture> runTextures;
	std::vector<sf::Texture> dieTextures;
	void drawSpriteAction(std::vector<sf::Texture>& texture, Actions& action);
	bool isColliding(std::vector<Tile>& objects);
public:
	Unit(const std::string& path, const float& opacity, sf::Vector2f startingPosition, float speed);

	bool getIsDead() const { return isDead; }

	sf::Vector2f getPosition() const { return sprite.getPosition(); }

	float getSpeed() const { return speed; }

	void movePosition(sf::RenderWindow& window, Actions& action, std::vector<sf::Texture>& textures, float x, float y, bool canMove);

	void setIsDead(const bool isDead) { this->isDead = isDead; }

	void setPosition(int x, int y);

	void setTextureToLoad(unsigned int pos) { this->textureToLoad = pos; }
};
#endif // !UNIT_H_
