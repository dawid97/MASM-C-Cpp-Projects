#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Exceptions.h"
#include"GameOver.h"

class MainMenu:public GameOver
{
protected:
	std::unique_ptr<sf::Sprite> background;
	std::unique_ptr<sf::Texture> backgroundTex;
	std::unique_ptr<sf::Font>font;
	
	void fontInitialization(std::string fileNameFont);
	void backgroundInitialization(sf::RenderWindow*window);

public:
	MainMenu(sf::RenderWindow*window);
	void render(sf::RenderWindow*window);
};



