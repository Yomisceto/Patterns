#pragma once

struct FlyBehavior {
	virtual void fly() = 0;

	~FlyBehavior() = default;
};

struct QuackBehavior {
	virtual void quack() = 0;

	~QuackBehavior() = default;
};