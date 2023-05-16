#pragma once
#include <iostream>

class GumballMachine;
                          

class SubjectMonitor {
public:
	virtual void report() const = 0;

	virtual ~SubjectMonitor() = default;
};


class GumballMonitor : SubjectMonitor {
public:
	GumballMonitor(GumballMachine* gumballMachine) : machine(gumballMachine) {}

	void report() const;

private:
	GumballMachine* machine;
};

class ProxyMonitor : SubjectMonitor {
public:
private:
	GumballMonitor* real_subject_;

	bool CheckAccess() const {
		// check real access
		std::cout << "Proxy: Checking access" << std::endl;
		return true;
	}
	void LogAccess() const {
		std::cout << "Proxy: Logging time access" << std::endl;
	}

public:
	ProxyMonitor(GumballMachine* gumballMachine) : real_subject_(new GumballMonitor(gumballMachine)) {}

	~ProxyMonitor() { delete real_subject_; }

	void report() const override;
};