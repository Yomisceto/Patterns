#pragma once

/** Duck behaviour interfaces.*/

struct FlyBehavior {
	virtual void fly() = 0;

	virtual ~FlyBehavior() = default;
};

struct QuackBehavior {
	virtual void quack() = 0;

	virtual ~QuackBehavior() = default;
};