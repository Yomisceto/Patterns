#ifndef _IPizzaIngredientFactory_H
#define _IPizzaIngredientFactory_H

#pragma once
#include "PizzaIngredients.h"
#include <vector>
#include <iostream>

class IPizzaIngredientFactory {
public:
	virtual ~IPizzaIngredientFactory() = default;

	virtual Dough* createDough() const = 0;
	virtual Sauce* createSauce() const = 0;
	virtual Cheese* createCheese() const = 0;
	virtual Pepperoni* createPeperoni() const = 0;
	virtual Clams* createClam() const = 0;
	virtual std::vector<Veggies*> createVeggies() const = 0;

	std::string getName() const { return name_; }
protected:
	std::string name_;
};


class NYPizzaIngredientFactory : public IPizzaIngredientFactory {
public:
	NYPizzaIngredientFactory() { name_ = "NY Pizza Factory"; }

	Dough* createDough() const override {
		std::cout << "Add Thin Crust Dough" << std::endl;
		return new ThinCrustDough;
	}
	Sauce* createSauce() const override {
		std::cout << "Add Thin Mariana Sauce" << std::endl;
		return new MarinaraSauce;
	}
	Cheese* createCheese() const override {
		std::cout << "Add Reggiano Cheese" << std::endl;
		return new ReggianoCheese;
	}
	std::vector<Veggies*> createVeggies() const override {
		std::cout << "Add Garlic and Oninon" << std::endl;
		return std::vector<Veggies*>{new Garlic, new Onion};
	}
	Pepperoni* createPeperoni() const override {
		std::cout << "Add Sliced Pepperoni" << std::endl;
		return new SlicedPepperoni;
	}
	Clams* createClam() const override {
		std::cout << "Add Fresh Clams" << std::endl;
		return new FreshClams;
	}
};


#endif // IPizzaIngredientFactory