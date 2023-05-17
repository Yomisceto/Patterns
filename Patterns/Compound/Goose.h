#pragma once
#include "Ducks.h"
#include <iostream>

// Added to ducks a goose with adapter pattern

class Goose {
public:
	void honk() const { std::cout << "Honk" << std::endl; }
};

class GooseAdapter : public BaseDuck {

public:
	explicit GooseAdapter(Goose* goose) : BaseDuck::BaseDuck(), goose(goose) { }

	void quack() override { notifyObservers(); goose->honk(); }

private:
	Goose* goose;
};