#pragma once
#include <SFML/Graphics.hpp>
#include "animation.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	//~Player(); // not necessary

	void update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }

private:
	sf::RectangleShape body; 
	animation animate;
	unsigned int row;
	float speed;
	bool faceRight;
};

