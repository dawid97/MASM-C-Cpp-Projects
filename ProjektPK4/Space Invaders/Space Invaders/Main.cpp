#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"GameOver.h"
#include"MainMenu.h"
#include<conio.h>
#include<vld.h>

constexpr int ScreenWidth = 800;
constexpr int ScreenHeight = 600;


int main()
{
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Hello world");

	/*std::unique_ptr<sf::Font>font(new sf::Font);

	if (!font->loadFromFile("Fonts/space_invaders.ttf"))
		std::cout << "blad wczytywania czcionki" << std::endl;

	std::unique_ptr<sf::Text>nameText(new sf::Text);
	nameText->setFont(*font);
	
	Menu menu(window.getSize().x,window.getSize().y);
	*/

	//GameOver gameOver(&window);
	std::unique_ptr<GameOver>gameOver(new GameOver(&window));
	std::unique_ptr<MainMenu>mainMenu(new MainMenu(&window));

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
			

			
		
			//switch (event.type)
			//{
			//case sf::Event::Closed:
			//{
			//	window.close();
			//}
			//case sf::Event::TextEntered:
			//{
			//	if (event.text.unicode < 128) //trzeba bedzie zrobic z tego jakas funkcje
			//	{
			//		std::unique_ptr<sf::String>str(new sf::String);
			//		*str = nameText->getString();

			//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
			//		{
			//			if (str->getSize() > 0)
			//				str->erase(str->getSize() - 1, 1);
			//		}
			//		if (isprint(event.text.unicode))
			//		{
			//			*str += static_cast<char>(event.text.unicode);
			//			std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
			//		}
			//		nameText->setString(*str);
			//		nameText->setOrigin(nameText->getLocalBounds().left + nameText->getLocalBounds().width / 2.f, nameText->getLocalBounds().top + nameText->getLocalBounds().height / 2.f);
			//		nameText->setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			//	}
			//}
			//}//end switch
		}//end while

		window.clear(sf::Color::Black);

		//menu.draw(window);

		//gameOver->Update(&window);
		//gameOver->Render(&window);
		mainMenu->Update(&window);
		mainMenu->Render(&window);
		
		
		//window.draw(*nameText);
	
	
		window.display();
	}//end while
	_getch();
	return 0;
}




	
	