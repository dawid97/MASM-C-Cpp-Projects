#include "Player.h"



Player::Player(sf::RenderWindow*window)
{
	this->maxSpeed = 5;

	this->player = std::unique_ptr<sf::Sprite>(new sf::Sprite());
	this->playerTex = std::unique_ptr<sf::Texture>(new sf::Texture());

	if (!playerTex->loadFromFile("Textures/ship.png"))
		throw LoadingError("ship loading error");


	player->setTexture(*playerTex);
	player->setScale(sf::Vector2f(0.08f, 0.08f));
	player->setOrigin(player->getLocalBounds().width / 2.f, player->getLocalBounds().height / 2.f);
	player->setPosition(window->getSize().x / 2.f, window->getSize().y / 1.07f);
}


Player::~Player()
{

}

void Player::Render(sf::RenderWindow*window)
{
	window->draw(*player);
}

void Player::Update(sf::RenderWindow*window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->move(5.f, 0.f);
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->move(-5.f, 0.f);

	if (player->getPosition().x-player->getGlobalBounds().width/2.f < 0)
		player->setPosition(player->getGlobalBounds().width/2.f, player->getPosition().y);
	if (player->getPosition().x + player->getGlobalBounds().width/2.f > window->getSize().x)
		player->setPosition(window->getSize().x-player->getGlobalBounds().width/2.f,player->getPosition().y);
}

//Ship::Ship(Score* score, EntityManager* manager, float x, float y)
//{
//	this->active = 1;
//	this->groupId = 1;
//	this->Load("ship.png");
//	this->setColor(sf::Color::Green);
//
//	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);
//	this->space = false;
//
//	this->manager = manager;
//	this->score = score;
//}
//
//void Ship::Update(sf::RenderWindow* window)
//{
//	this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) * PLAYER_SPEED;
//	if (!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
//	{
//		if (playerAmmo > 0)
//		{
//			this->manager->Add("bullet", new Bullet(this->score, this->getPosition().x, this->getPosition().y - 32, -1, true));
//			playerAmmo -= 1;
//		}
//	}
//	this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
//	Entity::Update(window);
//}
//
//void Ship::Collision(Entity* entity)
//{
//	switch (entity->GroupID())
//	{
//	case 2:
//		gameOver = true;
//		break;
//	}
//}