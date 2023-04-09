#pragma once
#include <string>
#include "Beverage.h"

class CondimentDecorator : public Beverage {
public:
	Beverage* beverage_;
	explicit CondimentDecorator(Beverage* beverage) : beverage_(beverage) {}

	double cost() const override { return this->beverage_->cost(); }
};