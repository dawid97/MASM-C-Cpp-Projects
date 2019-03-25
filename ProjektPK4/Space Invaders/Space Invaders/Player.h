#pragma once
#include<SFML/Graphics.hpp>
#include "Exceptions.h"
#include"Bullet.h"

class Player
{
private:
	sf::Sprite player;
	sf::Texture playerTex;
	std::vector<Bullet> bullets;
	float maxSpeed;
	float shootTimer;
	sf::Vector2f playerPosition;
	
public:
	Player(float x,float y);
	void Render(sf::RenderWindow*window);
	void Update(sf::RenderWindow*window);
	~Player();
};

