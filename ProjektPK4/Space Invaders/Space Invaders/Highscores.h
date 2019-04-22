#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Exceptions.h"
#include<fstream>
#include<string>
#include <algorithm> 
#include"Submitscore.h"




class Highscores
{
private:
	std::unique_ptr<sf::Font>font;
	std::unique_ptr<sf::Text>title;
	std::unique_ptr<sf::Sprite>background;
	std::unique_ptr<sf::Texture>backgroundTex;
	std::vector<PlayerScore> playersScores;
	std::vector<sf::Text> numbers;
	std::vector<sf::RectangleShape> playersBlocks;
	std::vector<Block> blocks;
	std::vector<Button> buttons;


	void backgroundInitialization(sf::RenderWindow*window);
	void fontInitialization();
	void titleInitialization(sf::RenderWindow*window);
	void loadPlayers(sf::RenderWindow*window);
	void buttonInitialization(sf::RenderWindow*window);
public:
	Highscores(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	int update();
};


