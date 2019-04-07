#pragma once
#include<sfml/Graphics.hpp>
class Life
{
private:
	sf::Sprite life;
	std::shared_ptr<sf::Texture>lifeTex;
public:
	Life(sf::Vector2f position);
	void render(sf::RenderWindow*window);
	~Life();
};

