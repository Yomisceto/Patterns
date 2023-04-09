#pragma once
#include "Beverage.h"

class Espresso : public Beverage {
public:
	Espresso() : Beverage("Espresso") {}
	double cost() const override { return 1.99; }
};

class HouseBlend : public Beverage {
public:
	HouseBlend() : Beverage("House Blend Coffee") {}
	double cost() const override { return .89; }
};