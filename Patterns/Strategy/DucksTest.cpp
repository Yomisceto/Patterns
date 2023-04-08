#include <iostream>
#include "Ducks.h"
#include <memory>
#include <vector>

#define tab std::cout << '\t'; // just for easier printing

/* 
int main(void) {
	Duck** ducks = new Duck*[3];
	ducks[0] = new MallardDuck();
	ducks[1] = new RubberDuck();
	ducks[2] = new DecoyDuck();

	for (int i = 0; i < 3; ++i) {
		ducks[i]->display(std::cout) << std::endl;
		tab ducks[i]->fly();
		tab ducks[i]->quack();
		delete ducks[i];
	}
	delete[] ducks;

	return 0;
}
*/