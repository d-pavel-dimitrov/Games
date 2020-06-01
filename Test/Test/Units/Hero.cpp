#include "Hero.h"

Hero::Hero(const std::string& path, const float& opacity, sf::Vector2f startingPosition, float speed) : Unit( path, opacity,  startingPosition, speed) {
	bomb = new Bomb(sprite.getPosition());

}
void Hero::draw(sf::RenderWindow& window, Actions action, const unsigned int& mapWidth, std::vector<Tile>& blocks, std::vector<Tile>& crates) {
	bool collides;
	sf::View view = window.getView();
	float heroPosX = sprite.getPosition().x;
	float centerViewPosition = view.getCenter().x;
	float viewWidth = view.getSize().x;

	switch (action)
	{
	case Idle:
		this->animateMovement(window, action, idleTextures, 0, 0, true);
		break;
	case RunLeft:
		sprite.move(-speed, 0);
		collides = (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().x < 0);
		if (!collides && centerViewPosition - viewWidth / 2> 0) {
			view.move(-1, .0f);
			window.setView(view);
		}
		this->animateMovement(window, action, runTextures, -speed, 0, collides);
		break;
	case RunRight:
		sprite.move(speed, 0);
		collides = this->isColliding(blocks) || this->isColliding(crates);
		if (!collides) {
 			
			if (heroPosX > centerViewPosition && centerViewPosition < mapWidth - viewWidth/2) {
				view.move(1, .0f);
				window.setView(view);
			}
		}
		this->animateMovement(window, action, runTextures, speed, 0, collides);
		break;
	case RunTop:
		sprite.move(0, -speed);
		collides = (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().y < 0);
		this->animateMovement(window, action, runTextures, 0, -speed, collides);
		break;
	case RunBottom:
		sprite.move(0, speed);
		collides = (this->isColliding(blocks) || this->isColliding(crates));
		this->animateMovement(window, action, runTextures, 0, speed, collides);
		break;
	case Die:
		this->animateMovement(window, action, dieTextures, 0, 0, true);
		break;
	}
}
