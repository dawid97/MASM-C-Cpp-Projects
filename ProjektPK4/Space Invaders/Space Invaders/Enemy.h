#pragma once
#include<sfml/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"Exceptions.h"

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
	
	void enemyInitialization(sf::Vector2f scale, sf::Vector2f position);

public:
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
	static void playInvaderMoveSound();
	void render(sf::RenderWindow*window);
	void setPosition(sf::Vector2f position);
	void setTexture(int index);
	int getCurrentTexture();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	std::string getEnemyType();
};






