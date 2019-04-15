#pragma once
#include<sfml/Graphics.hpp>
class Live
{
private:
	sf::Sprite live;
	std::shared_ptr<sf::Texture>lifeTex;
public:
	Live(sf::Vector2f position, sf::Vector2f scale, sf::Color color, std::string liveTex);

	void render(sf::RenderWindow*window);
};