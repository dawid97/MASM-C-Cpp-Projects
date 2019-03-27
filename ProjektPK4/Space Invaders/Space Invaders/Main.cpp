#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"GameOver.h"
#include"MainMenu.h"
#include"SubmitScores.h"
#include"Highscores.h"
#include"Game.h"
#include<conio.h>

#include<vld.h>

constexpr int ScreenWidth = 800;
constexpr int ScreenHeight =700;


int main()
{
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Hello world");
	window.setFramerateLimit(60);

	std::unique_ptr<Game>game(new Game(&window));

	/*std::unique_ptr<sf::Font>font(new sf::Font);

	if (!font->loadFromFile("Fonts/space_invaders.ttf"))
		std::cout << "blad wczytywania czcionki" << std::endl;

	std::unique_ptr<sf::Text>nameText(new sf::Text);
	nameText->setFont(*font);
	
	Menu menu(window.getSize().x,window.getSize().y);
	*/

	//GameOver gameOver(&window);
	//std::unique_ptr<GameOver>gameOver(new GameOver(&window));
	//std::unique_ptr<MainMenu>mainMenu(new MainMenu(&window));
	//std::unique_ptr<SubmitScores>submitScores(new SubmitScores(&window));
	//std::unique_ptr<Highscores>highscores(new Highscores(&window));

	//Player player(window.getSize().x/2.f,550.f);

	//SubmitScores submitScores(&window);

	//GameOver gameOver(&window);


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if(event.type == sf::Event::TextEntered)
			{
				//ubmitScores->updateUserName(&window,&event);
			}
			//}//end switch
		}


			window.clear(sf::Color::Black);

			//menu.draw(window);

			//gameOver->Update(&window);
			//gameOver->Render(&window);
			//mainMenu->Update(&window);
			//mainMenu->Render(&window);
			//submitScores->Update(&window);
			//submitScores->Render(&window);
			//highscores->Render(&window);
			//player->Render(&window);
			//player->Update(&window);
			game->mainGame(&window);

			//window.draw(*nameText);


			window.display();
		
	}//end while
	_getch();
	return 0;
}




	
	