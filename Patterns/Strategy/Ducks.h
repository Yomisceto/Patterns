#pragma once

#include "Duck.h"

/** Ducks classes sets manually new behaviour, so there is no need to override fly() and quack(). */
/** */
struct MallardDuck : public Duck {
	MallardDuck() {
		setFlyBehaviour(std::make_unique<FlyWithWings>());
		setQuackBehaviour(std::make_unique<Quack>());
	}
	std::ostream& display(std::ostream& os) const override { return os << "looks like a mallard."; }
};

struct RedHeadDuck : public Duck {
	RedHeadDuck() {
		setFlyBehaviour(std::make_unique<FlyWithWings>());
		setQuackBehaviour(std::make_unique<Quack>());
	}

	std::ostream& display(std::ostream& os) const override { return os << "looks like a redhead."; }
};

struct RubberDuck : public Duck {
	RubberDuck() {
		setFlyBehaviour(std::make_unique<FlyNoWay>());
		setQuackBehaviour(std::make_unique<Squeak>());
	}

	std::ostream& display(std::ostream& os) const override { return os << "looks like a rubberduck."; }
};

struct DecoyDuck : public Duck {
	DecoyDuck() {
		setFlyBehaviour(std::make_unique<FlyNoWay>());
		setQuackBehaviour(std::make_unique<MuteQuack>());
	}

	std::ostream& display(std::ostream& os) const override { return os << "looks like a decoy duck"; }
};