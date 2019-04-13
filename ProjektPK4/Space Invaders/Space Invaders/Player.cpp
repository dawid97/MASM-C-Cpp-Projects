#include "Player.h"



Player::Player(sf::Vector2f position,sf::Vector2f scale,float speed,float shootTimer,std::string shootSound,std::string explosionSound, std::string shipTex)
{
	this->shootTimer = shootTimer;
	this->currentShootTimer = this->shootTimer;
	this->maxSpeed = speed;
	this->score = 0;
	this->hp = 3;

	try
	{
		//shootSound
		this->soundBufferShoot = std::unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer);

		if (!soundBufferShoot->loadFromFile(shootSound))
			throw LoadingError("sound shoot loading error");

		this->shootSound = std::unique_ptr<sf::Sound>(new sf::Sound);
		this->shootSound->setBuffer(*this->soundBufferShoot);
		
		//explosionSound
		this->soundBufferExplosion = std::unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer);

		if (!soundBufferExplosion->loadFromFile(explosionSound))
			throw LoadingError("sound explosion loading error");

		this->explosionSound = std::unique_ptr<sf::Sound>(new sf::Sound);
		this->explosionSound->setBuffer(*this->soundBufferExplosion);

		//shipTexture
		this->playerTex = std::unique_ptr<sf::Texture>(new sf::Texture);
		if (!playerTex->loadFromFile(shipTex))
			throw LoadingError("ship texture loading error");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	//player
	player.setTexture(*playerTex);
	player.setScale(sf::Vector2f(scale));
	player.setOrigin(player.getLocalBounds().width / 2.f, player.getLocalBounds().height / 2.f);
	player.setPosition(position);
}

void Player::renderBullets(sf::RenderWindow*window)
{
	std::vector<Bullet>::iterator it;
	for (it = bullets.begin(); it < bullets.end(); it++)
	{
		it->render(window);
	}
}

void Player::collisionScreen(sf::RenderWindow*window)
{
	//collision left screen
	if (player.getPosition().x - player.getGlobalBounds().width / 2.f < 0)
		player.setPosition(player.getGlobalBounds().width / 2.f, player.getPosition().y);

	//collision right screen
	if (player.getPosition().x + player.getGlobalBounds().width / 2.f > window->getSize().x)
		player.setPosition(window->getSize().x - player.getGlobalBounds().width / 2.f, player.getPosition().y);

	//bullets out of window
	std::vector<Bullet>::iterator it;
	for (it = bullets.begin(); it < bullets.end(); it++)
	{
		it->move(sf::Vector2f(0.f,-it->getSpeed()));

		if (it->getPosition().y < 0)
		{
			bullets.erase(bullets.begin() + std::distance(bullets.begin(), it));
			break;
		}
	}
}

void Player::move(sf::RenderWindow*window)
{
	//move right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.move(maxSpeed, 0.f);

	//move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.move(-maxSpeed, 0.f);
}

void Player::shoot()
{
	//update shooting
	if (currentShootTimer < shootTimer)
		currentShootTimer += 1.f;

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && currentShootTimer >= shootTimer)
	{
		this->bullets.push_back(Bullet(5.f,this->getPosition(),sf::Vector2f(0.1f, 0.2f), "Textures/bullet.png"));
		this->shootSound->play();

		//reset timer
		currentShootTimer = 0.f;
	}
}

void Player::render(sf::RenderWindow*window)
{
	window->draw(player);
	this->renderBullets(window);
}

void Player::update(sf::RenderWindow*window)
{
	this->move(window);
	this->collisionScreen(window);
	this->shoot();
}

void Player::addScore(int score)
{
	this->score += score;
}

void Player::removeBullet(size_t index)
{
	this->bullets.erase(bullets.begin() + index);
}

Bullet Player::getBullet(size_t index)
{
	return this->bullets[index];
}

size_t Player::getBulletsSize()
{
	return this->bullets.size();
}

sf::Vector2f Player::getPosition()
{
	return player.getPosition();
}

int Player::getScore()
{
	return this->score;
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->player.getGlobalBounds();
}

void Player::removeHp()
{
	this->hp--;
}

int Player::getHp()
{
	return this->hp;
}

void Player::playExplosionSound()
{
	this->explosionSound->play();
}

void Player::setPosition(sf::Vector2f position)
{
	this->player.setPosition(position);
}

void Player::clearBullets()
{
	this->bullets.clear();
}