#include "Game.h"

void Game::addEnemies()
{
	for (size_t j = 0; j < 10; j++)//width
	{
		this->enemies.push_back(Enemy(sf::Vector2f((j + 1)*float(51.6 + 15.f), ((0 + 2)*float(40.5 + 5.f) + 40)), sf::Vector2f(0.08f, 0.08f), "squid"));

	}

	for (size_t i = 0; i < 2; i++)//hight
	{
		for (size_t j = 0; j < 10; j++)//width
		{

			this->enemies.push_back(Enemy(sf::Vector2f((j + 1)*float(51.6 + 15.f), ((i + 1 + 2)*float(40.5 + 5.f) + 40)), sf::Vector2f(0.08f, 0.08f), "crab"));
		}
	}

	for (size_t i = 0; i < 2; i++)//hight
	{
		for (size_t j = 0; j < 10; j++)//width
		{
			this->enemies.push_back(Enemy(sf::Vector2f((j + 1)*float(51.6 + 15.f), ((i + 3 + 2)*float(40.5 + 5.f) + 40)), sf::Vector2f(0.08f, 0.08f), "octopus"));
		}
	}
}

void Game::addShields()
{
	this->shields.push_back(Shield(10, sf::Vector2f(700.f, 500.f), sf::Vector2f(0.35f, 0.35f), "Textures/shield.png"));
	this->shields.push_back(Shield(10, sf::Vector2f(500.f, 500.f), sf::Vector2f(0.35f, 0.35f), "Textures/shield.png"));
	this->shields.push_back(Shield(10, sf::Vector2f(300.f, 500.f), sf::Vector2f(0.35f, 0.35f), "Textures/shield.png"));
	this->shields.push_back(Shield(10, sf::Vector2f(100.f, 500.f), sf::Vector2f(0.35f, 0.35f), "Textures/shield.png"));
}

Game::Game(sf::RenderWindow*window)
	:player(new Player(sf::Vector2f(window->getSize().x / 2.f, 620.f),sf::Vector2f(0.04f,0.04f),5.f,35.f,"Sounds/shoot.wav","Textures/ship.png")),
	 ui(new UI())
{
	this->addShields();
	
	try
	{
		Enemy::texturesInitialization();
		Enemy::soundsInitialization();
	}
	catch (LoadingError error)
	{
		error.DisplayMessage();
		system("pause");
		exit(EXIT_FAILURE);
	}

	this->addEnemies();
}

void Game::renderEnemies(sf::RenderWindow*window)
{
	std::vector<Enemy>::iterator it;
	for (it = enemies.begin(); it < enemies.end(); it++)
	{
		it->render(window);
	}
}

void Game::renderShields(sf::RenderWindow*window)
{
	std::vector<Shield>::iterator it;
	for (it = shields.begin(); it < shields.end(); it++)
	{
		it->render(window);
	}
}

void Game::updateShields()
{
	for (size_t i = 0; i < player->getBulletsSize(); i++)
	{
		for (size_t k = 0; k < shields.size(); k++)
		{
			if (player->getBullet(i).isIntersects(shields[k].getGlobalBounds()))
			{

				if (shields[k].getHp() == 1)
				{
					shields.erase(shields.begin() + k);
					ui->removeShieldsText(k);
				}
				else
				{
					player->removeBullet(i);
					shields[k].removeHp();
					ui->updateShieldLife(k, shields[k].getHp(), shields[k].getPosition());
				}
				break;
			}
		}
	}
}

void Game::moveEnemies(float step)
{
	std::vector<Enemy>::iterator it;
	for (it = this->enemies.begin(); it < this->enemies.end(); it++)
	{
		it->setPosition(sf::Vector2f(it->getPosition().x + step, it->getPosition().y));
	}
}

void Game::enemiesChangeTextures()
{
	std::vector<Enemy>::iterator it;
	for (it = this->enemies.begin(); it < this->enemies.end(); it++)
	{
		if (Enemy::getTextureFlag() == 0)
			it->setTexture(it->getCurrentTexture() + 1);
		else
			it->setTexture(it->getCurrentTexture() - 1);
	}
	Enemy::changeTextureFlag();
}

void Game::UpdateEnemies(sf::RenderWindow*window)
{
	//collision enemies-bullet
	for (size_t k = 0; k < this->enemies.size(); k++)
	{
		for (size_t i = 0; i < player->getBulletsSize(); i++)
		{
			if (player->getBullet(i).isIntersects(this->enemies[k].getGlobalBounds()))
			{
				player->removeBullet(i);

				if (enemies[k].getEnemyType() == "squid")
					player->addScore(30);
				else if (enemies[k].getEnemyType() == "crab")
					player->addScore(20);
				else if (enemies[k].getEnemyType() == "octopus")
					player->addScore(10);

				ui->updateScore(player->getScore());
				enemies[k].playInvaderKilledSound();

				enemies.erase(enemies.begin() + k);
				break;
			}
		}
	}

	//collision window enemies
	for (size_t k = 0; k < enemies.size(); k++)
	{
		if (this->enemies[k].getPosition().x + this->enemies[k].getGlobalBounds().width > window->getSize().x)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
		}

		if (this->enemies[k].getPosition().x < 0)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
		}
	}

	//move enemies
	if (Enemy::getCurrentMoveTimer() >= Enemy::getMoveTimer())
	{
		this->moveEnemies(Enemy::getMaxSpeed());
		Enemy::playInvaderMoveSound();
		Enemy::resetCurrentMoveTimer();
		this->enemiesChangeTextures();
	}
	else
		Enemy::incrementCurrentMoveTimer();
}

void Game::stepDownEnemies(float step)
{
	std::vector<Enemy>::iterator it;
	for (it = this->enemies.begin(); it < this->enemies.end(); it++)
	{
		it->setPosition(sf::Vector2f(it->getPosition().x , it->getPosition().y + step));
	}
}

void Game::mainGame(sf::RenderWindow*window)
{
	
	//update
	this->player->update(window);
	this->updateShields();
	this->UpdateEnemies(window);


	//render
	this->player->render(window);
	this->renderShields(window);
	this->ui->render(window);
	this->renderEnemies(window);
}
