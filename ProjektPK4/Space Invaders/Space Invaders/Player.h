#pragma once
#include<SFML/Graphics.hpp>
#include "Exceptions.h"
#include"Bullet.h"
#include"Live.h"
#include"Shield.h"

class Player
{
private:
	std::unique_ptr<sf::Sprite>player;
	std::unique_ptr<sf::Texture>playerTex;
	std::vector<Bullet> bullets;
	std::vector<Live> lives;
	std::vector<Shield> shields;
	float maxSpeed;
	float shootTimer;
	
	void renderBullets(sf::RenderWindow*window);
	void renderLives(sf::RenderWindow*window);
	void renderShields(sf::RenderWindow*window);
	void collisionScreen(sf::RenderWindow*window);
	void move(sf::RenderWindow*window);
	void shoot();
	
public:
	Player(sf::Vector2f position);
	sf::Vector2f getPosition();
	void render(sf::RenderWindow*window);
	void update(sf::RenderWindow*window);
	~Player();
};

