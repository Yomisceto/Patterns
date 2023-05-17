#pragma once
#include "QuackObservable.h"
#include <iostream>

class Quackologist : public Observer {
public:
	void update(QuackObservable* duck) override { std::cout << "Quackologist: " << duck << " just quacked." << std::endl; }
};