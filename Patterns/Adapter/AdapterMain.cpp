#include <iostream>
#include "TurkeyAdapter.h"

void TestDuck(ADuck* duck)
{
	duck->quack();
	duck->fly();
}
void DuckTest() {
	AMallardDuck duck;
	AWildTurkey turkey;

	ADuck* turkeyAdapter = new TurkeyAdapter(&turkey);
	ClassTurkeyAdapter classTurkeyAdapter;

	std::cout << "Turkey.." << std::endl;
	turkey.gobble();
	turkey.fly();

	std::cout << "Duck.." << std::endl;
	TestDuck(&duck);

	std::cout << "AdapterTurkey.." << std::endl;
	TestDuck(turkeyAdapter);

	std::cout << "ClassAdapterTurkey.." << std::endl;
	TestDuck(&classTurkeyAdapter);

	delete turkeyAdapter;
}
//
//int main(void)
//{
//	DuckTest();
//	return 0;
//}