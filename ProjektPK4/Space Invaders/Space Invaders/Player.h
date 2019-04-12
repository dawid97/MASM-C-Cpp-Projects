#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Exceptions.h"
#include"Bullet.h"


class Player
{
private:
	std::unique_ptr<sf::Sprite>player;
	std::unique_ptr<sf::Texture>playerTex;

	std::vector<Bullet> bullets;

	std::unique_ptr<sf::SoundBuffer>soundBuffer;
	std::unique_ptr<sf::Sound>shootSound;

	float maxSpeed;
	float shootTimer;
	float currentShootTimer;
	int score;
	
	void renderBullets(sf::RenderWindow*window);
	void collisionScreen(sf::RenderWindow*window);
	void move(sf::RenderWindow*window);
	void shoot();
	
public:
	Player(sf::Vector2f position,sf::Vector2f scale, float speed, float shootTimer, std::string shootSound, std::string shipTex);

	void render(sf::RenderWindow*window);
	void update(sf::RenderWindow*window);

	void addScore(int score);
	void removeBullet(size_t index);
	Bullet getBullet(size_t index);
	size_t getBulletsSize();
	sf::Vector2f getPosition();
	int getScore();
};
	
	

