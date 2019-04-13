#pragma once
#include<sfml/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"Exceptions.h"
#include"Bullet.h"

class Enemy
{
private:
	sf::Sprite enemy;
	std::string enemyType;
	int currentTexture;

	static std::vector<sf::Texture> enemyTextures;
	static std::vector<sf::SoundBuffer> soundsBuffer;
	static std::vector<sf::Sound> sounds;
	

	static float maxSpeed;
	static int moveTimer;
	static int currentMoveTimer;
	static int textureFlag;
	static int shootTimer;
	static int currentShootTimer;
	
	void enemyInitialization(sf::Vector2f scale, sf::Vector2f position);

public:
	static std::vector<Bullet>bullets;
	Enemy(sf::Vector2f position,sf::Vector2f scale,std::string enemyType);

	static void texturesInitialization();
	static void soundsInitialization();
	static float getMaxSpeed();
	static int getCurrentMoveTimer();
	static int getMoveTimer();
	static void resetCurrentMoveTimer();
	static void incrementCurrentMoveTimer();
	static void changeDirection();
	static void playInvaderKilledSound();
	static void changeTextureFlag();
	static int getTextureFlag();
	static void playInvaderMoveSound(size_t vectorSize);
	static void decrementMoveTimer();
	static void renderBullets(sf::RenderWindow*window);
	static int getCurrentShootTimer();
	static int getShootTimer();
	static void incrementCurrentShootTimer();
	static void incrementShootTimer();
	static void resetCurrentShootTimer();
	static void setMoveTimer(int value);
	static void setShootTimer(int value);
	static void setTextureFlag(int value);
	void render(sf::RenderWindow*window);
	void setPosition(sf::Vector2f position);
	void setTexture(int index);
	int getCurrentTexture();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	std::string getEnemyType();
};






