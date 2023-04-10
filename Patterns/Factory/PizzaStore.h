#ifndef _PIZZA_STORE_H
#define _PIZZA_STORE_H

#pragma once
#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class PizzaStore {
public:
	enum class PizzaType {
		CheesePiza, ClamPizza
	};

	virtual ~PizzaStore() { delete ingredientFactory; };

	virtual Pizza* createPizza(PizzaType type) const = 0;

	virtual void orderPizza(PizzaType type) const {
		Pizza* pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		delete pizza;
	}

	IPizzaIngredientFactory* ingredientFactory = nullptr;
};

/** Only one pizza store for reference. */
class NYPizzaStore : public PizzaStore {
public:
	NYPizzaStore() { ingredientFactory = new NYPizzaIngredientFactory; }

	Pizza* createPizza(PizzaType type) const override 
	{
		Pizza* pizza = nullptr;

		switch (type) {
		case PizzaStore::PizzaType::CheesePiza:
			pizza = new CheesePizza(ingredientFactory);
			pizza->setName("New York Style Cheese Pizza"); 
			break;
		case PizzaStore::PizzaType::ClamPizza:
			pizza = new CheesePizza(ingredientFactory);
			pizza->setName("New York Style Clam Pizza"); 
			break;
		default:
			break;
		}
		return pizza;
	}
};

//class ChicagoPizzaStore : public PizzaStore {
//public:
//	/** Only one pizza for reference. */
//	Pizza* createPizza() const override {
//		return new ChicagoStyleCheesePizza();
//	}
//};

#endif // !_PIZZA_STORE_H
