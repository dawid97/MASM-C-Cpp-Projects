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
	mainBlock.setSize(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 9.f));
	mainBlock.setFillColor(sf::Color(180, 180, 180, 70));
	mainBlock.setOutlineThickness(2.f);
	mainBlock.setOutlineColor(sf::Color::Green);
	mainBlock.setOrigin(mainBlock.getGlobalBounds().width / 2.f, mainBlock.getGlobalBounds().height / 2.f);
	mainBlock.setPosition(window->getSize().x / 2.f, window->getSize().y / 1.09f);
	blocksMenu.push_back(mainBlock);


	sf::RectangleShape playGame(mainBlock);
	playGame.setSize(sf::Vector2f(mainBlock.getSize().x / 1.2f, mainBlock.getSize().y / 2.f));
	playGame.setFillColor(sf::Color(0, 191, 255));
	playGame.setOrigin(playGame.getGlobalBounds().width / 2.f, playGame.getGlobalBounds().height / 2.f);
	playGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y);
	blocksMenu.push_back(playGame);

	this->mainMenu = std::unique_ptr<sf::Text>(new sf::Text(*this->title));
	mainMenu->setCharacterSize(17);
	mainMenu->setString("MAIN MENU");
	sf::FloatRect boundsMainMenu = mainMenu->getLocalBounds();
	sf::Vector2f centerMainMenu(boundsMainMenu.left + boundsMainMenu.width / 2.f, boundsMainMenu.top + boundsMainMenu.height / 2.f);
	mainMenu->setOrigin(centerMainMenu);
	mainMenu->setPosition(playGame.getPosition().x,playGame.getPosition().y);


	try
	{
		this->loadPlayers(window);
	}
	catch (LoadingError ex)
	{
		ex.DisplayMessage();
	}
}

void Highscores::savePlayers()
{
	std::fstream file;
	file.open("playersData.txt", std::ios::out);
	if (!file.good())
		throw LoadingError("PlayersData opening error");

	std::vector<PlayerScore>::iterator it;
	for (it = playersScores.begin(); it < playersScores.end(); it++)
	{
		std::string s;
		s = (*it).name.getString();
		file << s << '\n';
		s = (*it).score.getString();
		file << s;
		if (it != playersScores.end()-1)
			file << '\n';
	}
}

bool Highscores::isPlayer(std::string name, std::string score)
{
	std::vector<PlayerScore>::iterator it;
	for (it = playersScores.begin(); it < playersScores.end(); it++)
	{
		if ((*it).name.getString() == name)
			return true;
	}
	return false;
}

bool Highscores::betterResult(std::string name, std::string score)
{
	int tmpScoreUser = stoi(score);
	std::cout << tmpScoreUser << std::endl;
	std::cout << "-----------------" << std::endl;

	std::vector<PlayerScore>::iterator it;
	for (it = playersScores.begin(); it < playersScores.end(); it++)
	{
		std::string tmp = (*it).score.getString();
		int tmpScore = stoi(tmp);
		std::cout << tmpScore << std::endl;
		if ((*it).name.getString() == name && tmpScore < tmpScoreUser)
			return true;
	}
	return false;
}

void Highscores::addPlayer(std::string name,std::string score)
{

	if (betterResult(name, score))
	{
		for (int i = 0; i < playersScores.size(); i++)
		{
			if (playersScores[i].name.getString() == name)
			{
				playersScores[i].score.setString(score);
				savePlayers();
				return;
			}
		}
	}

	if (isPlayer(name, score))
		return;

	PlayerScore tmpScore;

	sf::Text tmpText1;
	tmpText1.setString(name);
	tmpScore.name = tmpText1;

	sf::Text tmpText2;
	tmpText2.setString(score);
	tmpScore.score = tmpText2;

	playersScores.push_back(tmpScore);
	std::sort(playersScores.begin(), playersScores.end());

	for (int i=0;i<playersScores.size();i++)
	{
		if (i == 10)
			playersScores.erase(playersScores.begin() + i, playersScores.end());
	}
	savePlayers();
}

void Highscores::loadPlayers(sf::RenderWindow*window)
{
	std::fstream file;
	file.open("playersData.txt", std::ios::in);
	if (!file.good())
		throw LoadingError("PlayersData loading error");

	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return;
	else
		file.seekg(0, std::ios::beg);
	

	int counter = 0;
	
	while (!file.eof() && counter<10)
	{
		sf::RectangleShape block;
		block.setSize(sf::Vector2f(window->getSize().x / 1.3f, window->getSize().y / 20.f));

		if (counter % 2 == 0)
			block.setFillColor(sf::Color(180, 180, 180, 70));
		else
			block.setFillColor(sf::Color::Black);

		block.setOutlineThickness(2.f);
		block.setOutlineColor(sf::Color::Green);
		block.setOrigin(block.getGlobalBounds().width / 2.f, block.getGlobalBounds().height / 2.f);

		if (counter == 0)
			block.setPosition(window->getSize().x / 2.f, window->getSize().y / 5.5f);
		else
			block.setPosition(window->getSize().x / 2.f, playersBlocks[counter-1].getPosition().y + playersBlocks[counter-1].getGlobalBounds().height);

		playersBlocks.push_back(sf::RectangleShape(block));

		PlayerScore tmp;

		for (int i = 0; i < 2; i++)
		{
			sf::Text playerText;
			playerText.setFont(*font);
			playerText.setCharacterSize(17);
			playerText.setFillColor(sf::Color::White);
			std::string s;
			std::getline(file, s);
			playerText.setString(s);

			if (i == 0)
			{
				playerText.setPosition(this->playersBlocks[counter].getPosition().x / 0.5f / 5.5f, this->playersBlocks[counter].getPosition().y - 11.f);
				tmp.name = playerText;
			}
			else
			{
				playerText.setPosition(this->playersBlocks[counter].getPosition().x + this->playersBlocks[counter].getGlobalBounds().width / 2.f - playerText.getGlobalBounds().width - 11.f, this->playersBlocks[counter].getPosition().y - 11.f);
				tmp.score = playerText;
			}
		}
		playersScores.push_back(PlayerScore(tmp));

		sf::Text number;
		number.setFont(*font);
		number.setCharacterSize(17);
		number.setFillColor(sf::Color::White);
		number.setPosition(this->playersBlocks[counter].getPosition().x / 4.f, this->playersBlocks[counter].getPosition().y - 11.f);
		number.setString(std::to_string(counter + 1));
		numbers.push_back(sf::Text(number));

		counter++;
	}
	std::reverse(numbers.begin(), numbers.end());
	file.close();
}


void Highscores::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	window->draw(*this->title);
	
	std::vector<sf::RectangleShape>::iterator it1;
	for (it1 = blocksMenu.begin(); it1 < blocksMenu.end(); it1++)
		window->draw(*it1);

	std::vector<sf::RectangleShape>::iterator it3;
	for (it3 = playersBlocks.begin(); it3 < playersBlocks.end(); it3++)
		window->draw(*it3);

	std::vector<PlayerScore>::iterator it2;
	for (it2 = playersScores.begin(); it2 < playersScores.end(); it2++)
	{
		window->draw((*it2).name);
		window->draw(sf::Text((*it2).score));
	}

	std::vector<sf::Text>::iterator it4;
	for (it4 = numbers.begin(); it4 < numbers.end(); it4++)
		window->draw(*it4);

	window->draw(*this->mainMenu);
}
