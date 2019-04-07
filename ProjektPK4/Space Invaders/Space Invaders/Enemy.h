#pragma once
#include<sfml/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"Exceptions.h"

class Enemy
{
private:
	std::vector<sf::Sprite> enemies1;
	std::vector<sf::Sprite> enemies2;
	std::vector<sf::Sprite> enemies3;

	std::vector<sf::Texture> enemiesTex1;
	std::vector<sf::Texture> enemiesTex2;
	std::vector<sf::Texture> enemiesTex3;

	std::shared_ptr<sf::SoundBuffer>soundBuffer;
	std::vector<sf::SoundBuffer> soundBufferVelocity;
	std::unique_ptr<sf::Sound>invaderKilledSound;
	std::vector<sf::Sound> soundVelocity;

	int moveTimer;
	int currentMoveTimer;
	int speedCounter;
	int currentTextureIndex;
	int maxSpeed;


	void texturesInitialization();
	sf::Sprite enemyInitialization(sf::Texture & enemyTextures, sf::Vector2f position);
	void SoundInitialization();
	void enemyInitialization();
public:
	void renderEnemies(sf::RenderWindow*window);
	size_t getSizeEnemies1();
	size_t getSizeEnemies2();
	size_t getSizeEnemies3();
	void removeEnemyEnemies1(size_t index);
	void removeEnemyEnemies2(size_t index);
	void removeEnemyEnemies3(size_t index);
	sf::Sprite getEnemyEnemies1(size_t index);
	sf::Sprite getEnemyEnemies2(size_t index);
	sf::Sprite getEnemyEnemies3(size_t index);
	void move(float step);
	void IncrementSpeedCounter();
	void ResetSpeedCounter();
	int getCurrentMoveTimer();
	void decrementMoveTimer(int value);
	int getMaxSpeed();
	void moveDown(float step);
	void playInvaderKilledSound();
	int getSpeedCounter();
	void changeTextures();
	void changeDirection();
	Enemy();
	~Enemy();
};

