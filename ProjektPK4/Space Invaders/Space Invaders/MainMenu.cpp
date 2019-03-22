#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window)
{
	this->maxNumberOfItems = 3;
	this->selectedItemIndex = 0;
	//this->enterKey = false;
	this->downKey = false;
	this->upKey = false;


	this->background = std::unique_ptr<sf::Sprite>(new sf::Sprite());

	this->backgroundTex = std::unique_ptr<sf::Texture>(new sf::Texture());
	if (!backgroundTex->loadFromFile("Textures/background.png"))
		throw LoadingError("Background loading error");

	
	background->setTexture(*backgroundTex);
	background->setScale(sf::Vector2f(0.8f,1.f));
	background->setOrigin(background->getLocalBounds().width / 2.f, background->getLocalBounds().height / 2.f);
	background->setPosition(window->getSize().x/2.f,window->getSize().y/2.f);

	this->font = std::unique_ptr<sf::Font>(new sf::Font());
	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");


	this->title = std::unique_ptr<sf::Text>(new sf::Text());
	this->chooseActionText = std::unique_ptr<sf::Text>(new sf::Text());


	sf::RectangleShape mainBlock;
	mainBlock.setSize(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f));
	mainBlock.setFillColor(sf::Color(180, 180, 180, 70));
	mainBlock.setOutlineThickness(2.f);
	mainBlock.setOutlineColor(sf::Color::Green);
	mainBlock.setOrigin(mainBlock.getGlobalBounds().width / 2.f, mainBlock.getGlobalBounds().height / 2.f);
	mainBlock.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	blocks.push_back(mainBlock);

	sf::RectangleShape playGame;
	playGame.setSize(sf::Vector2f(mainBlock.getSize().x / 1.2f, mainBlock.getSize().y / 5.f));
	playGame.setFillColor(sf::Color::Black);
	playGame.setOutlineThickness(2.f);
	playGame.setOutlineColor(sf::Color::Green);
	playGame.setOrigin(playGame.getGlobalBounds().width / 2.f, playGame.getGlobalBounds().height / 2.f);
	playGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y / 1.3f);
	blocks.push_back(playGame);

	sf::RectangleShape submitScores(playGame);
	submitScores.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y);
	blocks.push_back(submitScores);

	sf::RectangleShape exitGame(playGame);
	exitGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y / 0.81f);
	blocks.push_back(exitGame);

	title->setFont(*font);
	title->setCharacterSize(60);
	title->setFillColor(sf::Color::White);
	title->setString("SPACE INVADERS");
	sf::FloatRect boundsTitle = title->getLocalBounds();
	sf::Vector2f centerTitle(boundsTitle.left + boundsTitle.width / 2.f, boundsTitle.top + boundsTitle.height / 2.f);
	title->setOrigin(centerTitle);
	title->setPosition(window->getSize().x / 2.f, window->getSize().y / 7.f);

	chooseActionText->setFont(*font);
	chooseActionText->setCharacterSize(17);
	chooseActionText->setFillColor(sf::Color::White);
	chooseActionText->setString("CHOOSE ACTION");
	sf::FloatRect boundsGameOver = chooseActionText->getLocalBounds();
	sf::Vector2f centerGameOver(boundsGameOver.left + boundsGameOver.width / 2.f, boundsGameOver.top + boundsGameOver.height / 2.f);
	chooseActionText->setOrigin(centerGameOver);
	chooseActionText->setPosition(window->getSize().x / 2.f, window->getSize().y / 3.15f);


	sf::Text playGameText(*chooseActionText);
	playGameText.setFillColor(sf::Color::Red);
	playGameText.setString("PLAY GAME");
	sf::FloatRect boundsPlayGame = playGameText.getLocalBounds();
	sf::Vector2f centerPlayGame(boundsPlayGame.left + boundsPlayGame.width / 2.f, boundsPlayGame.top + boundsPlayGame.height / 2.f);
	playGameText.setOrigin(centerPlayGame);
	playGameText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.65f);
	texts.push_back(playGameText);
	

	sf::Text highScoresText(*chooseActionText);
	highScoresText.setString("HIGHSCORES");
	sf::FloatRect boundsHighScores =highScoresText.getLocalBounds();
	sf::Vector2f centerHighScores(boundsHighScores.left + boundsHighScores.width / 2.f, boundsHighScores.top + boundsHighScores.height / 2.f);
	highScoresText.setOrigin(centerHighScores);
	highScoresText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	texts.push_back(highScoresText);

	sf::Text exitText(*chooseActionText);
	exitText.setString("EXIT GAME");
	sf::FloatRect boundsExit = exitText.getLocalBounds();
	sf::Vector2f centerExit(boundsExit.left + boundsExit.width / 2.f, boundsExit.top + boundsExit.height / 2.f);
	exitText.setOrigin(centerExit);
	exitText.setPosition(window->getSize().x / 2.f, window->getSize().y / 1.63f);
	texts.push_back(exitText);
}

void MainMenu::Update(sf::RenderWindow* window)
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

void MainMenu::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	window->draw(*this->title);

	std::vector<sf::RectangleShape>::iterator it1;
	for (it1 = blocks.begin(); it1 < blocks.end(); it1++)
		window->draw(*it1);

	window->draw(*this->chooseActionText);
	std::vector<sf::Text>::iterator it2;
	for (it2 = texts.begin(); it2 < texts.end(); it2++)
		window->draw(*it2);
}

void MainMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		texts[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

void MainMenu::moveDown()
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