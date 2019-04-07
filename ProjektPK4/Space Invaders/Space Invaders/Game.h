#pragma once
#include"Player.h"
#include"Shield.h"
#include"UI.h"
#include"Enemy.h"
#include"GameOver.h"

class Game
{
private:
	std::unique_ptr<Player>player;
	std::vector<Shield> shields;
	std::unique_ptr<UI> ui;
	std::unique_ptr<Enemy> enemy;
	std::unique_ptr<GameOver>gameOver;
	bool gameOv;
	void renderShields(sf::RenderWindow*window);
	void updateShields();
public:
	void mainGame(sf::RenderWindow*window);
	Game(sf::RenderWindow*window);
	void UpdateEnemies(sf::RenderWindow*window);
	~Game();
};

