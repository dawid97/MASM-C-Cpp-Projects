#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Exceptions.h"
#include<fstream>
#include<string>
#include <algorithm>
#include"MainMenu.h"

struct PlayerScore
{
public:
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

class Submitscore:public MainMenu
{
private:
	std::unique_ptr<sf::Text>name;
	int score;
	std::vector<PlayerScore> playersScores;

	void savePlayers();
	bool isPlayer(std::string name, std::string score);
	bool betterResult(std::string name, std::string score);
	void addPlayer(std::string name, std::string score);
	void loadPlayers();
	bool isGoodString(std::string name);
	void moveUp();
	void moveDown();

public:
	Submitscore(sf::RenderWindow*window,int score);
	void updateUserName(sf::RenderWindow*window, sf::Event*event);
	int update(sf::RenderWindow* window);
	void render(sf::RenderWindow*window);
	~Submitscore();
};

