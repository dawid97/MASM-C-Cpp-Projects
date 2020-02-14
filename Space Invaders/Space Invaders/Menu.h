#pragma once
#include"GameOver.h"
#include"Game.h"
#include"MainMenu.h"
#include"Submitscore.h"
#include"Highscores.h"
#include"Pause.h"

class Menu
{
private:

	enum stateGame { MM, GO, SS, HS, MG, PG };

	int tmpScore;
	int playerScore;
	int choose;
	int currentState;
	bool enterKey;

	Game*game;
	GameOver*gameOver;
	MainMenu*mainMenu;
	Submitscore*submitscore;
	Highscores*highscores;
	Pause*pause;
public:
	Menu(sf::RenderWindow*window);
	int update(sf::RenderWindow*window);
	~Menu();
};

