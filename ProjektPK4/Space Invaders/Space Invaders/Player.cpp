#include "Player.h"



Player::Player(sf::Vector2f position)
{

	this->shootTimer = 20.f;
	this->maxSpeed = 5;

	//ship
	this->playerTex=std::unique_ptr<sf::Texture>(new sf::Texture);
	if (!playerTex->loadFromFile("Textures/ship.png"))
		throw LoadingError("ship loading error");

	//lives
	this->lives.push_back(Live(sf::Vector2f(655.f, 30.f)));
	this->lives.push_back(Live(sf::Vector2f(700.f, 30.f)));
	this->lives.push_back(Live(sf::Vector2f(745.f, 30.f)));

	//player
	this->player = std::unique_ptr<sf::Sprite>(new sf::Sprite);
	player->setTexture(*playerTex);
	player->setScale(sf::Vector2f(0.04f, 0.04f));
	player->setOrigin(player->getLocalBounds().width / 2.f, player->getLocalBounds().height / 2.f);
	player->setPosition(position);

	//shields
	this->shields.push_back(Shield(sf::Vector2f(700.f, 600.f)));
	this->shields.push_back(Shield(sf::Vector2f(500.f, 600.f)));
	this->shields.push_back(Shield(sf::Vector2f(300.f, 600.f)));
	this->shields.push_back(Shield(sf::Vector2f(100.f, 600.f)));
}

sf::Vector2f Player::getPosition()
{
	return player->getPosition();
}


Player::~Player()
{

}

void Player::renderShields(sf::RenderWindow*window)
{
	std::vector<Shield>::iterator it;
	for (it = shields.begin(); it < shields.end(); it++)
	{
		it->render(window);
	}
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

void Player::renderLives(sf::RenderWindow*window)
{
	std::vector<Live>::iterator it;
	for (it = lives.begin(); it < lives.end(); it++)
	{
		it->render(window);
	}
}

void Player::render(sf::RenderWindow*window)
{
	window->draw(*player);

	this->renderBullets(window);
	this->renderLives(window);
	this->renderShields(window);
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
	if (shootTimer < 20.f)
		shootTimer += 1.f;

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootTimer >= 20)
	{
		this->bullets.push_back(Bullet(this->getPosition()));

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

