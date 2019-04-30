#include "Submitscore.h"



Submitscore::Submitscore(sf::RenderWindow*window,int score):MainMenu(window)
{
	this->score = score;


	//main block
	this->blocks.clear();
	this->blocks.push_back(Block(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f),
		sf::Color(180, 180, 180, 70), 2.f, sf::Color::Green, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f), "ENTER NAME", sf::Vector2f(400.f, 210.f), sf::Color::White));

	//buttons
	this->buttons[0].setString("");
	this->buttons[0].setFillColor(sf::Color(0, 191, 255));
	this->buttons[1].setString("SUBMIT SCORE");
	this->buttons[2].setString("EXIT GAME");

	//font
	this->name = std::unique_ptr<sf::Text>(new sf::Text());
	name->setFont(*font);
	this->name->setCharacterSize(15);

	try
	{
		this->loadPlayers();
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void Submitscore::render(sf::RenderWindow*window)
{
	window->draw(*this->background);

	for (size_t i = 0; i < this->blocks.size(); i++)
		this->blocks[i].render(window);

	for (size_t i = 0; i < this->buttons.size(); i++)
		this->buttons[i].render(window);

	window->draw(*this->name);
}

void Submitscore::moveUp()
{
	if (selectedItemIndex - 1 == 0)
	{
		selectedItemIndex--;
		buttons[selectedItemIndex].setFillColor(sf::Color(0, 191, 255));
		buttons[selectedItemIndex + 1].setTextColor(sf::Color::White);
	}
	else if (selectedItemIndex - 1 > 0)
	{
		buttons[selectedItemIndex].setTextColor(sf::Color::White);
		selectedItemIndex--;
		buttons[selectedItemIndex].setTextColor(sf::Color(0, 191, 255));
	}
}

void Submitscore::moveDown()
{
	if (selectedItemIndex == 0)
	{
		buttons[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		buttons[selectedItemIndex].setTextColor(sf::Color(0, 191, 255));
	}
	else if (selectedItemIndex + 1 < maxNumberOfItems)
	{
		buttons[selectedItemIndex].setTextColor(sf::Color::White);
		selectedItemIndex++;
		buttons[selectedItemIndex].setTextColor(sf::Color(0, 191, 255));
	}
}

int Submitscore::update(sf::RenderWindow* window)
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && buttons[1].getTextColor() == sf::Color(0, 191, 255))
	{
		addPlayer(this->name->getString(), std::to_string(this->score));
		return 1;
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && buttons[2].getTextColor() == sf::Color(0, 191, 255))
		return 2;

	return -1;
}

void Submitscore::updateUserName(sf::RenderWindow*window, sf::Event*event)
{
	if (event->text.unicode < 128)
	{
		if (event->text.unicode > 96 && event->text.unicode < 123)
			event->text.unicode -= 32;

		std::unique_ptr<sf::String>str(new sf::String);
		*str = this->name->getString();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && this->buttons[0].getFillColor() == sf::Color(0, 191, 255))
		{
			if (str->getSize() > 0)
				str->erase(str->getSize() - 1, 1);
		}
		if (isprint(event->text.unicode) && str->getSize() < 15 && this->buttons[0].getFillColor() == sf::Color(0, 191, 255))
		{
			*str += static_cast<char>(event->text.unicode);
		}
		this->name->setString(*str);
		this->name->setOrigin(this->name->getLocalBounds().left + this->name->getLocalBounds().width / 2.f, this->name->getLocalBounds().top + this->name->getLocalBounds().height / 2.f);
		this->name->setPosition(this->buttons[0].getPosition().x, this->buttons[0].getPosition().y);
	}
}

Submitscore::~Submitscore()
{

}

void Submitscore::savePlayers()
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
		if (it != playersScores.end() - 1)
			file << '\n';
	}
}

bool Submitscore::isPlayer(std::string name, std::string score)
{
	std::vector<PlayerScore>::iterator it;
	for (it = playersScores.begin(); it < playersScores.end(); it++)
	{
		if ((*it).name.getString() == name)
			return true;
	}
	return false;
}

bool Submitscore::betterResult(std::string name, std::string score)
{
	int tmpScoreUser = stoi(score);
	
	std::vector<PlayerScore>::iterator it;
	for (it = playersScores.begin(); it < playersScores.end(); it++)
	{
		std::string tmp = (*it).score.getString();
		int tmpScore = stoi(tmp);
		if ((*it).name.getString() == name && tmpScore < tmpScoreUser)
			return true;
	}
	return false;
}

void Submitscore::addPlayer(std::string name, std::string score)
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

	tmpScore.name.setString(name);
	tmpScore.score.setString(score);

	playersScores.push_back(tmpScore);
	std::sort(playersScores.begin(), playersScores.end());

	for (int i = 0; i < playersScores.size(); i++)
	{
		if (i == 10)
			playersScores.erase(playersScores.begin() + i, playersScores.end());
	}

	try
	{
		savePlayers();
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void Submitscore::loadPlayers()
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

	while (!file.eof() && counter < 10)
	{
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
				tmp.name = playerText;
			else
				tmp.score = playerText;
		}

		playersScores.push_back(PlayerScore(tmp));

		counter++;
	}
	file.close();
}