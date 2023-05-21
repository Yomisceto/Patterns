#include "PizzaStore.h" 

void OrderPizza();

int main() {

	OrderPizza();
	return 0;
}
  
void OrderPizza()
{
	std::unique_ptr<PizzaStore> pizzaStore = std::make_unique<NYPizzaStore>();
	pizzaStore->orderPizza(PizzaStore::PizzaType::CheesePiza);
}