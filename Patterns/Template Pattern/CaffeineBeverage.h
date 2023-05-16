#pragma once
#include <iostream>
#include <string>

class CaffeineBeverage
{
public:
	/** This is template method */
	void prepareRecipe() 
	{
		/** Each step of algorithm is represented by a method */
		boilWater();						// handled by a class
		brew();								// handled by subclass
		pourInCup();						// handled by a class

		if (customerWantsCondiments())
		addCondiments();					// handled by subclass
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0;

	void boilWater()
	{
		std::cout << "Boiling water" << std::endl;
	}

	void pourInCup()
	{
		std::cout << "Pouring into cup" << std::endl;
	}

	virtual bool customerWantsCondiments()
	{
		return true;
	}
};
class CoffeeWithHook : public CaffeineBeverage
{
public:
	void brew() override { std::cout << "Dripping Coffee through filter" << std::endl; }
	void addCondiments() override { std::cout << "Adding Sugar and Milk" << std::endl; }
	bool customerWantsCondiments() override
	{
		std::string answer = getUserInput();

		if (answer.size() > 0 && std::tolower(answer[0]) == 'y') return true;
		else return false;
	}

	std::string getUserInput()
	{
		std::string input = "";
		std::cout << "Would you like milk and sugar with your coffee (y/n) ? " << std::endl;

		std::getline(std::cin, input);
	
		return input;
	}
};

class Tea : public CaffeineBeverage
{
public:
	void brew() override { std::cout << "Steeping the tea" << std::endl; }
	void addCondiments() override { std::cout << "Adding Lemon" << std::endl; }
};                                    

class Coffee : public CaffeineBeverage
{
public:
	void brew() override { std::cout << "Dripping Coffee through filter" << std::endl; }
	void addCondiments() override { std::cout << "Adding Sugar and Milk" << std::endl; }
};