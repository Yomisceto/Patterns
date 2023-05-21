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

	virtual void prepare() = 0;

	/** Default pizza preparing steps, but every pizza can override it */
	virtual void bake() const { std::cout << "Baking for 25 minutes at 200" << std::endl; }
	virtual void cut() const { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
	virtual void box() const { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

	std::string getName() const { return name_; }
	void setName(const std::string& name) { name_ = name; }

	virtual ~Pizza() = default;

protected:
	IPizzaIngredientFactory* getIngredientFactory() { return ingredientFactory; }

	void setIngredientFactory(IPizzaIngredientFactory* factory) { ingredientFactory = factory; }

	/** Takes only rvalue reference to control memory */
	void setDough(Dough* && dough) { dough_.reset(std::move(dough));  }
	void setClam(Clams* && clams) { clam_.reset(std::move(clams)); }
	void setSauce(Sauce* && sauce) { sauce_.reset(std::move(sauce)); }
	void setCheese(Cheese* && cheese) { cheese_.reset(std::move(cheese)); }
	void setDough(Pepperoni* && pepperoni) { pepperoni_.reset(std::move(pepperoni)); }

private:
	std::string name_;

	std::vector<std::unique_ptr<Veggies>> veggies_;
	
	std::unique_ptr<Clams> clam_ = nullptr;
	std::unique_ptr<Dough> dough_ = nullptr;
	std::unique_ptr<Sauce> sauce_ = nullptr;
	std::unique_ptr <Cheese> cheese_ = nullptr;
	std::unique_ptr <Pepperoni> pepperoni_ = nullptr;

	/** Factory to create ingredients for pizza. */
	IPizzaIngredientFactory* ingredientFactory = nullptr;
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
		: Pizza("Clam Pizza") 
	{
		setIngredientFactory(factory);
	}

	void cut() const override { std::cout << "Cutting the pizza into square slices." << std::endl; }

	void prepare() override {
		std::cout << "Preparing " << getName() << " " << getIngredientFactory()->getName() << std::endl;

		setDough(getIngredientFactory()->createDough());
		setSauce(getIngredientFactory()->createSauce());
		setCheese(getIngredientFactory()->createCheese());
		setClam(getIngredientFactory()->createClam());
	}
};

#endif //_PIZZA_H
