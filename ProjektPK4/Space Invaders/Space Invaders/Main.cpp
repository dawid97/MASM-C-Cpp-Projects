#include <SFML/Graphics.hpp>
#include<iostream>
#include<conio.h>
#include"Menu.h"



//#include<vld.h>



constexpr int ScreenWidth = 800;
constexpr int ScreenHeight = 650;


int main()
{
	
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "SPACE INVADERS");
	window.setFramerateLimit(60);

	std::unique_ptr<Menu>menu(new Menu(&window));
	
	while (window.isOpen())
	{
		if (menu->update(&window) == 0)
			return 0;
	}
}