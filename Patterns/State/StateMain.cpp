#include "GumballMachine.h"
#include <iostream>

void GumballMachineTest()
{
	GumballMachine gumballMachine(20);

	/*gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	std::cout << gumballMachine << std::endl << "\n";

	gumballMachine.insertQuarter();
	gumballMachine.ejectQuarter();
	gumballMachine.turnCrank();

	std::cout << gumballMachine << std::endl << "\n";

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.ejectQuarter();*/

	std::cout << gumballMachine << std::endl << "\n";
	
	for (auto i = 0; i != 10; ++i) {
		gumballMachine.insertQuarter();
		gumballMachine.turnCrank();
	}

	std::cout << gumballMachine << std::endl << "\n";
}

//int main(void)
//{
//	GumballMachineTest();
//	return 0;
//}