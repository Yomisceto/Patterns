#include <iostream>
#include "Ducks.h"
#include <memory>
#include <vector>

#define tab std::cout << '\t'; // just for easier printing

void simulate(const Duck* duck);

//int main(void) {
//
//	std::vector<std::unique_ptr<Duck>> ducks;
//	ducks.push_back(std::make_unique<MallardDuck>());
//	ducks.push_back(std::make_unique<RubberDuck>());
//	ducks.push_back(std::make_unique<DecoyDuck>());
//	
//	for (auto it = ducks.cbegin(); it != ducks.cend(); ++it) {
//		simulate(it->get());
//	}
//
//	return 0;
//}

void simulate(const Duck* duck) {
	duck->display(std::cout) << std::endl;
	tab duck->fly();
	tab duck->quack();
}