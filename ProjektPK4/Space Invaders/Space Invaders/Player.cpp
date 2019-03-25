#include "Player.h"



Player::Player(float x,float y)
{
	this->shootTimer = 20.f;
	this->maxSpeed = 5;
	this->playerPosition = sf::Vector2f(x, y);


	if (!playerTex.loadFromFile("Textures/ship.png"))
		throw LoadingError("ship loading error");


	player.setTexture(playerTex);
	player.setScale(sf::Vector2f(0.08f, 0.08f));
	player.setOrigin(player.getLocalBounds().width / 2.f, player.getLocalBounds().height / 2.f);
	player.setPosition(x,y);
}


Player::~Player()
{

}

void Player::Render(sf::RenderWindow*window)
{
	//player
	window->draw(player);

	//bullets
	std::vector<Bullet>::iterator it;
	for (it=bullets.begin(); it < bullets.end(); it++)
	{
		it->render(window);
	}
}

void Player::Update(sf::RenderWindow*window)
{
	//move right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.move(maxSpeed, 0.f);
	
	//move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.move(-maxSpeed, 0.f);

	//collision left screen
	if (player.getPosition().x-player.getGlobalBounds().width/2.f < 0)
		player.setPosition(player.getGlobalBounds().width/2.f, player.getPosition().y);

	//collision right screen
	if (player.getPosition().x + player.getGlobalBounds().width/2.f > window->getSize().x)
		player.setPosition(window->getSize().x-player.getGlobalBounds().width/2.f,player.getPosition().y);

	//update shooting
	if (shootTimer < 20.f)
		shootTimer += 1.f;

	//shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootTimer >= 20)
	{
		this->bullets.push_back(Bullet(this->playerPosition));


		//reset timer
		shootTimer = 0.f;
	}

	std::vector<Bullet>::iterator it;

	for (it = bullets.begin(); it<bullets.end(); it++)
	{
		it->move(sf::Vector2f(0.f, -5.f));

		//bullets out of window
		if (it->getPosition().x > window->getSize().x)
		{
			bullets.erase(bullets.begin() + std::distance(bullets.begin(),it)); //moze powodowac blad
			break;
		}
	}
}

