#pragma once
#include <iostream>
#include <string>

/** General class for beverage that handle the algorithm. */
class CaffeineBeverage {
public:
	virtual ~CaffeineBeverage() = default;

	/** This is template method */
	void prepareRecipe() 
	{
		/** Each step of algorithm is represented by a method */
		boilWater();						// handled by a class
		brew();								// handled by subclass
		pourInCup();						// handled by a class

		if (customerWantsCondiments()) {
			addCondiments();				// handled by subclass
		}
	}
	
	/** By overriding this methods, behaviour is controlled. */
	virtual void brew() = 0;
	virtual void addCondiments() = 0;

	/** Its common behaviour for all caffeine drinks. */
	void boilWater() const { std::cout << "Boiling water" << std::endl; }
	void pourInCup() const { std::cout << "Pouring into cup" << std::endl;}

	/** Override and control when user wants condiment. */
	virtual bool customerWantsCondiments() { return true; }
};


class CoffeeWithHook : public CaffeineBeverage
{
public:
	void brew() override { std::cout << "Dripping Coffee through filter" << std::endl; }
	void addCondiments() override { std::cout << "Adding Sugar and Milk" << std::endl; }

	bool customerWantsCondiments() override;

	std::string getUserInput() const;
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