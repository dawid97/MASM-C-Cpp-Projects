#include "Highscores.h"



Highscores::Highscores(sf::RenderWindow*window)
{
	this->background = std::unique_ptr<sf::Sprite>(new sf::Sprite());
	this->backgroundTex = std::unique_ptr<sf::Texture>(new sf::Texture());
	if (!backgroundTex->loadFromFile("Textures/background.png"))
		throw LoadingError("Background loading error");


	background->setTexture(*backgroundTex);
	background->setScale(sf::Vector2f(0.8f, 1.f));
	background->setOrigin(background->getLocalBounds().width / 2.f, background->getLocalBounds().height / 2.f);
	background->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);


	this->font = std::unique_ptr<sf::Font>(new sf::Font());
	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");


	this->title = std::unique_ptr<sf::Text>(new sf::Text());
	title->setFont(*font);
	title->setCharacterSize(60);
	title->setFillColor(sf::Color::White);
	title->setString("HIGHSCORES");
	sf::FloatRect boundsTitle = title->getLocalBounds();
	sf::Vector2f centerTitle(boundsTitle.left + boundsTitle.width / 2.f, boundsTitle.top + boundsTitle.height / 2.f);
	title->setOrigin(centerTitle);
	title->setPosition(window->getSize().x / 2.f, window->getSize().y / 15.f);


	sf::RectangleShape mainBlock;
	mainBlock.setSize(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f));
	mainBlock.setFillColor(sf::Color(180, 180, 180, 70));
	mainBlock.setOutlineThickness(2.f);
	mainBlock.setOutlineColor(sf::Color::Green);
	mainBlock.setOrigin(mainBlock.getGlobalBounds().width / 2.f, mainBlock.getGlobalBounds().height / 2.f);
	mainBlock.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	blocks.push_back(mainBlock);


	sf::RectangleShape playGame(mainBlock);
	playGame.setSize(sf::Vector2f(mainBlock.getSize().x / 1.2f, mainBlock.getSize().y / 5.f));
	playGame.setFillColor(sf::Color::Black);
	playGame.setOrigin(playGame.getGlobalBounds().width / 2.f, playGame.getGlobalBounds().height / 2.f);
	playGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y / 1.3f);
	blocks.push_back(playGame);

}


void Highscores::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	window->draw(*this->title);

	
	std::vector<sf::RectangleShape>::iterator it1;
	for (it1 = blocks.begin(); it1 < blocks.end(); it1++)
		window->draw(*it1);

	

	std::vector<sf::Text>::iterator it2;
	for (it2 = texts.begin(); it2 < texts.end(); it2++)
		window->draw(*it2);
		
}
