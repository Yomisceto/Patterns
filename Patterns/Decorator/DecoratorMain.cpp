#pragma once
#include "Beverage.h"
#include "Coffee.h"
#include "CoffeeDecorators.h"
#include <iostream>

//int main() {
//
//	using Beverage_ptr = std::shared_ptr<Beverage>;
//
//	Beverage_ptr espresso = std::make_shared<Espresso>();
//	Beverage_ptr houseBlend = std::make_shared<HouseBlend>();
//	Beverage_ptr e_milk = std::make_shared<Milk>(espresso.get());
//	Beverage_ptr e_mi_mocha = std::make_shared<Mocha>(e_milk.get());
//
//	std::cout << e_mi_mocha->getDescription() << " costs: " << e_mi_mocha->cost() << std::endl;
//
//	return 0;
//}