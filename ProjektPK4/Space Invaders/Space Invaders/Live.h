#pragma once
#include<sfml/Graphics.hpp>
class Live
{
private:
	sf::Sprite live;
	std::shared_ptr<sf::Texture>liveTex;
public:
	Live(sf::Vector2f position);
	void render(sf::RenderWindow*window);
	~Live();
};

