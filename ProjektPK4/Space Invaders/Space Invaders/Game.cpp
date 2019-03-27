#include "Game.h"



Game::Game(sf::RenderWindow*window)
	:player(new Player(sf::Vector2f(window->getSize().x / 2.f, 680.f)))
{

}


Game::~Game()
{

}

void Game::mainGame(sf::RenderWindow*window)
{
	this->player->update(window);
	this->player->render(window);

	/*sf::Image shieldImage;
	sf::Sprite shield;
	sf::Texture shieldTex;

	if (!shieldImage.loadFromFile("Textures/shield9.png"))
		throw LoadingError("shield loading error");
	shieldTex.loadFromImage(shieldImage);
	shield.setTexture(shieldTex);
	shield.setScale(1.f, 1.f);

	std::vector<sf::Sprite> vec;
	vec.push_back(sf::Sprite(shield));

	sf::Sprite shield1(shield);
	shield1.setPosition(400.f, 300.f);
	vec.push_back(sf::Sprite(shield1));


	vec.push_back(sf::Sprite(shield));*/

	//for (auto x : vec)
	//	window->draw(x);
}
