#ifndef _PIZZA_H
#define _PIZZA_H

#pragma once
#include <string>
#include <iostream>

class Pizza {
public:
	explicit Pizza(const std::string& name) : name_(name) {}
	virtual ~Pizza() { std::cout << "Deleting " << name_ << " pizza." << std::endl; }
	
	virtual void bake() const { std::cout << "Baking for 25 minutes at 200" << std::endl; }
	virtual void cut() const { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
	virtual void box() const { std::cout << "Place pizza in official PizzaStore box" << std::endl; }
	virtual void prepare() const { std::cout << "Preparing " << name_ << std::endl; }

	std::string getName() const { return name_; }
private:
	std::string name_;
};

class NYStyleCheesePizza : public Pizza {
public:
	NYStyleCheesePizza() : Pizza("NY Style Sauce and Cheese Pizza") {}
};

class ChicagoStyleCheesePizza : public Pizza {
public:
	ChicagoStyleCheesePizza() : Pizza("Chicago Style Deep Dish Cheese Pizza") {}
	void cut() const override { std::cout << "Cutting the pizza into square slices." << std::endl; }
};

#endif //_PIZZA_H
