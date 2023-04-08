#pragma once

#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include <functional>
#include "DuckBehaviors.h"
#include "DuckBehaviorsImpl.h"

struct Duck {
private:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
public:
	void setFlyBehaviour(FlyBehavior* behavior) { flyBehavior = behavior; }
	void setQuackBehaviour(QuackBehavior* behavior) { quackBehavior = behavior; }

	virtual void fly() { flyBehavior->fly(); }
	virtual void quack() { quackBehavior->quack(); }

	virtual void swim() { std::cout << "all ducks swim." << std::endl; };
	virtual std::ostream& display(std::ostream&) = 0;
	// others duck methods
	virtual ~Duck();
};

Duck::~Duck() {
	delete flyBehavior;
	delete quackBehavior;
}

#endif // DUCK_H