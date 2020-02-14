#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow*window):GameOver(window)
{
	this->blocks.clear();
	this->blocks.push_back(Block(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f),
		sf::Color(180, 180, 180, 70), 2.f, sf::Color::Green, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f), "CHOOSE ACTION", sf::Vector2f(400.f, 210.f), sf::Color::White));
	

	this->buttons[0].setString("PLAY GAME");
	this->buttons[1].setString("HIGHSCORES");
	this->buttons[2].setString("EXIT GAME");

	try
	{
		this->fontInitialization("Fonts/SpaceInvader.ttf");
		this->backgroundInitialization(window);
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void MainMenu::backgroundInitialization(sf::RenderWindow*window)
{
	this->background = std::unique_ptr<sf::Sprite>(new sf::Sprite());
	this->backgroundTex = std::unique_ptr<sf::Texture>(new sf::Texture());

	if (!backgroundTex->loadFromFile("Textures/background2.jpg"))
		throw LoadingError("Background loading error");

	background->setTexture(*backgroundTex);
	background->setScale(sf::Vector2f(0.8f, 0.8f));
	background->setOrigin(background->getLocalBounds().width / 2.f, background->getLocalBounds().height / 2.f);
	background->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
}

void MainMenu::fontInitialization(std::string fileNameFont)
{
	this->font = std::unique_ptr<sf::Font>(new sf::Font());

	if (!this->font->loadFromFile(fileNameFont))
		throw LoadingError("Font loading error!");
}

void MainMenu::render(sf::RenderWindow*window)
{
	window->draw(*this->background);
	//window->draw(*this->title);

	for (size_t i = 0; i < this->blocks.size(); i++)
		this->blocks[i].render(window);

	for (size_t i = 0; i < this->buttons.size(); i++)
		this->buttons[i].render(window);
}



