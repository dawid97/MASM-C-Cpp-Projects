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
	std::vector<Enemy> enemies;


	std::unique_ptr<UI> ui;//
	

	
	void addEnemies();
	void addShields();


	void renderShields(sf::RenderWindow*window);
	void renderEnemies(sf::RenderWindow*window);
	void enemiesChangeTextures();
	void moveEnemies(float step);
	void stepDownEnemies(float step);

	void updateShields();
public:
	void mainGame(sf::RenderWindow*window);
	Game(sf::RenderWindow*window);
	void UpdateEnemies(sf::RenderWindow*window);
};

