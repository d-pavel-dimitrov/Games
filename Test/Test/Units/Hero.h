#ifndef  Hero_H
#define Hero_H
#include "Unit.h"
#include "UnitDefines.h"
class Hero : public Unit {
private:
	int numberOfBombs = 1;
	Bomb* bomb;

public:
	Hero(const std::string& path, const float& opacity, sf::Vector2f startingPosition, float speed);
	bool getNumberOfBombs() const { return numberOfBombs; }
	Bomb* getBomb() { return bomb; }
	void setNumberOfBombs(const int numberOfBombs) { this->numberOfBombs = numberOfBombs; }
	void draw(sf::RenderWindow& window, Actions action, std::vector<Tile>& blocks = std::vector<Tile>(), std::vector<Tile>& crates = std::vector<Tile>());
};
#endif // ! Hero_H
