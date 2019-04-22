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
	:player(new Player(sf::Vector2f(window->getSize().x / 2.f, 620.f),sf::Vector2f(0.04f,0.04f),3.f,60.f,"Sounds/shoot.wav","Sounds/explosion.wav","Textures/ship.png")),
	 ui(new UI())
{
	this->setStaticValues();
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
					player->removeBullet(i);
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

void Game::collisionBulletsOfPlayerEnemies()
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

			Enemy::bullets.push_back(Bullet(5.f, sf::Vector2f(enemies[tmp].getPosition().x, enemies[tmp].getPosition().y + 20), sf::Vector2f(0.2f, 0.3f), tab[(std::rand() % 2)]));

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
		Enemy::setCurrentShootTimer(0);
	}
}

int Game::enemiesCollisionScreen(sf::RenderWindow*window)
{
	for (size_t k = 0; k < enemies.size(); k++)
	{
		if (this->enemies[k].getPosition().x + this->enemies[k].getGlobalBounds().width/2.f > window->getSize().x)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
			return -1;
		}

		if (this->enemies[k].getPosition().x-enemies[k].getGlobalBounds().width/2.f < 0)
		{
			Enemy::changeDirection();
			this->moveEnemies(Enemy::getMaxSpeed());
			this->stepDownEnemies(10);
			return -1;
		}

		if (this->enemies[k].getPosition().y + this->enemies[k].getGlobalBounds().height / 2.f > window->getSize().y)
			return 1;
	}
	return -1;
}

int Game::collisionBulletsOfEnemiesPlayer(sf::RenderWindow*window)
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
					this->aliens.clear();
					this->setStaticValues();
					return player->getScore();
				}
				break;
			}
	}
	return -1;
}

void Game::setStaticValues()
{
	Enemy::setMoveTimer(53);
	Enemy::setCurrentMoveTimer(Enemy::getMoveTimer());
	Enemy::setTextureFlag(0);
	Enemy::setShootTimer(1);
	Enemy::setCurrentShootTimer(Enemy::getShootTimer());
	UFO::resetCurrentMoveTimer();
	UFO::setCurrentTextureTimer(UFO::getCurrentTextureTimer());
	Enemy::clearSounds();
	Enemy::clearSoundsBuffer();
}

void Game::moveEnemies()
{
	if (Enemy::getCurrentMoveTimer() >= Enemy::getMoveTimer())
	{
		this->moveEnemies(Enemy::getMaxSpeed());

		if (this->enemies.size() != 0)
			Enemy::playInvaderMoveSound(this->enemies.size());

		Enemy::setCurrentMoveTimer(0);
		this->enemiesChangeTextures();
	}
	else
		Enemy::incrementCurrentMoveTimer();
}

int Game::update(sf::RenderWindow*window)
{
	//player
	this->collisionBulletsOfPlayerEnemies();

	int isGameOver= this->collisionBulletsOfEnemiesPlayer(window);
	if (isGameOver != -1)
		return isGameOver;
	
	this->player->update(window);

	isGameOver = this->collisionPlayerEnemies();
	if (isGameOver != -1)
		return isGameOver;

	//enemies
	this->shootEnemies();
	this->bulletsOfEnemiesCollisionScreen(window);

	isGameOver=this->enemiesCollisionScreen(window);
	if (isGameOver != -1)
		return isGameOver;

	this->moveEnemies();
	this->emptyEnemies();
	
	//shield
	this->collisionBulletsOfEnemiesShields();
	this->collisionBulletsOfPlayerShields();

	isGameOver = this->collisionShieldsEnemies();
	if (isGameOver != -1)
		return isGameOver;

	//aliens
	this->updateAliens(window);
	this->collisionBulletOfPlayerAliens(window);

	return -1;
}

void Game::stepDownEnemies(float step)
{
	std::vector<Enemy>::iterator it;
	for (it = this->enemies.begin(); it < this->enemies.end(); it++)
	{
		it->setPosition(sf::Vector2f(it->getPosition().x , it->getPosition().y + step));
	}
}

void Game::render(sf::RenderWindow*window)
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

	//aliens
	this->renderAliens(window);

	if (UI::getRenderUfoScore() == 1)
	ui->renderUfoScoreText(window);

	UI::setRenderUfoScore(0);
}



int Game::collisionShieldsEnemies()
{
	for (size_t k = 0; k < this->enemies.size(); k++)
	{
		for (size_t i = 0; i < shields.size(); i++)
		{
			if (shields[i].getGlobalBounds().intersects(this->enemies[k].getGlobalBounds()))
			{
				this->aliens.clear();
				this->setStaticValues();
				return player->getScore();
			}
		}
	}
	return -1;
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
		UFO::resetCurrentMoveTimer();
		this->aliens.clear();
		UFO::resetCurrentMoveTimer();
	}
}

void Game::renderAliens(sf::RenderWindow*window)
{
	std::vector<UFO>::iterator it;
	for (it = this->aliens.begin(); it < this->aliens.end(); it++)
	{
		it->render(window);
	}
}

void Game::updateAliens(sf::RenderWindow*window)
{
	//update move
	if (this->aliens.size() == 0)
	{
		if (UFO::getCurrentMoveTimer() < UFO::getMoveTimer())
			UFO::incrementCurrentMoveTimer();
	}
		
	if (UFO::getCurrentMoveTimer() >= UFO::getMoveTimer())
	{
		this->aliens.push_back(UFO(2.f,sf::Vector2f(-30.f, 70.f), sf::Vector2f(0.3f, 0.3f), 10.f,"Sounds/ufoLowPitch.wav", "Sounds/ufoHighPitch.wav" , "Textures/ufo.png", "Textures/ufo1.png"));

		std::vector<UFO>::iterator it;
		UFO::resetCurrentMoveTimer();
	}

	//move
	std::vector<UFO>::iterator it;
	for (it = this->aliens.begin(); it < this->aliens.end(); it++)
	{
		if (UFO::getCurrentTextureTimer() < UFO::getTextureTimer())
			UFO::incrementCurrentTextureTimer();		

		if (UFO::getCurrentTextureTimer() >= UFO::getTextureTimer())
		{
			it->playLowPitch();
			it->changeTexture();
			UFO::resetCurrentTextureTimer();
		}

		it->move();
		
		//ufo out of window
		if (it->getPosition().x > window->getSize().x+10)
		{
			aliens.erase(aliens.begin() + std::distance(aliens.begin(), it));
			break;
		}
	}
}

void Game::collisionBulletOfPlayerAliens(sf::RenderWindow*window)
{
	for (size_t k = 0; k < this->aliens.size(); k++)
	{
		for (size_t i = 0; i < player->getBulletsSize(); i++)
		{
			if (player->getBullet(i).isIntersects(this->aliens[k].getGlobalBounds()))
			{
				ui->updateUfoScore(this->aliens[k].getScore(),this->aliens[k].getPosition());
				ui->renderUfoScoreText(window);
				UI::setRenderUfoScore(1);
				player->addScore(this->aliens[k].getScore());
				ui->updateScore(player->getScore());
				this->aliens.erase(this->aliens.begin() + k);
				break;
			}
		}
	}
}

int Game::collisionPlayerEnemies()
{
	for (size_t k = 0; k < this->enemies.size(); k++)
	{
			if (enemies[k].getGlobalBounds().intersects(this->player->getGlobalBounds()))
				return player->getScore();
	}
	return -1;
}
