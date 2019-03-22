#pragma once
#include<iostream>
#include<string>

class LoadingError
{
	std::string message;
public:
	LoadingError(std::string s) :message(s) {}
	void DisplayMessage()
	{
		std::cout << message << std::endl;
	}
};