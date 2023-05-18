#include <iostream>
#include "TurkeyAdapter.h"

void simulate(const ADuck* duck);
void AdapterTest();


//int main(void)
//{
//	AdapterTest();
//	return 0;
//}
void AdapterTest()
{
	std::shared_ptr<ATurkey> turkey = std::make_shared<AWildTurkey>();

	std::unique_ptr<ADuck> turkeyAdapter(std::make_unique<TurkeyAdapter>(turkey));
	std::unique_ptr<ADuck> duck(std::make_unique<AMallardDuck>());

	ClassTurkeyAdapter classTurkeyAdapter;

	std::cout << "Turkey.." << std::endl;
	turkey->gobble();
	turkey->fly();

	std::cout << "Duck.." << std::endl;
	simulate(duck.get());

	std::cout << "AdapterTurkey.." << std::endl;
	simulate(turkeyAdapter.get());

	std::cout << "ClassAdapterTurkey.." << std::endl;
	simulate(&classTurkeyAdapter);
}
void simulate(const ADuck* duck)
{
	duck->quack();
	duck->fly();
}