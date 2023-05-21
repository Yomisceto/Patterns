#pragma once
#include <string>
#include <iostream>

/** Just for example it's not interfaces */
/** A lot of ingredients for pizza */
class PizzaIngredient {
public:
	virtual ~PizzaIngredient() = default;
	virtual void prepare() { std::cout << "Preparing " << name_ << "..." << std::endl; };

	virtual std::string getManufactor() const = 0;

	void setName(const std::string& name) { name_ = name; }
private:
	std::string name_ = "Unknown Pizza Ingredient";
};

class Dough : public PizzaIngredient {

};

class ThinCrustDough : public Dough {
public:
	ThinCrustDough() { setName("Thin Crust Dough"); }

	std::string getManufactor() const override { return ""; }
};

struct Sauce : public PizzaIngredient {
	
};

struct MarinaraSauce : public Sauce {
	MarinaraSauce() { setName("Marinara Sauce"); }
	std::string getManufactor() const override { return ""; }
};

struct Cheese : public PizzaIngredient {
	
};

struct ReggianoCheese : public Cheese {
	ReggianoCheese() { setName("Reggiano Cheese"); }
	std::string getManufactor() const override { return ""; }
};


struct Veggies : public PizzaIngredient {

};

struct Garlic : public Veggies {
	Garlic() { setName("Garlic"); }
	std::string getManufactor() const override { return ""; }
};

struct Onion : public Veggies {
	Onion() { setName("Onion"); }
	std::string getManufactor() const override { return ""; }
};

struct Pepperoni : public PizzaIngredient {

};

struct SlicedPepperoni : public Pepperoni {
	SlicedPepperoni() { setName("Sliced Pepperoni"); }
	std::string getManufactor() const override { return ""; }
};

struct Clams : public PizzaIngredient {

};

struct FreshClams : public Clams {
	FreshClams() { setName("Fresh Clams"); }
	std::string getManufactor() const override { return ""; }
};