#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"

class Bullet
{
private:
	sf::Sprite bullet;
	sf::Texture bulletTex;
public:

	Bullet(sf::Vector2f position);
	void move(sf::Vector2f xy);
	sf::Vector2f getPosition();
	void render(sf::RenderWindow*window);
	~Bullet();
};
