#ifndef UNIT_H_
#define UNIT_H_
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "UnitDefines.h"

class Unit {
private:
	bool isDead;
	float speed;
	Actions currentAction = Actions::Idle;
	unsigned int textureToLoad;
	std::vector<sf::Texture> idleTextures;
	std::vector<sf::Texture> runTextures;
	std::vector<sf::Texture> dieTextures;
	sf::Sprite sprite;
	void drawSpriteAction(std::vector<sf::Texture>& texture, Actions& action);
public:
	Unit(const std::string& path, const double& opacity, sf::Vector2f startingPosition, float speed);
	void draw(sf::RenderWindow& window, Actions action);
	void movePosition(int x, int y);
	void setTextureToLoad(unsigned int pos) { this->textureToLoad = pos; }
};
#endif // !UNIT_H_
