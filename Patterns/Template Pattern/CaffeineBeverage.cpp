#include "CaffeineBeverage.h"

bool CoffeeWithHook::customerWantsCondiments()
{
	std::string answer = getUserInput();

	if (answer.size() > 0 && std::tolower(answer[0]) == 'y') return true;
	else return false;
}

std::string CoffeeWithHook::getUserInput() const
{
	std::string input = "";
	std::cout << "Would you like milk and sugar with your coffee (y/n) ? " << std::endl;

	std::getline(std::cin, input);

	return input;
}
