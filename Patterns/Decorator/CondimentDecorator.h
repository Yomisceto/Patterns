#pragma once
#include <string>
#include "Beverage.h"

/** Base decorator for beverage. */
class CondimentDecorator : public Beverage {
public:
	explicit CondimentDecorator(Beverage* beverage) : beverage_(beverage) {}

	double cost() const override { return this->beverage_->cost(); }

protected:
	Beverage* getBeverage() const { return beverage_; }

private:
	/** Wraps beverage. */
	Beverage* beverage_;
};