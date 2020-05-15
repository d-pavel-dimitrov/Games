#include "Unit.h"

//path - point to the folder which contains all the images
//exampe path ../Test/Assets/Characters/Jack
Unit::Unit(const std::string& path, const float& opacity,sf::Vector2f startingPosition, float speed)
	: textureToLoad(0), speed(speed) {
	//load
	int i = 0;
	sf::Texture temp;
	//loads all idle textures
	while (temp.loadFromFile(path + "/Idle__" + std::to_string(i) + ".png")) {
		
		idleTextures.push_back(temp);
		i++;
	}

	//loads all run textures
	i = 0;
	while (temp.loadFromFile(path + "/Run__" + std::to_string(i) + ".png")) {
		runTextures.push_back(temp);
		i++;
	}

	//loads all dead textures
	i = 0;
	while (temp.loadFromFile(path + "/Dead__" + std::to_string(i) + ".png")) {
		dieTextures.push_back(temp);
		i++;
	}

	sprite.setScale(opacity, opacity);
	sprite.setPosition(startingPosition);

	bomb = new Bomb(sprite.getPosition());
}
//optimize??
void Unit::draw(sf::RenderWindow& window, Actions action, std::vector<Tile>& blocks, std::vector<Tile>& crates) {
	switch (action)
	{
	case Idle:
		drawSpriteAction(idleTextures, action);
		break;
	case RunLeft:
		//mirror image when running
		sprite.move(-speed, 0);
		if (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().x < 0) {
			sprite.move(speed, 0);
		}
		drawSpriteAction(runTextures, action);
		break;
	case RunRight:
		sprite.move(speed, 0);
		if (this->isColliding(blocks) || this->isColliding(crates)) {
			sprite.move(-speed, 0);
		}
		drawSpriteAction(runTextures, action);
		break;
	case RunTop:
		sprite.move(0, -speed);
		if (this->isColliding(blocks) || this->isColliding(crates) || this->sprite.getPosition().y < 0) {
			sprite.move(0, speed);
		}
		drawSpriteAction(runTextures, action);
		break;
	case RunBottom:
		sprite.move(0, speed);
		if (this->isColliding(blocks) || this->isColliding(crates)) {
			sprite.move(0, -speed);
		}
		drawSpriteAction(runTextures, action);
		break;
	case Die:
		drawSpriteAction(dieTextures, action);
		break;
	}
	window.draw(sprite);
	currentAction = action;
}

void Unit::drawSpriteAction( std::vector<sf::Texture>& texture, Actions& action) {
	bool  isFlipped = false;
	++textureToLoad;

	if (textureToLoad >  texture.size() - 1 || action != currentAction) {
		textureToLoad = 0;
	}
	int width = texture[textureToLoad].getSize().x;
	int height = texture[textureToLoad].getSize().y;
	if (action == RunLeft) {
		sprite.setTextureRect(sf::IntRect(width, 0, -width, height));
	}
	else if (action == RunRight) {
		sprite.setTextureRect(sf::IntRect(0, 0, width, height));
	}

	sprite.setTexture(texture[textureToLoad]);

	return;
}

//add x and y to the current position of the sprite
void Unit::movePosition(int x, int y) {
	float posX = sprite.getPosition().x;
	float posY = sprite.getPosition().y;
	if (posY + y > 123 && posY + y < 620) {
		sprite.move(sf::Vector2f(x, y));
	}
}

bool Unit::isColliding(std::vector<Tile>& objects) {
	sf::FloatRect object;
	for (int i = 0; i < objects.size(); ++i) {
		object = objects[i].getBounds();
		object.width = object.width - 10;
		object.height = object.height - 10;
		if (sprite.getGlobalBounds().intersects(object)) {
			return true;
		}
	}
	return false;
}

