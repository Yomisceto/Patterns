#pragma once

#include "Duck.h"
// just to simplify I added all ducks in one file

struct MallardDuck : public Duck {
	MallardDuck() {
		setFlyBehaviour(new FlyWithWings());
		setQuackBehaviour(new Quack());
	}
	std::ostream& display(std::ostream& os) { return os << "looks like a mallard."; }
};

struct RedHeadDuck : public Duck {
	RedHeadDuck() {
		setFlyBehaviour(new FlyWithWings());
		setQuackBehaviour(new Quack());
	}

	std::ostream& display(std::ostream& os) { return os << "looks like a redhead."; }
};

struct RubberDuck : public Duck {
	RubberDuck() {
		setFlyBehaviour(new FlyNoWay());
		setQuackBehaviour(new Squeak());
	}

	std::ostream& display(std::ostream& os) { return os << "looks like a rubberduck."; }
};

struct DecoyDuck : public Duck {
	DecoyDuck() {
		setFlyBehaviour(new FlyNoWay());
		setQuackBehaviour(new MuteQuack());
	}

	std::ostream& display(std::ostream& os) { return os << "looks like a decoy duck"; }
};