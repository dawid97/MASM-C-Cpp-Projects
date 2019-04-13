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
	:player(new Player(sf::Vector2f(window->getSize().x / 2.f, 620.f),sf::Vector2f(0.04f,0.04f),5.f,35.f,"Sounds/shoot.wav","Sounds/explosion.wav","Textures/ship.png")),
	 ui(new UI()),
	 ufo(new UFO(sf::Vector2f(100.f,70.f),sf::Vector2f(0.3f,0.3f),10.f,"Sounds/ufoHighPitch.wav","Sounds/ufoLowPitch.wav","Textures/ufo.png","Textures/ufo1.png"))
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

void Game::collisionBulletsOfPlayerShields()
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

void Game::collisionBulletsOfEnemiesPlayer()
{
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

				Enemy::decrementMoveTimer();
				ui->updateScore(player->getScore());
				Enemy::incrementShootTimer();
				enemies[k].playInvaderKilledSound();

				enemies.erase(enemies.begin() + k);
				break;
			}
		}
	}
}

void Game::bulletsOfEnemiesCollisionScreen(sf::RenderWindow*window)
{
	std::vector<Bullet>::iterator it;
	for (it = Enemy::bullets.begin(); it < Enemy::bullets.end(); it++)
	{
		it->move(sf::Vector2f(0.f, it->getSpeed()));

		if (it->getPosition().y > window->getSize().y)
		{
			Enemy::bullets.erase(Enemy::bullets.begin() + std::distance(Enemy::bullets.begin(), it));
			break;
		}
	}
}

void Game::shootEnemies()
{
	//update shooting
	if (Enemy::getCurrentMoveTimer() < Enemy::getShootTimer())
		Enemy::incrementCurrentShootTimer();

	srand(unsigned int(time(NULL)));

	//shoot
	if (Enemy::getCurrentShootTimer() >= Enemy::getShootTimer())
	{

		std::string tab[2]{ "Textures/bulletEnemy1.png","Textures/bulletEnemy2.png" };

		if (enemies.size() != 0)
		{
			int tmp = std::rand() % enemies.size();

			Enemy::bullets.push_back(Bullet(3.5f, sf::Vector2f(enemies[tmp].getPosition().x, enemies[tmp].getPosition().y + 20), sf::Vector2f(0.2f, 0.3f), tab[(std::rand() % 2)]));

			for (size_t i = 0; i < enemies.size(); i++)
			{
				for (size_t k = 0; k < Enemy::bullets.size(); k++)
				{
					if (enemies[i].getGlobalBounds().intersects(Enemy::bullets[k].getGlobalBounds()))
					{
						if (i != tmp)
						{
							Enemy::bullets.erase(Enemy::bullets.begin() + k);
							break;
						}
					}
				}
			}
		}
		//reset timer
		Enemy::resetCurrentShootTimer();
	}
}

void Game::enemiesCollisionScreen(sf::RenderWindow*window)
{
	for (size_t k = 0; k < enemies.size(); k++)
	{
		if (this->enemies[k].getPosition().x + this->enemies[k].getGlobalBounds().width/2.f > window->getSize().x)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
		}

		if (this->enemies[k].getPosition().x-enemies[k].getGlobalBounds().width/2.f < 0)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
		}
	}
}

void Game::collisionBulletsOfEnemiesPlayer(sf::RenderWindow*window)
{
	for (size_t i = 0; i < Enemy::bullets.size() ; i++)
	{
			if (Enemy::bullets[i].getGlobalBounds().intersects(player->getGlobalBounds()))
			{
				if (player->getHp() > 0)
				{
					player->removeHp();
					ui->removeLive();
					player->playExplosionSound();
					Enemy::bullets.erase(Enemy::bullets.begin() + i);
					player->setPosition(sf::Vector2f(window->getSize().x / 2.f, 620.f));
				}
				if(player->getHp()==0)
				{
					std::cout << "game over" << std::endl;
				}
				break;
			}
	}
}

void Game::moveEnemies()
{
	if (Enemy::getCurrentMoveTimer() >= Enemy::getMoveTimer())
	{
		this->moveEnemies(Enemy::getMaxSpeed());

		if (this->enemies.size() != 0)
			Enemy::playInvaderMoveSound(this->enemies.size());

		Enemy::resetCurrentMoveTimer();
		this->enemiesChangeTextures();
	}
	else
		Enemy::incrementCurrentMoveTimer();
}

void Game::UpdateGame(sf::RenderWindow*window)
{
	//player
	this->collisionBulletsOfEnemiesPlayer();
	this->collisionBulletsOfEnemiesPlayer(window);
	this->player->update(window);

	//enemies
	this->shootEnemies();
	this->bulletsOfEnemiesCollisionScreen(window);
	this->enemiesCollisionScreen(window);
	this->moveEnemies();
	this->emptyEnemies();
	
	//shield
	this->collisionBulletsOfEnemiesShields();
	this->collisionBulletsOfPlayerShields();
}

void Game::stepDownEnemies(float step)
{
	std::vector<Enemy>::iterator it;
	for (it = this->enemies.begin(); it < this->enemies.end(); it++)
	{
		it->setPosition(sf::Vector2f(it->getPosition().x , it->getPosition().y + step));
	}
}

void Game::renderGame(sf::RenderWindow*window)
{
	//player
	this->player->render(window);

	//shields
	this->renderShields(window);

	//UI
	this->ui->render(window);

	//enemies
	this->renderEnemies(window);
	Enemy::renderBullets(window);
}

void Game::mainGame(sf::RenderWindow*window)
{
	//update
	this->UpdateGame(window);
	this->ufo->update();

	//render
	this->renderGame(window);
	this->ufo->render(window);


	//gameOver
	for (size_t k = 0; k < this->enemies.size(); k++)
	{
		for (size_t i = 0; i < shields.size(); i++)
		{
			if (shields[i].getGlobalBounds().intersects(this->enemies[k].getGlobalBounds()))
			{
				std::cout << "game over" << std::endl;
			}
		}
	}
}

void Game::collisionBulletsOfEnemiesShields()
{
	for (size_t i = 0; i < Enemy::bullets.size(); i++)
	{
		for (size_t k = 0; k < shields.size(); k++)
		{
			if (Enemy::bullets[i].getGlobalBounds().intersects(shields[k].getGlobalBounds()))
			{
				if (shields[k].getHp() == 1)
				{
					shields.erase(shields.begin() + k);
					Enemy::bullets.erase(Enemy::bullets.begin() + i);
					ui->removeShieldsText(k);
				}
				else
				{
					Enemy::bullets.erase(Enemy::bullets.begin() + i);
					shields[k].removeHp();
					ui->updateShieldLife(k, shields[k].getHp(), shields[k].getPosition());
				}
				break;
			}
		}
	}
}

void Game::emptyEnemies()
{
	if (enemies.size() == 0)
	{
		Enemy::setTextureFlag(0);
		player->clearBullets();
		this->addEnemies();
		this->shields.clear();
		this->addShields();
		ui->removeShieldsTexts();
		ui->addShieldsTexts();
		Enemy::setMoveTimer(53);
		Enemy::setShootTimer(5);
	}
}
