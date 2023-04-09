#include "PizzaStore.h" 


int main() {

	PizzaStore* pPizza = new NYPizzaStore;
	pPizza->orderPizza();

	std::cout << std::endl;

	pPizza = new ChicagoPizzaStore;
	pPizza->orderPizza();

	delete pPizza;
	return 0;
}
