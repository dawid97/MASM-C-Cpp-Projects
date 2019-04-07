#include "Game.h"



Game::Game(sf::RenderWindow*window)
	:player(new Player(sf::Vector2f(window->getSize().x / 2.f, 620.f))),
	 ui(new UI()),
	 enemy(new Enemy()),
	 gameOver(new GameOver(window))
{
	gameOv = false;
	//shields
	this->shields.push_back(Shield(sf::Vector2f(700.f, 500.f)));
	this->shields.push_back(Shield(sf::Vector2f(500.f, 500.f)));
	this->shields.push_back(Shield(sf::Vector2f(300.f, 500.f)));
	this->shields.push_back(Shield(sf::Vector2f(100.f, 500.f)));

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
					shields[k].removeLife();
					ui->updateShieldLife(k, shields[k].getHp(), shields[k].getPosition());
				}
				break;
			}
		}
	}
}

void Game::UpdateEnemies(sf::RenderWindow*window)
{
	//enemies1
	for (size_t k = 0; k < enemy->getSizeEnemies1(); k++)
	{
		for (size_t i = 0; i < player->getBulletsSize(); i++)
		{
			if (player->getBullet(i).isIntersects(enemy->getEnemyEnemies1(k).getGlobalBounds()))
			{
				player->removeBullet(i);
				enemy->removeEnemyEnemies1(k);
				ui->addScore(1);
				ui->updateScore();
				enemy->playInvaderKilledSound();
				break;
			}
		}
	}

	//collision window enemies1
	for (size_t k = 0; k < enemy->getSizeEnemies1(); k++)
	{
		if (enemy->getEnemyEnemies1(k).getPosition().x + enemy->getEnemyEnemies1(k).getGlobalBounds().width > window->getSize().x)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);

			//enemies1 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if (enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}

		if (enemy->getEnemyEnemies1(k).getPosition().x < 0)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);
			
			//enemies1 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if (enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}
	}


	//enemies2
	for (size_t k = 0; k < enemy->getSizeEnemies2(); k++)
	{
		for (size_t i = 0; i < player->getBulletsSize(); i++)
		{
			if (player->getBullet(i).isIntersects(enemy->getEnemyEnemies2(k).getGlobalBounds()))
			{
				player->removeBullet(i);
				enemy->removeEnemyEnemies2(k);
				ui->addScore(2);
				ui->updateScore();
				ui->updateScore();
				enemy->playInvaderKilledSound();
				break;
			}
		}
	}

	//collision window enemies2
	for (size_t k = 0; k < enemy->getSizeEnemies2(); k++)
	{
		if (enemy->getEnemyEnemies2(k).getPosition().x + enemy->getEnemyEnemies2(k).getGlobalBounds().width > window->getSize().x)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);
			
			//enemies2 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if(enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}

		if (enemy->getEnemyEnemies2(k).getPosition().x < 0)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);
			
			//enemies2 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if (enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}
	}

	//enemies3
	for (size_t k = 0; k < enemy->getSizeEnemies3(); k++)
	{
		for (size_t i = 0; i < player->getBulletsSize(); i++)
		{
			if (player->getBullet(i).isIntersects(enemy->getEnemyEnemies3(k).getGlobalBounds()))
			{
				player->removeBullet(i);
				enemy->removeEnemyEnemies3(k);
				ui->addScore(3);
				ui->updateScore();
				ui->updateScore();
				enemy->playInvaderKilledSound();
				break;
			}
		}
	}

	//collision window enemies3
	for (size_t k = 0; k < enemy->getSizeEnemies3(); k++)
	{
		if (enemy->getEnemyEnemies3(k).getPosition().x + enemy->getEnemyEnemies3(k).getGlobalBounds().width > window->getSize().x)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);
			
			//enemies3 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if (enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}

		if (enemy->getEnemyEnemies3(k).getPosition().x < 0)
		{
			enemy->changeDirection();
			enemy->move(float(enemy->getMaxSpeed()));
			enemy->moveDown(10);
			
			//enemies3 speed
			if (enemy->getCurrentMoveTimer() <= 10)
				enemy->decrementMoveTimer(2);
			else if (enemy->getCurrentMoveTimer() <= 4)
				enemy->decrementMoveTimer(1);
			else
				enemy->decrementMoveTimer(8);
		}
	}

	//move enemies
	
	if (enemy->getSpeedCounter() >= enemy->getCurrentMoveTimer())
	{
		enemy->move(float(enemy->getMaxSpeed()));
		enemy->ResetSpeedCounter();
		enemy->changeTextures();
	}
	else
		enemy->IncrementSpeedCounter();
}

Game::~Game()
{

}

void Game::mainGame(sf::RenderWindow*window)
{
	
	//update
	if (!gameOv)
	{
		this->player->update(window);
		this->updateShields();
		this->UpdateEnemies(window);
	}
	else
		gameOver->Update(window);

	if (enemy->getSizeEnemies1() == 0 && enemy->getSizeEnemies2() == 0 && enemy->getSizeEnemies3() == 0)
	{
		//enemy = std::unique_ptr<Enemy>(new Enemy);
		
		/*this->shields.clear();
		this->ui->removeShieldsText();
		this->shields.push_back(Shield(sf::Vector2f(700.f, 500.f)));
		this->shields.push_back(Shield(sf::Vector2f(500.f, 500.f)));
		this->shields.push_back(Shield(sf::Vector2f(300.f, 500.f)));
		this->shields.push_back(Shield(sf::Vector2f(100.f, 500.f)));
		this->ui->addShieldsText();*/

		gameOv = true;
	}

	if (!gameOv)
	{
		//render
		this->player->render(window);
		this->renderShields(window);
		this->ui->render(window);
		this->enemy->renderEnemies(window);
	}
	else
	{
		this->player->render(window);
		this->renderShields(window);
		this->ui->render(window);
		this->enemy->renderEnemies(window);

		gameOver->Render(window);
	}
	
}
