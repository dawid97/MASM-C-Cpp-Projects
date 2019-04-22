#include "Highscores.h"

void Highscores::backgroundInitialization(sf::RenderWindow*window)
{
	this->background = std::unique_ptr<sf::Sprite>(new sf::Sprite());
	this->backgroundTex = std::unique_ptr<sf::Texture>(new sf::Texture());
	if (!backgroundTex->loadFromFile("Textures/background.png"))
		throw LoadingError("Background loading error");

	background->setTexture(*backgroundTex);
	background->setScale(sf::Vector2f(0.9f, 1.1f));
	background->setOrigin(background->getLocalBounds().width / 2.f, background->getLocalBounds().height / 2.f);
	background->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
}

void Highscores::fontInitialization()
{
	this->font = std::unique_ptr<sf::Font>(new sf::Font());
	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");
}

void Highscores::titleInitialization(sf::RenderWindow*window)
{
	this->title = std::unique_ptr<sf::Text>(new sf::Text());
	title->setFont(*font);
	title->setCharacterSize(60);
	title->setFillColor(sf::Color::White);
	title->setString("HIGHSCORES");
	sf::FloatRect boundsTitle = title->getLocalBounds();
	sf::Vector2f centerTitle(boundsTitle.left + boundsTitle.width / 2.f, boundsTitle.top + boundsTitle.height / 2.f);
	title->setOrigin(centerTitle);
	title->setPosition(window->getSize().x / 2.f, window->getSize().y / 12.f);
}

Highscores::Highscores(sf::RenderWindow*window)
{
	try
	{
		this->fontInitialization();
		this->backgroundInitialization(window);
		this->loadPlayers(window);
	}
	catch (LoadingError ex)
	{
		ex.DisplayMessage();
	}

	this->titleInitialization(window);
	this->buttonInitialization(window);
}
	
void Highscores::buttonInitialization(sf::RenderWindow*window)
{
	//main block
	this->blocks.push_back(Block(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 9.f),
		sf::Color(180, 180, 180, 70), 2.f, sf::Color::Green, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 1.09f), "", sf::Vector2f(400.f, 210.f), sf::Color::Red));

	//buttons
	this->buttons.push_back(Button(sf::Color::Black, 2.f, sf::Color::Green, sf::Vector2f(175.f, 50.f), sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 1.09f), "MAIN MENU", 17, sf::Color(0, 191, 255)));
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
			block.setPosition(window->getSize().x / 2.f, window->getSize().y / 4.5f);
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


void Highscores::render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	window->draw(*this->title);

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

	std::vector<Block>::iterator it1;
	for (it1 = this->blocks.begin(); it1 < this->blocks.end(); it1++)
		it1->render(window);

	std::vector<Button>::iterator it5;
	for (it5 = this->buttons.begin(); it5 < this->buttons.end(); it5++)
		it5->render(window);
}

int Highscores::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		return 0;

	return -1;
}
