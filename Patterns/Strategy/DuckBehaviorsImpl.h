#pragma once
#include <iostream>
#include "DuckBehaviors.h"

void print(const std::string&);

/** Duck behaviour implementations .*/

struct FlyWithWings : public FlyBehavior {
	void fly() override { print("Flying with wings."); }
};

struct FlyNoWay : public FlyBehavior {
	void fly() override { print("Can't fly."); }
};

struct Quack : public QuackBehavior {
	void quack() override { print("Quack."); }
};

struct Squeak : public QuackBehavior {
	void quack() override { print("Squeak."); }
};

struct MuteQuack : public QuackBehavior {
	void quack() override { print("Can't Quack."); }
};

void print(const std::string& s) {
	std::cout << s << std::endl;
}