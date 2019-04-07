#include "Enemy.h"




Enemy::Enemy()
{
	this->moveTimer = 50;
	this->currentMoveTimer = this->moveTimer;
	this->speedCounter = this->moveTimer;
	this->currentTextureIndex = 0;
	this->maxSpeed = 10;

	//sound
	this->SoundInitialization();

	//textures
	this->texturesInitialization();

	//enemies
	this->enemyInitialization();
}

void Enemy::enemyInitialization()
{
	for (size_t i = 0; i < 2; i++)//hight
	{
		for (size_t j = 0; j < 10; j++)//width
		{
			if (i < 1)
			{
				this->enemies3.push_back(sf::Sprite(this->enemyInitialization(this->enemiesTex3[0], sf::Vector2f((j + 1)*float(51.6 + 15.f), ((i + 2)*float(40.5 + 5.f)+40)))));
			}
			this->enemies2.push_back(sf::Sprite(this->enemyInitialization(this->enemiesTex2[0], sf::Vector2f((j + 1)*float(51.6 + 15.f), ((i + 1 + 2)*float(40.5 + 5.f)+40)))));
			this->enemies1.push_back(sf::Sprite(this->enemyInitialization(this->enemiesTex1[0], sf::Vector2f((j + 1)*float(51.6 + 15.f), ((i + 3 + 2)*float(40.5 + 5.f)+40)))));

		}
	}
}

void Enemy::SoundInitialization()
{
	//enemy killed sound
	this->soundBuffer = std::shared_ptr<sf::SoundBuffer>(new sf::SoundBuffer);
	if (!soundBuffer->loadFromFile("Sounds/invaderkilled.wav"))
		throw LoadingError("sound shoot loading error");
	this->invaderKilledSound = std::unique_ptr<sf::Sound>(new sf::Sound);
	this->invaderKilledSound->setBuffer(*soundBuffer);


	//enemy fast sound
	sf::SoundBuffer soundBufferVelocity;
	this->soundBufferVelocity.push_back(sf::SoundBuffer(soundBufferVelocity));
	this->soundBufferVelocity.push_back(sf::SoundBuffer(soundBufferVelocity));
	this->soundBufferVelocity.push_back(sf::SoundBuffer(soundBufferVelocity));
	this->soundBufferVelocity.push_back(sf::SoundBuffer(soundBufferVelocity));

	sf::Sound soundVelocity;
	//1
	if (!this->soundBufferVelocity[0].loadFromFile("Sounds/fastinvader1.wav"))
		throw LoadingError("sound fastinvader1 loading error");
	soundVelocity.setBuffer(this->soundBufferVelocity[0]);
	this->soundVelocity.push_back(sf::Sound(soundVelocity));

	//2
	if (!this->soundBufferVelocity[1].loadFromFile("Sounds/fastinvader2.wav"))
		throw LoadingError("sound fastinvader2 loading error");
	soundVelocity.setBuffer(this->soundBufferVelocity[1]);
	this->soundVelocity.push_back(sf::Sound(soundVelocity));

	//3
	if (!this->soundBufferVelocity[2].loadFromFile("Sounds/fastinvader3.wav"))
		throw LoadingError("sound fastinvader3 loading error");
	soundVelocity.setBuffer(this->soundBufferVelocity[2]);
	this->soundVelocity.push_back(sf::Sound(soundVelocity));

	//4
	if (!this->soundBufferVelocity[3].loadFromFile("Sounds/fastinvader4.wav"))
		throw LoadingError("sound fastinvader4 loading error");
	soundVelocity.setBuffer(this->soundBufferVelocity[3]);
	this->soundVelocity.push_back(sf::Sound(soundVelocity));
}

int Enemy::getMaxSpeed()
{
	return this->maxSpeed;
}

void Enemy::texturesInitialization()
{
	//enemy1
	sf::Texture enemyTex;
	if (!enemyTex.loadFromFile("Textures/enemy11.png"))
		throw LoadingError("Enemy11 loading error");

	this->enemiesTex1.push_back(sf::Texture(enemyTex));

	
	if (!enemyTex.loadFromFile("Textures/enemy12.png"))
		throw LoadingError("Enemy12 loading error");

	this->enemiesTex1.push_back(sf::Texture(enemyTex));

	//enemy2
	if (!enemyTex.loadFromFile("Textures/enemy21.jpg"))
		throw LoadingError("Enemy21 loading error");

	this->enemiesTex2.push_back(sf::Texture(enemyTex));

	if (!enemyTex.loadFromFile("Textures/enemy22.png"))
		throw LoadingError("Enemy22 loading error");

	this->enemiesTex2.push_back(sf::Texture(enemyTex));

	//enemy3
	if (!enemyTex.loadFromFile("Textures/enemy31.png"))
		throw LoadingError("Enemy31 loading error");

	this->enemiesTex3.push_back(sf::Texture(enemyTex));

	if (!enemyTex.loadFromFile("Textures/enemy32.png"))
		throw LoadingError("Enemy32 loading error");

	this->enemiesTex3.push_back(sf::Texture(enemyTex));
}

sf::Sprite Enemy::enemyInitialization(sf::Texture & enemyTexture,sf::Vector2f position)
{
	sf::Sprite enemy;
	enemy.setTexture(enemyTexture);
	enemy.setScale(sf::Vector2f(0.08f, 0.08f));
	enemy.setPosition(position);

	return enemy;
}

void Enemy::renderEnemies(sf::RenderWindow*window)
{
	//enemies1
	std::vector<sf::Sprite>::iterator it1;
	for (it1 = this->enemies1.begin(); it1 < this->enemies1.end(); it1++)
	{
		window->draw(*it1);
	}

	//enemies2
	std::vector<sf::Sprite>::iterator it2;
	for (it2 = this->enemies2.begin(); it2 < this->enemies2.end(); it2++)
	{
		window->draw(*it2);
	}

	//enemies3
	std::vector<sf::Sprite>::iterator it3;
	for (it3 = this->enemies3.begin(); it3 < this->enemies3.end(); it3++)
	{
		window->draw(*it3);
	}
}

void Enemy::moveDown(float step)
{
	//enemies1
	std::vector<sf::Sprite>::iterator it1;
	for (it1 = this->enemies1.begin(); it1 < this->enemies1.end(); it1++)
	{
		it1->setPosition(it1->getPosition().x , it1->getPosition().y + step);
	}

	//enemies2
	std::vector<sf::Sprite>::iterator it2;
	for (it2 = this->enemies2.begin(); it2 < this->enemies2.end(); it2++)
	{
		it2->setPosition(it2->getPosition().x, it2->getPosition().y+ step);
	}

	//enemies3
	std::vector<sf::Sprite>::iterator it3;
	for (it3 = this->enemies3.begin(); it3 < this->enemies3.end(); it3++)
	{
		it3->setPosition(it3->getPosition().x, it3->getPosition().y + step);
	}
}


Enemy::~Enemy()
{

}

size_t Enemy::getSizeEnemies1()
{
	return this->enemies1.size();
}

size_t Enemy::getSizeEnemies2()
{
	return this->enemies2.size();
}

size_t Enemy::getSizeEnemies3()
{
	return this->enemies3.size();
}

void Enemy::removeEnemyEnemies1(size_t index)
{
	this->enemies1.erase(this->enemies1.begin() + index);
}

void Enemy::removeEnemyEnemies2(size_t index)
{
	this->enemies2.erase(this->enemies2.begin() + index);
}

void Enemy::removeEnemyEnemies3(size_t index)
{
	this->enemies3.erase(this->enemies3.begin() + index);
}

sf::Sprite Enemy::getEnemyEnemies1(size_t index)
{
	return this->enemies1[index];
}

sf::Sprite Enemy::getEnemyEnemies2(size_t index)
{
	return this->enemies2[index];
}

sf::Sprite Enemy::getEnemyEnemies3(size_t index)
{
	return this->enemies3[index];
}

void Enemy::move(float step)
{
	//enemies1
	std::vector<sf::Sprite>::iterator it1;
	for (it1 = this->enemies1.begin(); it1 < this->enemies1.end(); it1++)
	{
		it1->setPosition(it1->getPosition().x + step, it1->getPosition().y);
	}

	//enemies2
	std::vector<sf::Sprite>::iterator it2;
	for (it2 = this->enemies2.begin(); it2 < this->enemies2.end(); it2++)
	{
		it2->setPosition(it2->getPosition().x + step, it2->getPosition().y);
	}

	//enemies3
	std::vector<sf::Sprite>::iterator it3;
	for (it3 = this->enemies3.begin(); it3 < this->enemies3.end(); it3++)
	{
		it3->setPosition(it3->getPosition().x + step, it3->getPosition().y);
	}
}

void Enemy::IncrementSpeedCounter()
{
	this->speedCounter++;
}


void Enemy::ResetSpeedCounter()
{
	this->speedCounter = 0;
}

int Enemy::getCurrentMoveTimer()
{
	return this->currentMoveTimer;
}

void Enemy::playInvaderKilledSound()
{
	this->invaderKilledSound->play();
}

void Enemy::changeTextures()
{
	if (currentTextureIndex == 0)
	{
		//enemies1
		for (size_t i = 0; i < this->enemies1.size(); i++)
		{
			enemies1[i].setTexture(this->enemiesTex1[1]);
		}

		//enemies2
		for (size_t i = 0; i < this->enemies2.size(); i++)
		{
			enemies2[i].setTexture(this->enemiesTex2[1]);
		}

		//enemies3
		for (size_t i = 0; i < this->enemies3.size(); i++)
		{
			enemies3[i].setTexture(this->enemiesTex3[1]);
		}
		this->currentTextureIndex = 1;
	}
	else
	{
		//enemies1
		for (size_t i = 0; i < this->enemies1.size(); i++)
		{
			enemies1[i].setTexture(this->enemiesTex1[0]);
		}

		//enemies2
		for (size_t i = 0; i < this->enemies2.size(); i++)
		{
			enemies2[i].setTexture(this->enemiesTex2[0]);
		}

		//enemies3
		for (size_t i = 0; i < this->enemies3.size(); i++)
		{
			enemies3[i].setTexture(this->enemiesTex3[0]);
		}
		this->currentTextureIndex = 0;
	}
}

void Enemy::changeDirection()
{
	this->maxSpeed = -this->maxSpeed;
}

void Enemy::decrementMoveTimer(int value)
{
	this->currentMoveTimer-=value;
}

int Enemy::getSpeedCounter()
{
	return this->speedCounter;
}