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
	int maxSpeed;
	int moveTimer;
	int currentMoveTimer;

	void texturesInitialization(std::string ufoTexWhite, std::string ufoTexRed);
	void soundsInitialization(std::string ufoLowPitch, std::string ufoHighPitch);
	void move();
	void changeTexture();

public:
	UFO(sf::Vector2f position, sf::Vector2f scale, float speed,std::string ufoLowPitch,std::string ufoHighPitch,std::string ufoTexWhite,std::string ufoTexRed);
	void render(sf::RenderWindow*window);
	void update();
	
};

