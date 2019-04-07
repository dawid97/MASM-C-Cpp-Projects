#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Exceptions.h"
#include"Bullet.h"
#include"Life.h"

class Player
{
private:
	std::unique_ptr<sf::Sprite>player;
	std::unique_ptr<sf::Texture>playerTex;
	std::vector<Bullet> bullets;
	std::vector<Life> lifes;
	std::unique_ptr<sf::SoundBuffer>soundBuffer;
	std::unique_ptr<sf::Sound>shootSound;
	float maxSpeed;
	float shootTimer;
	
	void renderBullets(sf::RenderWindow*window);
	void renderLifes(sf::RenderWindow*window);
	void collisionScreen(sf::RenderWindow*window);
	void move(sf::RenderWindow*window);
	void shoot();
	
public:
	Player(sf::Vector2f position);
	sf::Vector2f getPosition();
	size_t getBulletsSize();
	void render(sf::RenderWindow*window);
	void update(sf::RenderWindow*window);
	Bullet getBullet(size_t index);
	void removeBullet(size_t index);
	~Player();
};

