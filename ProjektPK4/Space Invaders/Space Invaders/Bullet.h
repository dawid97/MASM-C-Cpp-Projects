#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"

class Bullet
{
private:
	sf::Sprite bullet;
	std::shared_ptr<sf::Texture>bulletTex;
	float speed;

public:
	Bullet(float speed,sf::Vector2f position,sf::Color color, sf::Vector2f scale, std::string fileNameTex);
	

	void render(sf::RenderWindow*window);
	void move(sf::Vector2f position);
	bool isIntersects(sf::FloatRect object);
	sf::Vector2f getPosition();
	float getSpeed();
};

