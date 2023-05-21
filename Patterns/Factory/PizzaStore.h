#ifndef _PIZZA_STORE_H
#define _PIZZA_STORE_H

#pragma once
#include "Pizza.h"
#include "PizzaIngredientFactory.h"

/** Pizza Factory. */
class PizzaStore {
public:
	enum class PizzaType {
		CheesePiza, ClamPizza
	};

	virtual ~PizzaStore() = default;

	/** Every derived factory implements it's way to create Pizza. */
	virtual Pizza* createPizza(PizzaType type) const = 0;

	/** Default pizza order. */
	virtual void orderPizza(PizzaType type) const {
		Pizza* pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		delete pizza;
	}

	std::unique_ptr<IPizzaIngredientFactory> ingredientFactory = nullptr;
};

/** Only one pizza store for reference. */
class NYPizzaStore : public PizzaStore {
public:
	NYPizzaStore() { ingredientFactory = std::make_unique<NYPizzaIngredientFactory>(); }

	Pizza* createPizza(PizzaType type) const override 
	{
		Pizza* pizza = nullptr;

		switch (type) {
		case PizzaStore::PizzaType::CheesePiza:
			pizza = new CheesePizza(ingredientFactory.get());;
			pizza->setName("New York Style Cheese Pizza"); 
			break;
		case PizzaStore::PizzaType::ClamPizza:
			pizza = new CheesePizza(ingredientFactory.get());
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
