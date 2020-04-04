#include "Unit.h"

//path - point to the folder which contains all the images
//exampe path ../Test/Assets/Characters/Jack
Unit::Unit(const std::string& path, const double& opacity,sf::Vector2f startingPosition, int speed)
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

}
//optimize??
void Unit::draw(sf::RenderWindow& window, Actions action) {
	switch (action)
	{
	case Idle:
		drawSpriteAction(idleTextures, action);
		break;
	case RunLeft:
		//mirror image when running
		sprite.move(sf::Vector2f(-speed, 0));
		drawSpriteAction(runTextures, action);
		break;
	case RunRight:
		sprite.setPosition(sf::Vector2f(speed, 0));
		drawSpriteAction(runTextures, action);
		break;
	case RunTop:
		sprite.move(sf::Vector2f(0, -speed));
		drawSpriteAction(runTextures, action);
		break;
	case RunBottom:
		sprite.move(sf::Vector2f(0, speed));
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
	sprite.setTexture(texture[textureToLoad]);
	if (textureToLoad ==  texture.size() - 1|| action != currentAction) {
		textureToLoad = 0;
	}
	else {
		textureToLoad++;
	}
	return;
}

//add x and y to the current position of the sprite
void Unit::movePosition(int x, int y) {
	int posX = sprite.getPosition().x;
	int posY = sprite.getPosition().y;
	sprite.move(sf::Vector2f(x, y));
}