#pragma once
#include "Ducks.h"
#include <iostream>
#include <memory>

/** Goose that needs to be adapted to work as duck. */
class Goose {
public:
	void honk() const { std::cout << "Honk" << std::endl; }
};

/** Goose Adapter makes goose work as duck. */
class GooseAdapter : public BaseDuck {
public:
	explicit GooseAdapter(std::shared_ptr<Goose> goose) : goose(goose) { }

	void quack() override { notifyObservers(); goose->honk(); }

private:
	std::shared_ptr<Goose> goose;
};