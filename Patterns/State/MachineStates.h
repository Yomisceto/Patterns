#pragma once
#include <iostream>
#include "GumballMachine.h"
#include <random>

/** Abstract machine state */
class MachineState
{
public:
	friend std::ostream& operator<<(std::ostream& os, const MachineState& machine);

	explicit MachineState(GumballMachine* gumballMachine_) : gumballMachine(gumballMachine_) {}

	//virtual void insertQuarter() = 0;
	//virtual void ejectQuarter() = 0;
	//virtual void turnCrank() = 0;
	virtual void dispense() = 0;
	
	// default implementations will be error messages
	virtual void ejectQuarter()  { std::cout << "Sorry, you already turned the crank" << std::endl; }
	virtual void turnCrank()	 { std::cout << "Turning twice doesn't get you another gumball!" << std::endl; }
	virtual void insertQuarter() { std::cout << "Please wait, we're already giving you a gumball" << std::endl; }

	virtual ~MachineState() = default;

	// converts state to it's name, for reports
	virtual std::string getName() const { return "State"; }

protected:
	GumballMachine* getMachine() const { return gumballMachine; }

private:
	GumballMachine* gumballMachine;
};

/** Idle, when no quarter. */
class NoQuarterState : public MachineState
{
public:
	using MachineState::MachineState;
	
	void insertQuarter() override;

	void ejectQuarter() override { std::cout << "You haven’t inserted a quarter" << std::endl; }
	void turnCrank() override { std::cout << "You turned, but there’s no quarter" << std::endl; }
	void dispense() override { std::cout << "You need to pay first" << std::endl; }

	std::string getName() const override { return "NoQuarterState"; }
};

/** Quarter inserted. */
class HasQuarterState : public MachineState
{
public:
	explicit HasQuarterState(GumballMachine* gumballMachine_);

	void ejectQuarter() override;
	void turnCrank() override;

	void insertQuarter() override { std::cout << "You can't insert another quarter" << std::endl; }
	void dispense() override { std::cout << "No gumball dispensed" << std::endl; }

	std::string getName() const override { return "HasQuarterState"; }

private:
	// random generator
	std::default_random_engine random_engine;
	std::uniform_int_distribution<int> distribution = std::uniform_int_distribution<int>(0, 10);
};

/** Gum is dispenced. */
class SoldState : public MachineState
{
public:
	using MachineState::MachineState;

	void dispense() override;

	std::string getName() const override { return "SoldState"; }
};

/** No gums left in machine. */
class SoldOutState : public MachineState
{
public:
	using MachineState::MachineState;

	void insertQuarter() override { std::cout << "You can't insert a quarter, the machine is sold out" << std::endl; }
	void ejectQuarter() override { std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl; }
	void turnCrank() override { std::cout << "You turned, but there are no gumballs" << std::endl; }
	void dispense() override { std::cout << "No gumball dispensed" << std::endl; }

	std::string getName() const override { return "SoldOutState"; }
};

/** Chance of getting secong gum when turn trunk. */
class WinnerState : public MachineState {

public:
	using MachineState::MachineState;

	void dispense() override;

	std::string getName() const override { return "WinnerState"; }
};