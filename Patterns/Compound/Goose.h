#pragma once
#include "Ducks.h"
#include <iostream>

// Added to ducks a goose with adapter pattern

class Goose {
public:
	void honk() const { std::cout << "Honk" << std::endl; }
};

class GooseAdapter : public Quackable {

public:
	GooseAdapter() : observable(new Observable(this)) {};
	~GooseAdapter() override { delete observable; }

	// Observer
	void registerObserver(Observer* observer) override { observable->registerObserver(observer); }
	void notifyObservers() override { observable->notifyObservers(); }

	explicit GooseAdapter(Goose* goose) : goose(goose) { }
	void quack() override { goose->honk(); }

private:
	Goose* goose;
	Observable* observable;
};