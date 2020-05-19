#include "Hero.h"

Hero::Hero(const std::string& path, const float& opacity, sf::Vector2f startingPosition, float speed) : Unit( path, opacity,  startingPosition, speed) {
	bomb = new Bomb(sprite.getPosition());

}
void Hero::draw(sf::RenderWindow& window, Actions action, std::vector<Tile>& blocks, std::vector<Tile>& crates) {
	bool collides;
	switch (action)
	{
	case Idle:
		this->movePosition(window, action, idleTextures, 0, 0, true);
		break;
	case RunLeft:
		sprite.move(-speed, 0);
		collides = (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().x < 0);
		this->movePosition(window, action, runTextures, -speed, 0, collides);
		break;
	case RunRight:
		sprite.move(speed, 0);
		collides = this->isColliding(blocks) || this->isColliding(crates);
		this->movePosition(window, action, runTextures, speed, 0, collides);
		break;
	case RunTop:
		sprite.move(0, -speed);
		collides = (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().y < 0);
		this->movePosition(window, action, runTextures, 0, -speed, collides);
		break;
	case RunBottom:
		sprite.move(0, speed);
		collides = (this->isColliding(blocks) || this->isColliding(crates));
		this->movePosition(window, action, runTextures, 0, speed, collides);
	case Die:
		this->movePosition(window, action, dieTextures, 0, 0, true);
		break;
	}
	//window.draw(sprite);
	//currentAction = action;
}
