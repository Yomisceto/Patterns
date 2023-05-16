#pragma once
#include "QuackObservable.h"
class Quackable : public QuackObservable {
public:
	virtual void quack() = 0;

	virtual ~Quackable() = default;
};