#pragma once

#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include <functional>
#include "DuckBehaviors.h"
#include "DuckBehaviorsImpl.h"

struct Duck {
public:
	virtual ~Duck() = default;

	void setFlyBehaviour(std::unique_ptr<FlyBehavior> behavior) { flyBehavior = std::move(behavior); }
	void setQuackBehaviour(std::unique_ptr<QuackBehavior> behavior) { quackBehavior = std::move(behavior); }

	/** Base class just call behaviour mehtods. */
	virtual void fly() const { flyBehavior->fly(); }
	virtual void quack() const { quackBehavior->quack(); }
	
	virtual void swim() const { std::cout << "all ducks swim." << std::endl; };

	virtual std::ostream& display(std::ostream&) const = 0;
private:
	// Uses composite to hold behaviour, not inheritance
	std::unique_ptr<FlyBehavior> flyBehavior;
	std::unique_ptr<QuackBehavior> quackBehavior;
};


#endif // DUCK_H