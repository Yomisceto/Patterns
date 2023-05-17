#pragma once
#include "Quackable.h"
#include <vector>

class Flock : public Quackable {

public:
	void add(Quackable* quacker) { quackers.push_back(quacker); }
	
	// Quackable
	void quack() override;

	// QuackObservable
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;

private:
	std::vector<Quackable*> quackers;
};