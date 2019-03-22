#include "GameOver.h"



GameOver::GameOver(sf::RenderWindow* window)
{
	this->maxNumberOfItems = 3;
	this->selectedItemIndex = 0;
	//this->enterKey = false;
	this->downKey = false;
	this->upKey = false;

	this->font = std::unique_ptr<sf::Font>(new sf::Font());
	this->gameOverText = std::unique_ptr<sf::Text>(new sf::Text());

	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");

	sf::RectangleShape mainBlock;
	mainBlock.setSize(sf::Vector2f(window->getSize().x/4.f,window->getSize().y/2.5f));
	mainBlock.setFillColor(sf::Color(180,180,180,70));
	mainBlock.setOutlineThickness(2.f);
	mainBlock.setOutlineColor(sf::Color::Green);
	mainBlock.setOrigin(mainBlock.getGlobalBounds().width / 2.f, mainBlock.getGlobalBounds().height / 2.f);
	mainBlock.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	blocks.push_back(mainBlock);

	sf::RectangleShape mainMenu;
	mainMenu.setSize(sf::Vector2f(mainBlock.getSize().x/1.2f,mainBlock.getSize().y/5.f));
	mainMenu.setFillColor(sf::Color::Black);
	mainMenu.setOutlineThickness(2.f);
	mainMenu.setOutlineColor(sf::Color::Green);
	mainMenu.setOrigin(mainMenu.getGlobalBounds().width / 2.f, mainMenu.getGlobalBounds().height / 2.f);
	mainMenu.setPosition(mainBlock.getPosition().x,mainBlock.getPosition().y/1.3f);
	blocks.push_back(mainMenu);

	sf::RectangleShape submitScores(mainMenu);
	submitScores.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y);
	blocks.push_back(submitScores);

	sf::RectangleShape exitGame(mainMenu);
	exitGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y/0.81f);
	blocks.push_back(exitGame);


	gameOverText->setFont(*font);
	gameOverText->setCharacterSize(17);
	gameOverText->setFillColor(sf::Color::White);
	gameOverText->setString("GAME OVER");
	sf::FloatRect boundsGameOver = gameOverText->getLocalBounds();
	sf::Vector2f centerGameOver(boundsGameOver.left + boundsGameOver.width / 2.f, boundsGameOver.top + boundsGameOver.height / 2.f);
	gameOverText->setOrigin(centerGameOver);
	gameOverText->setPosition(window->getSize().x / 2.f, window->getSize().y / 3.15f);
	

	sf::Text mainMenuText(*gameOverText);
	mainMenuText.setFillColor(sf::Color::Red);
	mainMenuText.setString("MAIN MENU");
	mainMenuText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.63f);
	texts.push_back(mainMenuText);

	sf::Text submitScoresText(*gameOverText);
	submitScoresText.setString("SUBMIT SCORES");
	sf::FloatRect boundsSubmitScores = submitScoresText.getLocalBounds();
	sf::Vector2f centerSubmitScores(boundsSubmitScores.left + boundsSubmitScores.width / 2.f, boundsSubmitScores.top + boundsSubmitScores.height / 2.f);
	submitScoresText.setOrigin(centerSubmitScores);
	submitScoresText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	texts.push_back(submitScoresText);

	sf::Text exitText(*gameOverText);
	exitText.setString("EXIT GAME");
	sf::FloatRect boundsExit = exitText.getLocalBounds();
	sf::Vector2f centerExit(boundsExit.left + boundsExit.width / 2.f, boundsExit.top + boundsExit.height / 2.f);
	exitText.setOrigin(centerExit);
	exitText.setPosition(window->getSize().x / 2.f, window->getSize().y / 1.63f);
	texts.push_back(exitText);
}

void GameOver::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->moveDown();
	}

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void GameOver::Render(sf::RenderWindow* window)
{

	std::vector<sf::RectangleShape>::iterator it1;
	for (it1 = blocks.begin(); it1 < blocks.end(); it1++)
		window->draw(*it1);

	window->draw(*this->gameOverText);
	std::vector<sf::Text>::iterator it2;
	for (it2 = texts.begin(); it2 < texts.end(); it2++)
		window->draw(*it2);
}

void GameOver::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		texts[selectedItemIndex].setFillColor(sf::Color::Red);
		
	}
}

void GameOver::moveDown()
{
	if (selectedItemIndex + 1 < maxNumberOfItems)
	{
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		texts[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey)
//{
//	coreState.SetState(new main_menu());
//}
//enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);