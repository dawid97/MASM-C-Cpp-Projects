#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Exceptions.h"
#include<fstream>
#include<string>
#include <algorithm> 


struct PlayerScore
{
	sf::Text name;
	sf::Text score;
	bool operator <(const PlayerScore& ps) const
	{
		std::string str1 = score.getString();
		int a = stoi(str1);

		std::string str2 = ps.score.getString();
		int b = stoi(str2);

		return a > b;
	}
};

class Highscores
{
private:
	std::unique_ptr<sf::Font>font;
	std::unique_ptr<sf::Text>title;
	std::unique_ptr<sf::Sprite>background;
	std::unique_ptr<sf::Texture>backgroundTex;
	std::unique_ptr<sf::Text>mainMenu;
	std::vector<PlayerScore> playersScores;
	std::vector<sf::RectangleShape> blocksMenu;
	std::vector<sf::RectangleShape> playersBlocks;
	std::vector<sf::Text> numbers;


	bool enterKey;
	int selectedItemIndex;
	int maxNumberOfItems;
	bool upKey, downKey;
	void loadPlayers(sf::RenderWindow*window);
	void savePlayers();
	void addPlayer(std::string name, std::string score);
	bool isPlayer(std::string name, std::string score);
	bool betterResult(std::string name, std::string score);


public:
	Highscores(sf::RenderWindow* window);
	//void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
};


