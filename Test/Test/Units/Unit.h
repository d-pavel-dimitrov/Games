#ifndef UNIT_H_
#define UNIT_H_
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "UnitDefines.h"

class Unit {
private:
	bool isDead;
	int speed;
	Actions currentAction = Actions::Idle;
	unsigned int textureToLoad;
	std::vector<sf::Texture> idleTextures;
	std::vector<sf::Texture> runTextures;
	std::vector<sf::Texture> dieTextures;
	sf::Sprite sprite;
public:
	Unit(const std::string& path, const double& opacity, sf::Vector2f startingPosition, int speed);
	void draw(sf::RenderWindow& window, Actions action);
	void drawSpriteAction(std::vector<sf::Texture>& texture, Actions& action);
	void movePosition(int x, int y);
};
#endif // !UNIT_H_
