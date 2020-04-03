#ifndef UNIT_H_
#define UNIT_H_
#include <vector>
#include "SFML\Graphics.hpp"
#include "UnitDefines.h"

class Unit {
private:
	int health; //unsigned??
	int speed;
	//width height for texture??
	std::vector<sf::Texture> texture;
	sf::Sprite sprite;
public:
	Unit(const int& width, const int& height,const std::string& path, const int& opacity, sf::Vector2f& position);
	void draw(sf::RenderWindow& window, Actions action);
};
#endif // !UNIT_H_
