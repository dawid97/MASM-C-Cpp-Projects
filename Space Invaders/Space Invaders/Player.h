#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Exceptions.h"
#include"Bullet.h"


class Player
{
private:
	sf::Sprite player;
	std::unique_ptr<sf::Texture>playerTex;

	std::vector<Bullet> bullets;

	std::unique_ptr<sf::SoundBuffer>soundBufferShoot;
	std::unique_ptr<sf::Sound>shootSound;
	std::unique_ptr<sf::SoundBuffer>soundBufferExplosion;
	std::unique_ptr<sf::Sound>explosionSound;

	float maxSpeed;
	float shootTimer;
	float currentShootTimer;
	int score;
	int hp;
	
	void renderBullets(sf::RenderWindow*window);
	void collisionScreen(sf::RenderWindow*window);
	void move(sf::RenderWindow*window);
	void shoot();
	
public:
	Player(sf::Vector2f position,sf::Vector2f scale, float speed, float shootTimer, std::string shootSound,std::string explosionSound,std::string shipTex);

	void render(sf::RenderWindow*window);
	void update(sf::RenderWindow*window);

	void addScore(int score);
	void removeBullet(size_t index);
	void playExplosionSound();
	void clearBullets();
	void setPosition(sf::Vector2f position);
	Bullet getBullet(size_t index);
	size_t getBulletsSize();
	sf::Vector2f getPosition();
	int getScore();
	sf::FloatRect getGlobalBounds();
	void removeHp();
	int getHp();
};
	
	

