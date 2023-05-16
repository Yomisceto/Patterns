#pragma once
#include "Ducks.h"
#include "Quackable.h"
#include "QuackCounter.h"
#include <memory>

class AbstractDuckFactory {

public:
	virtual ~AbstractDuckFactory() = default;

	virtual Quackable* createMallardDuck() = 0;
	virtual Quackable* createRedheadDuck() = 0;
	virtual Quackable* createDuckCall() = 0;
	virtual Quackable* createRubberDuck() = 0;
};

class DuckFactory : public AbstractDuckFactory {

public:
	Quackable* createMallardDuck() override { return new MallardDuck; }
	Quackable* createRedheadDuck() override { return new RedheadDuck; }
	Quackable* createDuckCall() override { return new DuckCall; }
	Quackable* createRubberDuck() override { return new RubberDuck; }

};

class CountingDuckFactory : public AbstractDuckFactory {
public:
	Quackable* createMallardDuck() override { return new QuackCounter(new MallardDuck, true); }
	Quackable* createRedheadDuck() override { return new QuackCounter(new RedheadDuck, true); }
	Quackable* createDuckCall() override { return new QuackCounter(new DuckCall, true); }
	Quackable* createRubberDuck() override { return new QuackCounter(new RubberDuck, true); }
};