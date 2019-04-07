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
	void render(sf::RenderWindow*window);
	sf::FloatRect getGlobalBounds();
	Shield(sf::Vector2f position);
	sf::Vector2f getPosition();
	void removeLife();
	int getHp();
	~Shield();
};

