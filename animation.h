#pragma once
#include <SFML/Graphics.hpp>

class animation
{
public:
	animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~animation();

	sf::IntRect uvRect;

	void update(int row, float deltaTime, bool faceRight);

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime, switchTime;
};
