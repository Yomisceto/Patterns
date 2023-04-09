#ifndef _PIZZA_STORE_H
#define _PIZZA_STORE_H

#pragma once
#include "Pizza.h"

class PizzaStore {
public:
	virtual ~PizzaStore() = default;

	virtual Pizza* createPizza() const = 0;

	virtual void orderPizza() const {
		Pizza* pizza = createPizza();
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		delete pizza;
	}
};

class NYPizzaStore : public PizzaStore {
public:
	Pizza* createPizza() const override {
		return new NYStyleCheesePizza();
	}
};

class ChicagoPizzaStore : public PizzaStore {
public:
	Pizza* createPizza() const override {
		return new ChicagoStyleCheesePizza();
	}
};
#endif // !_PIZZA_STORE_H
