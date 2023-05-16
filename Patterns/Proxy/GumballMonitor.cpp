#include "GumballMonitor.h"
#include "../State/GumballMachine.h"
#include "../State/MachineStates.h"
#include <iostream>

void GumballMonitor::report() const
{
	std::cout << "Gumball Machine: " << machine->getLocation() << std::endl;
	std::cout << "Current Inventory: " << machine->getCount() << std::endl;
	std::cout << "Current State: " << machine->getState()->getName() << std::endl;
}

void ProxyMonitor::report() const {
	if (this->CheckAccess())
	{
		this->real_subject_->report();
		this->LogAccess();
	}
}
