#pragma once
#include "QuackObservable.h"

/** By default, all Quackable objects can be observed. */
class Quackable : public QuackObservable {
public:
	virtual void quack() = 0;

	~Quackable() override = default;
};