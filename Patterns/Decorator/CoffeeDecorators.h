#pragma once
#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator {
public:
	using CondimentDecorator::CondimentDecorator;

	std::string getDescription() const override { return beverage_->getDescription() + ", Mocha"; }
	double cost() const override { return .20 + beverage_->cost(); };
};

class Milk : public CondimentDecorator {
public:
	using CondimentDecorator::CondimentDecorator;
	
	std::string getDescription() const override { return beverage_->getDescription() + ", Milk"; }
	double cost() const override { return .15 + beverage_->cost() ; };
};