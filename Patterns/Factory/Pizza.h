#ifndef _PIZZA_H
#define _PIZZA_H

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "PizzaIngredients.h"
#include "PizzaIngredientFactory.h"

class Pizza {
public:
	explicit Pizza(const std::string& name) : name_(name) {}

	Pizza(const Pizza&) = delete;
	Pizza& operator=(const Pizza&) = delete;

	virtual void prepare() = 0;
	virtual void bake() const { std::cout << "Baking for 25 minutes at 200" << std::endl; }
	virtual void cut() const { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
	virtual void box() const { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

	std::string getName() const { return name_; }
	void setName(const std::string& name) { name_ = name; }

	virtual ~Pizza() {
		delete clam_;
		delete dough_;
		delete sauce_;
		delete cheese_;
		delete pepperoni_;

		for(Veggies* veg : veggies_) {
			delete veg;
		}

		std::cout << "Deleting " << name_ << " pizza." << std::endl; 
	}

protected:
	IPizzaIngredientFactory* getIngredientFactory() { return ingredientFactory; }
	void setIngredientFactory(IPizzaIngredientFactory* factory) {
		ingredientFactory = factory;
	}
	void setDough(Dough* dough) { dough_ = dough; }
	void setClam(Clams* clams) { clam_ = clams; }
	void setSauce(Sauce* sauce) { sauce_ = sauce; }
	void setCheese(Cheese* cheese) { cheese_ = cheese; }
	void setDough(Pepperoni* pepperoni) { pepperoni_ = pepperoni; }

private:
	std::string name_;
	Clams* clam_;
	Dough* dough_;
	Sauce* sauce_;
	Cheese* cheese_;
	Pepperoni* pepperoni_;
	std::vector<Veggies*> veggies_;
	IPizzaIngredientFactory* ingredientFactory;
};

class CheesePizza : public Pizza {
public:
	explicit CheesePizza(IPizzaIngredientFactory* factory)
		: Pizza("Cheese Pizza") 
	{
		setIngredientFactory(factory);
	}

	void prepare() override {
		std::cout << "Preparing " << getName() << " " <<  getIngredientFactory()->getName() << std::endl;

		setDough(getIngredientFactory()->createDough());
		setSauce(getIngredientFactory()->createSauce());
		setCheese(getIngredientFactory()->createCheese());
	}
};

class ClamPizza : public Pizza {
public:
	explicit ClamPizza(IPizzaIngredientFactory* factory)
		: Pizza("Clam Pizza"), ingredientFactory(factory) {}

	void cut() const override { std::cout << "Cutting the pizza into square slices." << std::endl; }

	void prepare() override {
		std::cout << "Preparing " << getName() << " " << ingredientFactory->getName() << std::endl;

		setDough(ingredientFactory->createDough());
		setSauce(ingredientFactory->createSauce());
		setCheese(ingredientFactory->createCheese());
		setClam(ingredientFactory->createClam());
	}

	IPizzaIngredientFactory* ingredientFactory;
};

#endif //_PIZZA_H
