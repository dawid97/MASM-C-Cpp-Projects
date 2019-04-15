#pragma once
#include"Player.h"
#include"Shield.h"
#include"UI.h"
#include"Enemy.h"
#include"GameOver.h"
#include"UFO.h"
#include<cstdlib>



class Game
{
private:
	std::unique_ptr<Player>player;
	std::vector<UFO>aliens;
	std::vector<Shield> shields;
	std::vector<Enemy> enemies;
	

	std::unique_ptr<UI> ui;
	

	
	void addEnemies();
	void addShields();


	void renderShields(sf::RenderWindow*window);
	void renderEnemies(sf::RenderWindow*window);
	void enemiesChangeTextures();
	void moveEnemies(float step);
	void stepDownEnemies(float step);
	void collisionBulletsOfPlayerEnemies();
	void emptyEnemies();
	void bulletsOfEnemiesCollisionScreen(sf::RenderWindow*window);
	void shootEnemies();
	void enemiesCollisionScreen(sf::RenderWindow*window);
	void moveEnemies();
	void collisionBulletsOfEnemiesPlayer(sf::RenderWindow*window);
	void collisionBulletsOfEnemiesShields();
	void UpdateGame(sf::RenderWindow*window);
	void renderGame(sf::RenderWindow*window);
	void renderAliens(sf::RenderWindow*window);
	void updateAliens(sf::RenderWindow*window);
	void collisionBulletOfPlayerAliens();

	void collisionBulletsOfPlayerShields();
public:
	void mainGame(sf::RenderWindow*window);
	Game(sf::RenderWindow*window);
	
};

