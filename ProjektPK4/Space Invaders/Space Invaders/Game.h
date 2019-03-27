#pragma once
#include"Player.h"
class Game
{
	std::unique_ptr<Player>player;
public:
	void mainGame(sf::RenderWindow*window);
	Game(sf::RenderWindow*window);
	~Game();
};

