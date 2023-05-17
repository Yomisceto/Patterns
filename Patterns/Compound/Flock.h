#pragma once
#include "Quackable.h"
#include <vector>
#include <memory>

/** Flock allows to treat collection of ducks as a Quackable object. */
class Flock : public Quackable {
private:
	std::vector<std::shared_ptr<Quackable>> quackers;
public:

	void add(std::shared_ptr<Quackable> quacker) { quackers.push_back(quacker); }

	// Quackable, just call quack in every duck
	void quack() override;

	// QuackObservable, just calls in every duck
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};