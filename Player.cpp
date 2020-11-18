#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animate(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(100.f, 200.f));
	body.setPosition({ 300.f,300.f });
	body.setOrigin(body.getSize() / 2.f);
	body.setTexture(texture);
}
void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (movement.x == 0.f)
		row = 0;
	else
	{
		row = 1;
		if (movement.x > 0.f)
			faceRight = true;
		else
			faceRight = false;
	}
	animate.update(row, deltaTime, faceRight);
	body.setTextureRect(animate.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
