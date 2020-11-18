#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "Player.h"

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
	view.setSize(800.f * aspectRatio, 800.f);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "It's LUX", sf::Style::Close | sf::Style::Resize);
	//sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(800.f, 800.f));

	sf::Texture texture;
	texture.loadFromFile("tux.png");

	Player player(&texture, sf::Vector2u(3, 9), 0.3f, 100.f);
	float deltaTime = 0.f;
	sf::Clock clock;

	sf::Event event;  
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				window.close();
				break;
			case(sf::Event::Resized):
				//ResizeView(window, view);
				break;
			}
			
		}
		player.update(deltaTime); 
		//view.setCenter(player.GetPosition());
		window.clear(sf::Color(150,150,150));
		//window.setView(view);
		player.Draw(window);
		window.display();
	}
} 
