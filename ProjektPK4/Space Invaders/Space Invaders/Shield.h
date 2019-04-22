#pragma once
#include<sfml/Graphics.hpp>
#include"Exceptions.h"

class Shield
{
private:
	sf::Sprite shield;
	std::shared_ptr<sf::Texture> shieldTex;
	int hp;

public:
	Shield(int hp, sf::Vector2f position, sf::Vector2f scale, std::string shieldTex);
	void removeHp();
	int getHp();
	void render(sf::RenderWindow*window);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();	
};
