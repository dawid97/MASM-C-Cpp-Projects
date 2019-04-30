#include "Menu.h"



Menu::Menu(sf::RenderWindow*window)
{
	game = nullptr;
	gameOver = nullptr;
	mainMenu = new MainMenu(window);
    submitscore = nullptr;
	highscores = nullptr;
	pause = nullptr;
	enterKey = false;

	tmpScore = -1;
	choose = -1;
	currentState = MM;
}


Menu::~Menu()
{

}

int Menu::update(sf::RenderWindow*window)
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::TextEntered && submitscore != nullptr)
		{
			submitscore->updateUserName(window, &event);
		}
		if (choose == 2 && currentState == MM)
		{
			choose = -1;
			delete mainMenu;
			mainMenu = nullptr;
			return 0;
		}
		if (choose == 0 && currentState == MM)
		{
			choose = -1;
			delete mainMenu;
			mainMenu = nullptr;
			currentState = MG;
			game = new Game(window);
		}
		if (choose == 2 && currentState == GO)
		{
			choose = -1;
			delete game;
			game = nullptr;
			delete gameOver;
			gameOver = nullptr;
			return 0;
		}
		if (choose == 0 && currentState == GO)
		{
			choose = -1;
			currentState = MM;
			delete game;
			game = nullptr;
			delete gameOver;
			gameOver = nullptr;
			mainMenu = new MainMenu(window);
		}
	    if (choose == 1 && currentState == GO)
		{
			choose = -1;
			currentState = SS;
			delete game;
			game = nullptr;
			delete gameOver;
			gameOver = nullptr;
			submitscore = new Submitscore(window,	playerScore);
		}
		if (choose == 2 && currentState == SS)
		{
			choose = -1;
			delete submitscore;
			submitscore = nullptr;
			return 0;
		}
		if (choose == 1 && currentState == SS)
		{
			choose = -1;
			delete submitscore;
			submitscore = nullptr;
			currentState = HS;
			highscores = new Highscores(window);
		}
		if (choose == 0 && currentState == HS)
		{
			enterKey = true;
			choose = -1;

			delete highscores;
			highscores = nullptr;
			currentState = MM;
			mainMenu = new MainMenu(window);
		}
		if (choose == 1 && currentState == MM)
		{
			choose = -1;
			delete mainMenu;
			mainMenu = nullptr;
			currentState = HS;
			highscores = new Highscores(window);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && currentState == MG)
		{
			pause = new Pause(window);
			currentState = PG;
		}
		if (choose == 0 && currentState == PG)
		{
			choose = -1;
			delete pause;
			pause = nullptr;
			currentState = MG;
		}
		if (choose == 1 && currentState == PG)
		{
			choose = -1;
			delete pause;
			pause = nullptr;
			delete game;
			game = nullptr;
			mainMenu = new MainMenu(window);
			currentState = MM;
		}
		if (choose == 2 && currentState == PG)
		{
			choose = -1;
			delete pause;
			pause = nullptr;
			delete game;
			game = nullptr;
			return 0;
		}
		
	}

	if (tmpScore != -1 && currentState == MG)
	{
		playerScore = tmpScore;
		tmpScore = -1;
		currentState = GO;
		gameOver = new GameOver(window);
	}

	window->clear(sf::Color::Black);

	//highscores
	if (highscores != nullptr)
	{
		choose = highscores->update(window);
		highscores->render(window);
	}

	//submitscore
	if (submitscore != nullptr)
	{
		choose = submitscore->update(window);
		submitscore->render(window);
	}

	//main menu
	if (mainMenu != nullptr)
	{
		choose = mainMenu->update(window);
		mainMenu->render(window);
	}

	//game
	if (game != nullptr)
	{
		if (gameOver == nullptr && pause == nullptr)
			tmpScore = game->update(window);

		game->render(window);
	}

	//game over
	if (gameOver != nullptr)
	{
		gameOver->render(window);
		choose = gameOver->update(window);
	}

	//pause
	if (pause != nullptr)
	{
		choose = pause->update(window);
		pause->render(window);
	}

	window->display();

	return -1;
}
