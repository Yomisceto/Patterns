#include "MachineStates.h"

std::ostream& operator<<(std::ostream& os, const MachineState& machine)
{
    os << machine.getName();
    return os;
}

// constructors
HasQuarterState::HasQuarterState(GumballMachine* gumballMachine_) : MachineState(gumballMachine_) {
	random_engine.seed(std::time(0));
}

// states methods 
void HasQuarterState::turnCrank() {
	std::cout << "You turned..." << std::endl;

	int winner = distribution(random_engine);

	// turn has 10% chance of giving second gum so we changing state
	if (winner == 0 && getMachine()->getCount() > 1) {
		getMachine()->setState(getMachine()->getWinnerState());
	}
	else {
		getMachine()->setState(getMachine()->getSoldState());
	}
}
void HasQuarterState::ejectQuarter() {
	std::cout << "Quarter returned" << std::endl;
	getMachine()->setState(getMachine()->getNoQuarterState());
}

void WinnerState::dispense()
{
	std::cout << "You're a winner! You get two gumballs for your quarter" << std::endl;
	getMachine()->releaseBall();

	if (getMachine()->getCount() == 0)
	{
		getMachine()->setState(getMachine()->getSoldOutState());
	}
	else { // if there is second ball then release 
		getMachine()->releaseBall();

		// and update state according to amount of gums left
		if (getMachine()->getCount() > 0) {
			getMachine()->setState(getMachine()->getNoQuarterState());
		}
		else {
			std::cout << "Oops, out of gumballs" << std::endl;
			getMachine()->setState(getMachine()->getSoldOutState());
		}

	}
}

void NoQuarterState::insertQuarter()
{
	std::cout << "You inserted a quarter" << std::endl;
	getMachine()->setState(getMachine()->getHasQuarterState());
}

void SoldState::dispense() {
	getMachine()->releaseBall();
	if (getMachine()->getCount() > 0)
	{
		getMachine()->setState(getMachine()->getNoQuarterState());
	}
	else {
		getMachine()->setState(getMachine()->getSoldOutState());
		std::cout << "Oops, out of gumballs" << std::endl;
	}
}
