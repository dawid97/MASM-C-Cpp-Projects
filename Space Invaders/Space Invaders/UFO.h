#pragma once
#include<SFML/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"Exceptions.h"

class UFO
{
private:
	sf::Sprite ufo;
	std::vector<sf::Texture> textures;
	std::vector<sf::SoundBuffer>soundsBuffer;
	std::vector<sf::Sound>sounds;
	int texIndex;
	float maxSpeed;
	int score;
	static int moveTimer;
	static int currentMoveTimer;
	static int textureTimer;
	static int currentTextureTimer;

	void texturesInitialization(std::string ufoTexWhite, std::string ufoTexRed);
	void soundsInitialization(std::string ufoLowPitch, std::string ufoHighPitch);
	
	
public:
	UFO(float maxSpeed,sf::Vector2f position, sf::Vector2f scale, float speed,std::string ufoLowPitch,std::string ufoHighPitch,std::string ufoTexWhite,std::string ufoTexRed);
	void render(sf::RenderWindow*window);
	void changeTexture();
	static int getMoveTimer();
	static int getCurrentMoveTimer();
	static void incrementCurrentMoveTimer();
	static void resetCurrentMoveTimer();
	static int getTextureTimer();
	static int getCurrentTextureTimer();
	static void resetCurrentTextureTimer();
	static void incrementCurrentTextureTimer();
	static void setCurrentTextureTimer(int value);
	void playLowPitch();
	void playHighPitch();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	int getScore();

	void move();
};

