#include "Player.h"



Player::Player(sf::Vector2f position)
{
	this->shootTimer = 35.f;
	this->maxSpeed = 5;

	//sound
	this->soundBuffer = std::unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer);
	if (!soundBuffer->loadFromFile("Sounds/shoot.wav"))
		throw LoadingError("sound shoot loading error");

	this->shootSound = std::unique_ptr<sf::Sound>(new sf::Sound);
	this->shootSound->setBuffer(*soundBuffer);

	//ship
	this->playerTex=std::unique_ptr<sf::Texture>(new sf::Texture);
	if (!playerTex->loadFromFile("Textures/ship.png"))
		throw LoadingError("ship loading error");

	//lives
	this->lifes.push_back(Life(sf::Vector2f(670.f, 30.f)));
	this->lifes.push_back(Life(sf::Vector2f(715.f, 30.f)));
	this->lifes.push_back(Life(sf::Vector2f(760.f, 30.f)));

	//player
	this->player = std::unique_ptr<sf::Sprite>(new sf::Sprite);
	player->setTexture(*playerTex);
	player->setScale(sf::Vector2f(0.04f, 0.04f));
	player->setOrigin(player->getLocalBounds().width / 2.f, player->getLocalBounds().height / 2.f);
	player->setPosition(position);
}

sf::Vector2f Player::getPosition()
{
	return player->getPosition();
}


Player::~Player()
{

}



void Player::renderBullets(sf::RenderWindow*window)
{
	std::vector<Bullet>::iterator it;
	for (it = bullets.begin(); it < bullets.end(); it++)
	{
		it->render(window);
	}
	std::cout << bullets.size() << std::endl;
}

void Player::renderLifes(sf::RenderWindow*window)
{
	std::vector<Life>::iterator it;
	for (it = lifes.begin(); it < lifes.end(); it++)
	{
		it->render(window);
	}
}

void Player::render(sf::RenderWindow*window)
{
	window->draw(*player);

	this->renderBullets(window);
	this->renderLifes(window);
}

void Player::collisionScreen(sf::RenderWindow*window)
{
	//collision left screen
	if (player->getPosition().x - player->getGlobalBounds().width / 2.f < 0)
		player->setPosition(player->getGlobalBounds().width / 2.f, player->getPosition().y);

	//collision right screen
	if (player->getPosition().x + player->getGlobalBounds().width / 2.f > window->getSize().x)
		player->setPosition(window->getSize().x - player->getGlobalBounds().width / 2.f, player->getPosition().y);

	//bullets out of window
	std::vector<Bullet>::iterator it;
	for (it = bullets.begin(); it < bullets.end(); it++)
	{
		it->move(sf::Vector2f(0.f, -5.f));

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
		player->move(maxSpeed, 0.f);

	//move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->move(-maxSpeed, 0.f);
}

void Player::shoot()
{
	//update shooting
	if (shootTimer < 35.f)
		shootTimer += 1.f;

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootTimer >= 35)
	{
		this->bullets.push_back(Bullet(this->getPosition()));
		this->shootSound->play();

		//reset timer
		shootTimer = 0.f;
	}
}

void Player::update(sf::RenderWindow*window)
{
	
	this->move(window);
	this->collisionScreen(window);
	this->shoot();
}

size_t Player::getBulletsSize()
{
	return this->bullets.size();
}

Bullet Player::getBullet(size_t index)
{
	return this->bullets[index];
}

void Player::removeBullet(size_t index)
{
	this->bullets.erase(bullets.begin() + index);
}




