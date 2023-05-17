#pragma once
#include "Ducks.h"
#include "Quackable.h"
#include "QuackCounter.h"
#include <memory>

/** Abstract classs that can create ducks.
    Class returns a raw pointers to new object. */
class AbstractDuckFactory {

public:
	virtual ~AbstractDuckFactory() = default;

	virtual Quackable* createMallardDuck() = 0;
	virtual Quackable* createRedheadDuck() = 0;
	virtual Quackable* createDuckCall() = 0;
	virtual Quackable* createRubberDuck() = 0;
};

/** Factory that can create common ducks. */
class DuckFactory : public AbstractDuckFactory {

public:
	Quackable* createMallardDuck() override { return new MallardDuck; }
	Quackable* createRedheadDuck() override { return new RedheadDuck; }
	Quackable* createDuckCall()    override { return new DuckCall; }
	Quackable* createRubberDuck()  override { return new RubberDuck; }

};

/** Factory that can create counter ducks. */
class CountingDuckFactory : public AbstractDuckFactory {
public:
	Quackable* createMallardDuck() override { return new QuackCounter(std::make_shared<MallardDuck>());}
	Quackable* createRedheadDuck() override { return new QuackCounter(std::make_shared<RedheadDuck>()); }
	Quackable* createDuckCall()    override { return new QuackCounter(std::make_shared <DuckCall>()); }
	Quackable* createRubberDuck()  override { return new QuackCounter(std::make_shared <RubberDuck>()); }
};