#pragma once
#include <iostream>

class MachineState;

class GumballMachine {
public:
	friend std::ostream& operator<<(std::ostream& os, const GumballMachine& gm);

	GumballMachine(int count_, std::string location = "");
	

	// machine functions
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void releaseBall();
	void refill(int count);

	// set
	void setState(MachineState* state_) { state = state_; }

	// get
	int getCount() const { return count; }
	std::string getLocation() const { return location; }

	MachineState* getState() const { return state; }
	MachineState* getSoldState() const { return soldState; }
	MachineState* getSoldOutState() const { return soldOutState; }
	MachineState* getNoQuarterState() const { return noQuarterState; }
	MachineState* getHasQuarterState() const { return hasQuarterState; }
	MachineState* getWinnerState() const { return winnerState; }
	
	// cleans states that created with new keyword
	~GumballMachine();

private:
	MachineState* soldState;
	MachineState* soldOutState;
	MachineState* noQuarterState;
	MachineState* hasQuarterState;

	MachineState* winnerState;

	MachineState* state = soldOutState;
	int count;
	
	std::string location;
};