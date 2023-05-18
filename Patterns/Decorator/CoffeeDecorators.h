#pragma once
#include "CondimentDecorator.h"

/** Decorators wrap beverage, add own description and increase price. */
class Mocha : public CondimentDecorator {
public:
	using CondimentDecorator::CondimentDecorator;

	std::string getDescription() const override { return getBeverage()->getDescription() + ", Mocha"; }
	double cost() const override { return .20 + getBeverage()->cost(); };
};

class Milk : public CondimentDecorator {
public:
	using CondimentDecorator::CondimentDecorator;
	
	std::string getDescription() const override { return getBeverage()->getDescription() + ", Milk"; }
	double cost() const override { return .15 + getBeverage()->cost() ; };
};