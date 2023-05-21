#include "GumballMachine.h"
#include "MachineStates.h"
#include <iostream>

GumballMachine::GumballMachine(int count_, const std::string& location) : count(count_), location(location)
{
	soldState = new SoldState(this);
	winnerState = new WinnerState(this);
	soldOutState = new SoldOutState(this);
	noQuarterState = new NoQuarterState(this);
	hasQuarterState = new HasQuarterState(this);

	if (count_ > 0) { state = noQuarterState; }
}

/** Gumball operations delegate work to current state. */
void GumballMachine::insertQuarter()
{
	state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
	state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
	state->turnCrank();

	// improve: we can check state of machine so we don't call dispense when no need
	if (dynamic_cast<SoldState*>(state)) {
		state->dispense();
	}
}

void GumballMachine::releaseBall()
{
	std::cout << "A gumball comes rolling out of the slot..." << std::endl;
	if (count != 0) --count;
}

void GumballMachine::refill(int toCount)
{
	this->count = toCount;
	state = noQuarterState;
}

GumballMachine::~GumballMachine()
{
	delete soldOutState;
	delete noQuarterState;
	delete hasQuarterState;
	delete soldState;
	delete winnerState;
}

// more methods here including getters for each state...

std::ostream& operator<<(std::ostream& os, const GumballMachine& gm)
{
	os << "Gumball state: " << typeid(gm.state).name() << ", has " << gm.count << " gumball(s) left";
	return os;
}
